/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     relop = 258,
     _addop = 259,
     _mulop = 260,
     _assignop = 261,
     AndandOrop = 262,
     _num = 263,
     _id = 264,
     _sentence = 265,
     _foreach = 266,
     end = 267,
     _else = 268,
     till = 269,
     out = 270,
     intt = 271,
     DEFAULT = 272,
     _if = 273,
     program = 274,
     in = 275,
     DO = 276,
     thenn = 277,
     CASE = 278,
     BREAK = 279,
     start = 280,
     real = 281,
     SWITCHH = 282,
     final = 283,
     _while = 284,
     decl = 285,
     string = 286,
     _with = 287
   };
#endif
/* Tokens.  */
#define relop 258
#define _addop 259
#define _mulop 260
#define _assignop 261
#define AndandOrop 262
#define _num 263
#define _id 264
#define _sentence 265
#define _foreach 266
#define end 267
#define _else 268
#define till 269
#define out 270
#define intt 271
#define DEFAULT 272
#define _if 273
#define program 274
#define in 275
#define DO 276
#define thenn 277
#define CASE 278
#define BREAK 279
#define start 280
#define real 281
#define SWITCHH 282
#define final 283
#define _while 284
#define decl 285
#define string 286
#define _with 287



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 7 "cpm.y"

    struct 
    {
        char* id; // Pointer to a character string representing the variable's name or identifier
        char type; // A character representing the type of the value stored in the union
        union
        {
            float Var_Float; // A float value
            char* Val_String; // A pointer to a character string representing a value
            int Val_Int; // An integer value
        } value; // Union containing the value of the variable
    } Var; // Struct containing information about the variable

enum {
  assignop,
  andop,
  subop,
  equalop,
  notequalop,
  greaterthanop,
  mulop,
  orop,
  divop,
  lessthanop,
  addop,
  greatorequalop,
  lessorequal
} op;
	char type;


/* Line 2058 of yacc.c  */
#line 153 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
