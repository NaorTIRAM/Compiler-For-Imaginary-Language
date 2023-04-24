%option noyywrap

%{
	#include <string.h>
    #include "y.tab.h"
	#define HUGE_VAL (__builtin_huge_val())

	extern int atoi(const char *); // converting strings to numeric values.
	extern double atof(const char *nptr); // converting strings to numeric values.
	void Error_Longid();
	void Error_NotReconized();
	void Error_FloatOverflow();
	
    int new_line = 1; 
%}

DIGIT [0-9]  
LETTER [a-zA-Z]

%%
[\n]	{ fprintf(yyout, "\n%d.\t", new_line++);
 /* match one or more spaces or tabs and print them */	}
[ \t]+	{ fprintf(yyout, "%s", yytext);
/* match a newline and print the line number */	}
"case" { fprintf(yyout, "%s", yytext);
/* if see case then */ return CASE; }
"start" { fprintf(yyout, "%s", yytext);
/* if see bgn then */ return start; }
"while" { fprintf(yyout, "%s", yytext);
 /* if see while then */return _while; }
"final" { fprintf(yyout, "%s", yytext);
 /* if see final then */return final; }
"default" { fprintf(yyout, "%s", yytext);
 /* if see default then */return DEFAULT; }
"else" { fprintf(yyout, "%s", yytext);
 /* if see else then */return _else; }
"string" { fprintf(yyout, "%s", yytext);
 /* if see string then */return string; }
"with" { fprintf(yyout, "%s", yytext);
 /* if see with then */return _with; }
"program" { fprintf(yyout, "%s", yytext);
 /* if see program then */return program; }
"do" { fprintf(yyout, "%s", yytext);
 /* if see do then */return DO; }
"out" { fprintf(yyout, "%s", yytext);
 /* if see out then */return out; }
"foreach" { fprintf(yyout, "%s", yytext);
 /* if see foreach then */return _foreach; }
"then" { fprintf(yyout, "%s", yytext);
 /* if see then then */return thenn; }
"int" { fprintf(yyout, "%s", yytext);
 /* if see int then */return intt; }
"in" { fprintf(yyout, "%s", yytext);
 /* if see read then */return in; }
"break" { fprintf(yyout, "%s", yytext);
 /* if see break then */return BREAK; }
"real" { fprintf(yyout, "%s", yytext);
 /* if see real then */return real; }
"decl" { fprintf(yyout, "%s", yytext);
 /* if see let then */return decl; }
"end" { fprintf(yyout, "%s", yytext);
 /* if see end then */return end; }
"switch" { fprintf(yyout, "%s", yytext);
 /* if see switch then */return SWITCHH; }
"if" { fprintf(yyout, "%s", yytext);
 /* if see if then */return _if; }
"till" { fprintf(yyout, "%s", yytext);
 /* if see till then */return till; }
"("	{ fprintf(yyout, "%s", yytext);	return '(';	}
")"	{ fprintf(yyout, "%s", yytext);	return ')';	}
"{"	{ fprintf(yyout, "%s", yytext);	return '{';	}
"}"	{ fprintf(yyout, "%s", yytext);	return '}';	}
","	{ fprintf(yyout, "%s", yytext);	return ',';	}
":"	{ fprintf(yyout, "%s", yytext);	return ':';	}
";"	{ fprintf(yyout, "%s", yytext);	return ';';	}
"!"	{ fprintf(yyout, "%s", yytext);	return '!';	}
"=="	{ fprintf(yyout, "%s", yytext);	yylval.op = equalop;		return relop;		}
"<>"	{ fprintf(yyout, "%s", yytext);	yylval.op = notequalop;		return relop;		}
"<"		{ fprintf(yyout, "%s", yytext);	yylval.op = lessthanop;		return relop;		}
">"		{ fprintf(yyout, "%s", yytext);	yylval.op = greaterthanop;		return relop;		}
">="	{ fprintf(yyout, "%s", yytext);	yylval.op = greatorequalop;		return relop;		}
"<="	{ fprintf(yyout, "%s", yytext);	yylval.op = lessorequal;		return relop;		}
"+"		{ fprintf(yyout, "%s", yytext);	yylval.op = addop;		return _addop;		}
"-"		{ fprintf(yyout, "%s", yytext);	yylval.op = subop;		return _addop;		}
"*"		{ fprintf(yyout, "%s", yytext);	yylval.op = mulop;		return _mulop;		}
"/"		{ fprintf(yyout, "%s", yytext);	yylval.op = divop;		return _mulop;		}
"="		{ fprintf(yyout, "%s", yytext);	yylval.op = assignop;	return _assignop;	}
"||"	{ fprintf(yyout, "%s", yytext);	yylval.op = orop;		return AndandOrop;	}
"&&"	{ fprintf(yyout, "%s", yytext);	yylval.op = andop;		return AndandOrop;	}


{LETTER}({LETTER}|{DIGIT})*	{ 
/* identify must start with letter then zero or more 
occurrences of either a letter or a digit.
this code segment is responsible for identifying and handling identifiers in the input text.*/
	if (yyleng <= 9) {
    fprintf(yyout, "%s", yytext);
    yylval.Var.id = strdup(yytext);
    return _id;
  } else {
    Error_Longid();
  }

}

{DIGIT}+			{
	/*identifying integers in the input text. */
	int val = atoi(yytext);
  if (val == 0 && yytext[0] != '0') {
    /* Handle the case where the token starts with a non-digit character */
    Error_NotReconized();
  } else {
    fprintf(yyout, "%s", yytext);
    yylval.Var.type = 'i';
    yylval.Var.value.Val_Int = val;
    return _num;
  }
}

{DIGIT}+"."{DIGIT}+		{
	double floatVal = strtod(yytext, NULL);
	
	if (floatVal == HUGE_VAL || floatVal == -HUGE_VAL) {
		Error_FloatOverflow();
	}
	fprintf(yyout, "%s", yytext);
	yylval.Var.type = 'f'; //float
	yylval.Var.value.Var_Float = floatVal;
	return _num;
}

\"({LETTER}|"."|","|"!"|"?"|" "|{DIGIT})*\"	{
	/*matches a string literal in double quotes, including any characters between the quotes.*/
	fprintf(yyout, "%s", yytext);
	yylval.Var.type = 's'; //indicates a string type
	yylval.Var.value.Val_String = strdup(yytext); //copies the string value
	return _sentence;
}

"/*".*"*/"	{/* C-style comment*/}

.		{
	/*This code block is a catch-all rule that is executed if none of the previous 
	regular expressions match the current input*/
	Error_NotReconized();
}
%%