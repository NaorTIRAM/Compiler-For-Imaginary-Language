#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#include "y.tab.h"
#define INPUT_FILE_EXTENSION1 ".cpl"
#define INPUT_FILE_EXTENSION2 ".CPL"
#define OUTPUT_FILE_EXTENSION ".lst"
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 65536



//struct for the Table list //
typedef struct node
{
	struct node* next;

	union
	{
		int Val_Int;
		float Var_Float;
		char* Val_String;
	} value;

	char type;
	char* id;
	int isImmutable;
	int hasBeenAssigned;
} Node_Symbol_In_Table;

typedef struct
{
	Node_Symbol_In_Table* head;
	Node_Symbol_In_Table* tail;
} Table_List;

Table_List* symbolS;

//Extern guncation/variables
extern FILE* yyin, *yyout;
extern int new_line;
extern int yylex(void);
extern void yyerror(const char* eMs);

//variable for next use
char	decl_type;
int Count_Errors = 0, Count_Strings = 0, Count_Jumps = 0, Count_Data = 0, Reg_Num = 0, 
Flag_andOror = 0, Flag_Not = 0, operationInPrograss = 0, Number_Index = 0, Count_Break = 0;
FILE* File_Error, *File_Mips, *Data_Mips, *Write_To_File_Mips;

//symbol table
Node_Symbol_In_Table* find_Node_using_Id(char* id);
void push_Int_To_List(char* id, int Val_Int, int isImmutable, int hasBeenAssigned);
void push_Float_To_List(char* id, float Var_Float, int isImmutable, int hasBeenAssigned);
void push_String_To_List(char* id, char* Val_String, int isImmutable, int hasBeenAssigned);
void remove_Symbol_From_Table(char* id);
void Free_Symole_Table();
void assign_Integer_To_Variable(char* id, int Val_Int);
void assign_Float_To_Variable(char* id, float Var_Float);
void assign_String_Value(char* id, char* Val_String);
int IsId(char* id);

//file handling
void Combining_Both_Files_In_Mips(const char* mipsFile, const char* mipsFirstFile, const char* mipsSecondFile);
void Remove_Files_Mips(const char* mipsFile, const char* mipsFirstFile, const char* mipsSecondFile);
void Combining_Both_Files_Errors(const char* lstFile, const char* Listing_File_Output);
void Remove_Files_Errors(const char* lstFile);

//mips functions
void push_Int_To_Mips(char* id, int Val_Int);
void push_Float_To_Mips(char* id, float Var_Float);
void push_String_To_Mips(char* id, char* Val_String);
void assign_To_String_In_Mips(char* id, char* Val_String);
void emit_Read_Code_For_Mips(char* id, char type);
void emit_Out_put_Code_For_Mips(char* id, char type, int Val_Int, float Var_Float);

// If and Else functions.
void generate_Comparison_Mips(char* op, char* id1, char* id2, int FirstIneVal, int SecondIntVal, float FirstFloatVal, float SecondFloatVal, char FirstType, char SecondType);
void generate_Comparison_Validation_Code_For_Mips();
void generate_Else_Code_For_Mips();
void generate_End_If_Code_For_Mips();
void generate_And_or_Or_For_Mips(char* op);


// While functions.
void generate_Start_While_Code_For_Mips();
void generate_While_Validation_Code_For_Mips();
void generate_End_While_Code_For_Mips();

//errors
void Error_Redeclaration(char* id);
void Error_undeclared_Var(char* id);
void Error_Wrong_Type_For_Assignment(char* id, char type);
void Error_Constent_Var(char* id);
void Error_With_String_op();
void Error_Longid();
void Error_NotReconized();
void Error_FloatOverflow();
void Error_TooManyArguments(char* id, int expectedArgs);
void Error_MismatchedTypes(char* id);
void Error_OutOfBounds(char* id, int index);



// Do While functions.
void generate_Do_While_Start_For_Mips();
void generate_Do_Validation_Mips_Statement();
void generate_End_Of_Do_Statement_In_For_Mips();

// For Each functions.
void generate_Start_For_each_Code_For_Mips();
void generate_Foreach_Validation_Code_Mips();
void generate_Mips_Code_For_End_Of_Foreach_Loop_Mips();

// Switch Case functions.
void generate_Mips_Code_For_Switch_Case(char* id, int Val_Int, float Var_Float, char type);
void generate_Mips_Assembly_For_Switch_Case(int Val_Int, float Var_Float, char type);
void generate_Switch_Break_For_Mips();
void generate_Switch_Choice_For_Mips();
void generate_Switch_End_Label_For_Mips();
void generate_Arithmetic_Op_For_Mips(char* op, char* id1, char* id2, int FirstIneVal, int SecondIntVal,float FirstFloatVal, float SecondFloatVal, char FirstType, char SecondType);
void generate_Mips_Arith_Expr(char* op, char* id, int Val_Int, float Var_Float, char type);
void generate_Assignment_Code_For_Mips(char* idToAssign, char typeToAssign, char* id, int Val_Int, float Var_Float, char type);
void generate_End_For_Mips(char* idToAssign, char typeToAssign);
void Mips_Exit();



int main(int argc, char** argv)
{
	const char* source_File, * Listing_File_Output;
	
	//Checking if the  file name is correct and if there is 2 arg
	if (argc != 2 || (strstr(argv[1], ".cpl") == NULL && strstr(argv[1], ".CPL") == NULL))
    {
    fprintf(stderr, "Wrong file name!\n");
	fprintf(stderr, "Ofek and Naor!\n");
    return 1;
    }
	
	//Keeping the name of the file
	source_File  = argv[1];
	// Check if file exists before attempting to open it
	if(access(source_File, F_OK) == -1)
	{
		fprintf(stderr, "Error: %s does not exist!\n", source_File);
		fprintf(stderr, "Ofek and Naor!\n");
		return 2;
	}

	/*  printing /*  printing  */ /*  printing  */ /*  printing  */ 
	fprintf(stderr, "%s is opened for reading\n", source_File );
	
	//Using yyin instead of FILE *... becuase lex 
	yyin = fopen(source_File , "r");
	if (yyin == NULL)
	{
		fprintf(stderr, "Error: Can not open %s for reading!\n", source_File );
		fprintf(stderr, "Ofek and Naor!\n");
		return 3;
	}
	//Creating file for the errors
	Listing_File_Output = "listing.lst";
	
	/*  printing /*  printing  */ /*  printing  */ /*  printing  */  
	fprintf(stderr, "%s is in writing now\n", Listing_File_Output);
	
	yyout = fopen(Listing_File_Output, "w");
	//Cheacking if the file can be opened
	if (yyout == NULL)
	{
		fprintf(stderr, "Error: Can not open %s for writing!\n", Listing_File_Output);
		fprintf(stderr, "Ofek and Naor!\n");
		return 4;
	}
	fprintf(yyout, "Ofek and Naor Compiler!\n");

	
	//Creating another file, so we can combined both lising and errors if there is as  requested in 3.3
	const char* lstFile = "error.lst";
	File_Error = fopen(lstFile, "w");
	if(File_Error==NULL)
	{
		fprintf(stderr, "Error:Cannot open  %s !\n", File_Error);
		fprintf(stderr, "Ofek and Naor!\n");
		return 5;
	}
	
	//creating the mips file itself then we will create 2 more files for data and text
	const char* mipsFile = "mips.s";
	File_Mips = fopen(mipsFile, "w");
	if(File_Mips==NULL)
	{
		fprintf(stderr, "Error:Cannot open  %s !\n", File_Error);
		fprintf(stderr, "Ofek and Naor!\n");
		return 6;
	}
	fprintf(File_Mips, "Ofek and Naor Compiler!\n");
	// data in mips file
	const char* mipsFirstFile = "mipsData.s";
	Data_Mips = fopen(mipsFirstFile, "w");
	if(Data_Mips==NULL)
	{
		fprintf(stderr, "Error:Cannot open  %s !\n", File_Error);
		fprintf(stderr, "Ofek and Naor!\n");
		return 7;
	}
			
	//the text in the mips file
	const char* mipsSecondFile = "mipsText.s";
	Write_To_File_Mips = fopen(mipsSecondFile, "w");
	if(Write_To_File_Mips==NULL)
	{
		fprintf(stderr, "Error:Cannot open  %s !\n", File_Error);
		fprintf(stderr, "Ofek and Naor!\n");
		return 7;
	}
	
	

    /*  printing  /*  printing  */ /*  printing  */ /*  printing  */ 
	fprintf(stderr, "%s is in writing now\n", mipsFile);

	//allocation memory for the size of the table list
	symbolS = (Table_List*)malloc(sizeof(Table_List));
	symbolS->tail = NULL;
	symbolS->head = NULL;

   
	fprintf(yyout, "%d.\t", new_line++);
	yyparse();

	
	if (Count_Errors != 0)
	{
		Remove_Files_Mips(mipsFile, mipsFirstFile, mipsSecondFile);
		Combining_Both_Files_Errors(lstFile, Listing_File_Output);
	}
	else
	{
		Combining_Both_Files_In_Mips(mipsFile, mipsFirstFile, mipsSecondFile);
		Remove_Files_Errors(lstFile);
	}
	/*  printing /*  printing  */ /*  printing  */ /*  printing  */ 
	fprintf(stderr, "Closing files: %s, %s \n", source_File , Listing_File_Output);
	
	

	fclose(yyin);
	fclose(yyout);
	fclose(File_Error);
	fclose(File_Mips);
	fclose(Data_Mips);
	fclose(Write_To_File_Mips);
	Free_Symole_Table();
    return 8;
}

/*
This is a C function named Combining_Both_Files_In_Mips that merges two MIPS assembly files, mipsFirstFile and mipsSecondFile, into a single file with the name mipsFile. The function takes three arguments, all of which are pointers to character arrays representing the file names.


*/
void Combining_Both_Files_In_Mips(const char* mipsFile, const char* mipsFirstFile, const char* mipsSecondFile)
{
	fclose(Data_Mips);
	fclose(Write_To_File_Mips);
	Data_Mips = fopen(mipsFirstFile, "r");
	Write_To_File_Mips = fopen(mipsSecondFile, "r");	
	fprintf(File_Mips, ".data\n");

	char buffer[BUFFER_SIZE];

// Copy contents of Data_Mips to File_Mips
    while (fgets(buffer, BUFFER_SIZE, Data_Mips) != NULL) 
	{
    fputs(buffer, File_Mips);
    }
	// Write "\n.text\n" to File_Mips
    fputs("\n.text\n", File_Mips);

    // Copy contents of Write_To_File_Mips to File_Mips
     rewind(Write_To_File_Mips);
     while (fgets(buffer, BUFFER_SIZE, Write_To_File_Mips) != NULL) 
	 {
    fputs(buffer, File_Mips);
    }

	fclose(Data_Mips);
	fclose(Write_To_File_Mips);
	fclose(File_Mips);

	remove(mipsFirstFile);
	remove(mipsSecondFile);

	//fprintf(stderr, "Files are combined!\n");
}
/*
 Remove_Files_Mips is called when a certain number of errors have been encountered during the processing of the MIPS code. It simply deletes the three files specified by the input parameters (mipsFile, mipsFirstFile, and mipsSecondFile).
*/
void Remove_Files_Mips(const char* mipsFile, const char* mipsFirstFile, const char* mipsSecondFile)
{
	//fprintf(stderr, "%d Errors was found\n", Count_Errors);

	fclose(Data_Mips);
	fclose(Write_To_File_Mips);
	fclose(File_Mips);

	remove(mipsFirstFile);
	remove(mipsSecondFile);
	remove(mipsFile);

	//fprintf(stderr, "%s deleted!\n", mipsFile);
}


/*This function takes in two parameters: the name of an error file to be read and the name of a listing file to be written. It assumes that the error file contains a list of errors that were encountered during some previous operation.
*/

void Combining_Both_Files_Errors(const char* lstFile, const char* Listing_File_Output)
{
	fclose(File_Error);
	File_Error = fopen(lstFile, "r");

	fprintf(yyout, "\n%d Errors was found: \n", Count_Errors);
	char buffer[BUFFER_SIZE];
     // Copy contents of File_Error to yyout
     while (fgets(buffer, BUFFER_SIZE, File_Error) != NULL) 
	 {
    fputs(buffer, yyout);
    }
	fclose(File_Error);
	remove(lstFile);
}

/*
This function takes in one parameter: the name of an error file to be deleted. It assumes that the file was created earlier in the program and is no longer needed.
*/

void Remove_Files_Errors(const char* lstFile)
{
	fclose(File_Error);
	remove(lstFile);
}

/*
The purpose of this function is to print an error message to the standard error stream (stderr) and to a separate error file (File_Error), and to increment a count of the number of errors encountered.
*/
void yyerror(const char* eMs)
{
	fprintf(stderr, "%s\n", eMs);
	fprintf(File_Error, "Line %d.\tError: syntax error!\n", new_line - 1);
	Count_Errors++;
}



/*
This function adds a new integer variable to a linked list representing a symbol table for the program. 
*/
void push_Int_To_List(char* id, int Val_Int, int isImmutable, int hasBeenAssigned)
{
	
	Node_Symbol_In_Table* newNode = (Node_Symbol_In_Table*)malloc(sizeof(Node_Symbol_In_Table));
    if (newNode == NULL) 
    {
    return;
     }
	 * newNode = (Node_Symbol_In_Table) {
    .next = NULL,
    .type = 's',
    .value.Val_Int = Val_Int,
    .id = id,
    .isImmutable = isImmutable,
    .hasBeenAssigned = hasBeenAssigned
     };
	

	symbolS->head == NULL ? symbolS->head = newNode, symbolS->tail = newNode : (symbolS->tail->next = newNode, symbolS->tail = newNode);

}

/*
This function adds a new floating-point variable to the linked list representing the symbol table for the program(just like the last function)
*/

void push_Float_To_List(char* id, float Var_Float, int isImmutable, int hasBeenAssigned)
{
	Node_Symbol_In_Table* newNode = (Node_Symbol_In_Table*)malloc(sizeof(Node_Symbol_In_Table));
	if (newNode == NULL) 
    {
    return;
     }
	 * newNode = (Node_Symbol_In_Table) {
    .next = NULL,
    .type = 's',
    .value.Var_Float = Var_Float,
    .id = id,
    .isImmutable = isImmutable,
    .hasBeenAssigned = hasBeenAssigned
     };


	symbolS->head == NULL ? symbolS->head = newNode, symbolS->tail = newNode : (symbolS->tail->next = newNode, symbolS->tail = newNode);

}


/*
This function is used to add a new symbol with its corresponding value to the symbol table. 
*/
void push_String_To_List(char* id, char* Val_String, int isImmutable, int hasBeenAssigned)
{
    Node_Symbol_In_Table* newNode = malloc(sizeof(Node_Symbol_In_Table));
     if (newNode == NULL) 
    {
    return;
     }

// Initialize the fields of the new node
     *newNode = (Node_Symbol_In_Table) {
    .next = NULL,
    .type = 's',
    .value.Val_String = Val_String,
    .id = id,
    .isImmutable = isImmutable,
    .hasBeenAssigned = hasBeenAssigned
     };

	symbolS->head == NULL ? symbolS->head = newNode, symbolS->tail = newNode : (symbolS->tail->next = newNode, symbolS->tail = newNode);

}

/*
This function removes a symbol with the given ID from a linked list that represents a symbol table.
*/

void remove_Symbol_From_Table(char* id)
{
	Node_Symbol_In_Table* current_node = symbolS->head;
    Node_Symbol_In_Table* prev_node = NULL;

    while (current_node != NULL) 
	{
    if (strcmp(current_node->id, id) == 0) {
        if (prev_node == NULL) {
            symbolS->head = current_node->next;
        } else {
            prev_node->next = current_node->next;
        }
        free(current_node);
        return;
     }
    prev_node = current_node;
    current_node = current_node->next;
}

}


/*
This function frees the memory allocated for the symbol table by deleting each node in the linked list.
*/

void Free_Symole_Table()
{
	Node_Symbol_In_Table* delNode = symbolS->head;

      while (delNode != NULL)
    {
    symbolS->head = delNode->next;
    free(delNode);
    delNode = symbolS->head;
    }
free(symbolS);
}

/*
This function searches for a node in the symbol table by its identifier (id). It returns a pointer to the node if found, or NULL if the node is not in the table.
*/


Node_Symbol_In_Table* find_Node_using_Id (char* id)
{
	Node_Symbol_In_Table* iteratorNode = symbolS->head;
	while (iteratorNode != NULL)
	{
		if (strcmp(iteratorNode->id, id) == 0)
		{
			return iteratorNode;
		}
		iteratorNode = iteratorNode->next;
	}
	return NULL;

}


/*
the purpose of IsId is to check whether a given id is present in the symbol table.
*/

int IsId(char* id)
{
	if (find_Node_using_Id (id) != NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
This function assigns an integer value to a variable in the symbol table identified by its name id. If the variable is a constant, it calls the Error_Constent_Var function to report an error.
*/

void assign_Integer_To_Variable(char* id, int Val_Int) 
{
	Node_Symbol_In_Table* nodeToAssign = find_Node_using_Id(id);

   nodeToAssign->isImmutable ? Error_Constent_Var(id) : (nodeToAssign->value.Val_Int = Val_Int, nodeToAssign->hasBeenAssigned = TRUE);

}

/*
This function assigns an float value to a variable in the symbol table identified by its name id. If the variable is a constant, it calls the Error_Constent_Var function to report an error.
*/

void assign_Float_To_Variable(char* id, float Var_Float)
{
	Node_Symbol_In_Table* nodeToAssign = find_Node_using_Id(id);

    nodeToAssign->isImmutable ? Error_Constent_Var(id) : (nodeToAssign->value.Var_Float = Var_Float, nodeToAssign->hasBeenAssigned = TRUE);
;
}

/*
This function assigns an string value to a variable in the symbol table identified by its name id. If the variable is a constant, it calls the Error_Constent_Var function to report an error.
*/

void assign_String_Value(char* id, char* Val_String)
{
	Node_Symbol_In_Table* nodeToAssign = find_Node_using_Id(id);

    nodeToAssign->isImmutable ? Error_Constent_Var(id) : (nodeToAssign->value.Val_String = Val_String, nodeToAssign->hasBeenAssigned = TRUE);
}


/*
This function takes in an identifier id and an integer value Val_Int, and writes a line of MIPS assembly code to the Data_Mips file. The code stores the integer value in memory with the label id.
*/
void push_Int_To_Mips(char* id, int Val_Int)
{
	fprintf(Data_Mips, "\t%s:\t.word %d\n", id, Val_Int);
}

/*
This function takes in an identifier id and an float value Val_Float, and writes a line of MIPS assembly code to the Data_Mips file. The code stores the float value in memory with the label id.
*/

void push_Float_To_Mips(char* id, float Var_Float)
{
	fprintf(Data_Mips, "\t%s:\t.float %f\n", id, Var_Float);
}

/*
This function takes in an identifier id and an String value Val_String, and writes a line of MIPS assembly code to the Data_Mips file. The code stores the String value in memory with the label id.
*/

void push_String_To_Mips(char* id, char* Val_String)
{
	fprintf(Data_Mips, "\t%s:\t.space 1000\n", id);

	if (Val_String != NULL)
	{
		assign_To_String_In_Mips(id, Val_String);
	}
}

/*
 copies the string literal character by character to the memory location reserved for the string variable.
*/

void assign_To_String_In_Mips(char* id, char* Val_String)
{
	fprintf(Data_Mips, "\t%s_string:\t.asciiz %s\n", id, Val_String);

	// Load address of first character in string
	fprintf(Write_To_File_Mips, "\tla\t$t0, %s_string\n", id);
	// Load the address string variable
	fprintf(Write_To_File_Mips, "\tla\t$t1, %s\n\n", id);

	// Start loop
	fprintf(Write_To_File_Mips, "\tloop_%s:\n", id);

	// Load the first byte of $t0(id_string) into $t2
	fprintf(Write_To_File_Mips, "\t\tlbu\t$t2, 0($t0)\n");
	// Save the value in $t2 at the same byte in $t1(id)
	fprintf(Write_To_File_Mips, "\t\tsb\t$t2, 0($t1)\n");

	// Increment both pointers by 1 byte
	fprintf(Write_To_File_Mips, "\t\taddi\t$t0, $t0, 1\n");
	fprintf(Write_To_File_Mips, "\t\taddi\t$t1, $t1, 1\n");

	
	fprintf(Write_To_File_Mips, "\t\tbne\t$t2, $zero, loop_%s\n\n", id);
}


/*
This function emits the MIPS assembly code for reading user input for a given variable id and type.
*/

void emit_Read_Code_For_Mips(char* id, char type)
{
	if (type == 'i') 
	{
	fprintf(Write_To_File_Mips, "\tli\t$v0, 5\n");
	fprintf(Write_To_File_Mips, "\tsyscall\n");
	fprintf(Write_To_File_Mips, "\tsw\t$v0, %s\n\n", id);
    } else if (type == 'f') 
	{
	fprintf(Write_To_File_Mips, "\tli\t$v0, 6\n");
	fprintf(Write_To_File_Mips, "\tsyscall\n");
	fprintf(Write_To_File_Mips, "\tswc1\t$f0, %s\n\n", id);
     } else if (type == 's') 
	 {
	fprintf(Write_To_File_Mips, "\tli\t$v0, 8\n");
	fprintf(Write_To_File_Mips, "\tla\t$a0, %s\n", id);
	fprintf(Write_To_File_Mips, "\tli\t$a1, 50\n");
	fprintf(Write_To_File_Mips, "\tsyscall\n\n");
}
}

/*
This code defines a function called emit_Out_put_Code_For_Mips that generates MIPS assembly code to print output to the console.
*/


void emit_Out_put_Code_For_Mips(char* id, char type, int Val_Int, float Var_Float)
{
    if (type == 'i')
    {
        fprintf(Write_To_File_Mips, "\tli\t$v0, 1\n");

        if (id != NULL)
        {
            fprintf(Write_To_File_Mips, "\tlw\t$a0, %s\n", id);
        }
        else
        {
            fprintf(Write_To_File_Mips, "\tli\t$a0, %d\n", Val_Int); 
        }

        fprintf(Write_To_File_Mips, "\tsyscall\n\n");
    }
    else if (type == 'f')
    {
        fprintf(Write_To_File_Mips, "\tli\t$v0, 2\n");

        if (id != NULL)
        {
            fprintf(Write_To_File_Mips, "\tl.s\t$f12, %s\n", id);
        }
        else
        {
            fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
            fprintf(Write_To_File_Mips, "\tl.s\t$f12, floatConst_%d\n", Count_Data++);
        }
            
        fprintf(Write_To_File_Mips, "\tsyscall\n\n");
    }
    else if (type == 's')
    {
        fprintf(Write_To_File_Mips, "\tli\t$v0, 4\n");
        fprintf(Write_To_File_Mips, "\tla\t$a0, %s\n", id);
        fprintf(Write_To_File_Mips, "\tsyscall\n\n");
    }
    else if (type == 'e')
    {
        fprintf(Data_Mips, "\tstring_%d:\t.asciiz %s\n", Count_Strings++, id);
        fprintf(Write_To_File_Mips, "\tli\t$v0, 4\n");
        fprintf(Write_To_File_Mips, "\tla\t$a0, string_%d\n", Count_Strings);
        fprintf(Write_To_File_Mips, "\tsyscall\n\n");
    }
}



/*
 generates MIPS assembly code for a comparison operation. The function takes in parameters such as the comparison operator, two identifiers or integer/float values to compare, and their types, and generates the appropriate MIPS code for the comparison.
*/

void generate_Comparison_Mips(char* op, char* id1, char* id2, int FirstIneVal, int SecondIntVal, float FirstFloatVal, float SecondFloatVal, char FirstType, char SecondType)
{
	if (id1 != NULL && id2 != NULL)
	{
		if (FirstType == 'i' && SecondType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tlw\t$t1, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tlw\t$t2, %s\n", id2);
			fprintf(Write_To_File_Mips, "\ts%s\t$s%d, $t1, $t2\n\n", op, Reg_Num);

			if (Flag_Not)
			{
				fprintf(Write_To_File_Mips, "\txor\t$s%d, 1\n", Reg_Num);
				Flag_Not = FALSE;
			}
			Reg_Num = !Reg_Num;
			return;
		}
		else if (FirstType == 'f' && SecondType == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id2);
		}
		else if (FirstType == 'i' && SecondType == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f0, $f0\n");

			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id2);
		}
		else 
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, %s\n", id1);

			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id2);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
	}
	else if (id1 == NULL && id2 == NULL)
	{
		if (FirstType == 'i' && SecondType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tli\t$t1, %d\n", FirstIneVal);
			fprintf(Write_To_File_Mips, "\tli\t$t2, %d\n", SecondIntVal);

			fprintf(Write_To_File_Mips, "\ts%s\t$s%d, $t1, $t2\n\n", op, Reg_Num);

			if (Flag_Not)
			{
				fprintf(Write_To_File_Mips, "\txor\t$s%d, 1\n", Reg_Num);
				Flag_Not = FALSE;
			}

			Reg_Num = !Reg_Num;

			return;
		}
		else if (FirstType == 'f' && SecondType == 'f')
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, floatConst_%d\n", Count_Data++);
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
		}
		else if (FirstType == 'i' && SecondType == 'f')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, FirstIneVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f0, $f0\n");
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, floatConst_%d\n", Count_Data++);
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, SecondIntVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
	}
	else if (id1 != NULL && id2 == NULL)
	{
		fprintf(Write_To_File_Mips, "\tl.s\t$f0, %s\n", id1);

		if (FirstType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f0, $f0\n");
		}

		if (SecondType == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, SecondIntVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
		}
	}
	else 
	{
		if (FirstType == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, FirstIneVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f0, $f0\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f0, floatConst_%d\n", Count_Data++);
		}
		   fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id2);

		if (SecondType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
	}

	if (strcmp("ne", op) == 0)
	{
		fprintf(Write_To_File_Mips, "\tc.eq.s\t$f0, $f1\n");
		fprintf(Write_To_File_Mips, "\tbc1f\tstart_%d\n\n", Count_Jumps);
	}
	else if (strcmp("gt", op) == 0)
	{
		fprintf(Write_To_File_Mips, "\tc.le.s\t$f0, $f1\n");
		fprintf(Write_To_File_Mips, "\tbc1f\tstart_%d\n\n", Count_Jumps);
	}
	else if (strcmp("ge", op) == 0)
	{
		fprintf(Write_To_File_Mips, "\tc.lt.s\t$f0, $f1\n");
		fprintf(Write_To_File_Mips, "\tbc1f\tstart_%d\n\n", Count_Jumps);
	}
	else
	{
		fprintf(Write_To_File_Mips, "\tc.%s.s\t$f0, $f1\n", op);
		fprintf(Write_To_File_Mips, "\tbc1t\tstart_%d\n\n", Count_Jumps);
	}

	fprintf(Write_To_File_Mips, "\tli\t$s%d, 0\n", Reg_Num);
	fprintf(Write_To_File_Mips, "\tj\tbeqz_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tstart_%d:\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tli\t$s%d, 1\n\n", Reg_Num);
	fprintf(Write_To_File_Mips, "\tbeqz_%d:\n", Count_Jumps++);

	if (Flag_Not)
	{
		fprintf(Write_To_File_Mips, "\txor\t$s%d, 1\n", Reg_Num);
		Flag_Not = FALSE;
	}
	Reg_Num = !Reg_Num;
}

/*
generates code for the MIPS architecture
*/

void generate_Comparison_Validation_Code_For_Mips()
{
	Reg_Num = !Reg_Num;
	fprintf(Write_To_File_Mips, "\tbeqz\t$s%d, else_%d\n\n", Flag_andOror, Count_Jumps);
	Flag_andOror = 0;
}


/*
this function generates the MIPS assembly code for the "else" block of an "if-else" statement in a high-level language program.
*/
void generate_Else_Code_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tj\tend_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\telse_%d:\n", Count_Jumps);
}


/*
The function simply prints the end label to the output file using the fprintf function.
*/
void generate_End_If_Code_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tend_%d:\n", Count_Jumps++);
}


/*
This function generates code for logical AND and OR operations in MIPS assembly language.
*/
void generate_And_or_Or_For_Mips(char* op)
{
	fprintf(Write_To_File_Mips, "\t%s\t$s2, $s0, $s1\n", op);
	fprintf(Write_To_File_Mips, "\tmove\t$s1, $s2\n\n");
	Flag_andOror = 2;
}

/*
This function generates the MIPS code for the start of a while loop. The generated code consists of a label that marks the start of the loop.
*/

void generate_Start_While_Code_For_Mips()
{
	fprintf(Write_To_File_Mips, "\twhile_%d:\n", Count_Jumps);
}

/*
This function generates the MIPS assembly code for validating a while loop condition. 
*/

void generate_While_Validation_Code_For_Mips()
{
	Reg_Num = !Reg_Num;
	fprintf(Write_To_File_Mips, "\tbeqz\t$s%d, end_while_%d\n\n", Flag_andOror, Count_Jumps);
	Flag_andOror = 0;
}






/*
 generates code for branching back to the start of a while loop (j while_X) and setting up a label for the end of the loop (end_while_X).
*/
void generate_End_While_Code_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tj\twhile_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tend_while_%d:\n", Count_Jumps++);
}


/*
This function generates the starting label for a do-while loop in MIPS assembly code. 
*/
void generate_Do_While_Start_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tdo_while_%d:\n", Count_Jumps);
}

/*
this function generates the validation code for a do-while loop in MIPS assembly. 
*/

void generate_Do_Validation_Mips_Statement()
{
	Reg_Num = !Reg_Num;
	fprintf(Write_To_File_Mips, "\tbeqz\t$s%d, end_do_%d\n\n", Flag_andOror, Count_Jumps);
	Flag_andOror = 0;
}

/*
This function is used to jump to the start of the "do-while" loop and the label for the end of the loop.
*/

void generate_End_Of_Do_Statement_In_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tj\tdo_while_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tend_do_%d:\n", Count_Jumps++);
}

/*
generates the MIPS assembly code for the start of a foreach loop.
*/

void generate_Start_For_each_Code_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tforeach_%d:\n", Count_Jumps);
}

/*
This function generates the MIPS assembly code for validating the condition in a foreach loop.
*/

void generate_Foreach_Validation_Code_Mips()
{
	Reg_Num = !Reg_Num;
	fprintf(Write_To_File_Mips, "\tbeqz\t$s%d, end_foreach_%d\n\n", Flag_andOror, Count_Jumps);
	Flag_andOror = 0;
}

/*
This function generates MIPS code for the end of a foreach loop in the program.
*/

void generate_Mips_Code_For_End_Of_Foreach_Loop_Mips()
{
	fprintf(Write_To_File_Mips, "\tj\tforeach_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tend_foreach_%d:\n", Count_Jumps++);
}


/*
This function generates MIPS assembly code for a switch case statement. 
*/

void generate_Mips_Code_For_Switch_Case(char* id, int Val_Int, float Var_Float, char type)
{
	if (id != NULL)
	{
		fprintf(Write_To_File_Mips, "\tl.s\t$f24, %s\n", id);
		
		if (type == 'i')
		{
			fprintf(Write_To_File_Mips, "\tcvt.w.s\t$f24, $f24\n");
		}
	}
	else 
	{
		if (type == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, Val_Int);
			fprintf(Write_To_File_Mips, "\tl.s\t$f24, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f24, $f24\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
			fprintf(Write_To_File_Mips, "\tl.s\t$f24, floatConst_%d\n", Count_Data++);
		}
	}
}

/*
This function generates MIPS assembly code for a case in a switch statement.
*/

void generate_Mips_Assembly_For_Switch_Case(int Val_Int, float Var_Float, char type)
{
	fprintf(Write_To_File_Mips, "\tcase_%d:\n", Number_Index++);

	if (type == 'i')
	{
		fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, Val_Int);
		fprintf(Write_To_File_Mips, "\tl.s\t$f25, wordConst_%d\n", Count_Data++);
		fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f25, $f25\n");
	}
	else 
	{
		fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
		fprintf(Write_To_File_Mips, "\tl.s\t$f25, floatConst_%d\n", Count_Data++);
	}

	fprintf(Write_To_File_Mips, "\tc.eq.s\t$f24, $f25\n");
	fprintf(Write_To_File_Mips, "\tbc1t\tstart_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tli\t$s7, 0\n");
	fprintf(Write_To_File_Mips, "\tj\tbeqz_%d\n\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tstart_%d:\n", Count_Jumps);
	fprintf(Write_To_File_Mips, "\tli\t$s7, 1\n\n");
	fprintf(Write_To_File_Mips, "\tbeqz_%d:\n", Count_Jumps++);
	fprintf(Write_To_File_Mips, "\tbeqz\t$s7, case_%d\n\n", Number_Index);
}

/*
This function generates MIPS assembly code for the "break" statement within a "switch" statement.
*/

void generate_Switch_Break_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tj\tbreak_switch_%d\n\n", Count_Break);
}

/*
This function generates MIPS assembly code for a case statement within a switch block. 
*/

void generate_Switch_Choice_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tcase_%d:\n", Number_Index++);
}

/*
This function generates a label in the MIPS assembly code that marks the end of a switch statement. 
*/

void generate_Switch_End_Label_For_Mips()
{
	fprintf(Write_To_File_Mips, "\tbreak_switch_%d:\n", Count_Break++);
}

/*
This code appears to be generating MIPS assembly code for performing arithmetic operations (such as addition, subtraction, multiplication, and division) on variables and constants.
*/

void generate_Arithmetic_Op_For_Mips(char* op, char* id1, char* id2, int FirstIneVal, int SecondIntVal, float FirstFloatVal, float SecondFloatVal, char FirstType, char SecondType)
{
	if (id1 != NULL && id2 != NULL)
	{
		if (FirstType == 'i' && SecondType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id2);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
		else if (FirstType == 'f' && SecondType == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id2);
		}
		else if (FirstType == 'i' && SecondType == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id2);
		}
		else 
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id1);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id2);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else if (id1 == NULL && id2 == NULL)
	{
		if (FirstType == 'i' && SecondType == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, FirstIneVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, SecondIntVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
		else if (FirstType == 'f' && SecondType == 'f')
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, floatConst_%d\n", Count_Data++);
		}
		else if (FirstType == 'i' && SecondType == 'f')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, FirstIneVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, floatConst_%d\n", Count_Data++);
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, SecondIntVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else if (id1 != NULL && id2 == NULL)
	{
		fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id1);

		if (FirstType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}

		if (SecondType == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, SecondIntVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, SecondFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, floatConst_%d\n", Count_Data++);
		}
	}
	else if (id1 == NULL && id2 != NULL)
	{
		if (FirstType == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, FirstIneVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, FirstFloatVal);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
		}

		fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id2);

		if (SecondType == 'i')
		{
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
	}

	fprintf(Write_To_File_Mips, "\t%s.s\t$f2, $f1, $f2\n\n", op);
	operationInPrograss = TRUE;
}

/*
This is a function that generates MIPS assembly code for arithmetic expressions, given the operator, identifier, integer value, float value, and type of the operand.
*/

void generate_Mips_Arith_Expr(char* op, char* id, int Val_Int, float Var_Float, char type)
{
	if (id != NULL)
	{
		if (type == 'i')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
		else 
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, %s\n", id);
		}
	}
	else 
	{
		if (type == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, Val_Int);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f1, $f1\n");
		}
		else 
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
			fprintf(Write_To_File_Mips, "\tl.s\t$f1, floatConst_%d\n", Count_Data++);
		}
	}

	fprintf(Write_To_File_Mips, "\t%s.s\t$f2, $f1, $f2\n\n", op);
}

/*
the function takes in an identifier to assign to (idToAssign), the type of the value to assign (typeToAssign), an identifier to load the value from (id), an integer value (Val_Int), a floating-point value (Var_Float), and the type of the value to load (type).
*/

void generate_Assignment_Code_For_Mips(char* idToAssign, char typeToAssign, char* id, int Val_Int, float Var_Float, char type)
{
	if (id != NULL)
	{
		if (typeToAssign == 'i' && type == 'i')
		{
			fprintf(Write_To_File_Mips, "\tlw\t$f2, %s\n", id);
		}
		else if (typeToAssign == 'f' && type == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id);
		}
		else if (typeToAssign == 'i' && type == 'f')
		{
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, %s\n", id);
			fprintf(Write_To_File_Mips, "\tcvt.w.s\t$f2, $f2\n");
		}
		else 
		{
			fprintf(Write_To_File_Mips, "\tlw\t$f2, %s\n", id);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else 
	{
		if (typeToAssign == 'i' && type == 'i')
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, Val_Int);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, wordConst_%d\n", Count_Data++);
		}
		else if (typeToAssign == 'f' && type == 'f')
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, floatConst_%d\n", Count_Data++);
		}
		else if (typeToAssign == 'i' && type == 'f')
		{
			fprintf(Data_Mips, "\tfloatConst_%d:\t.float %f\n", Count_Data, Var_Float);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, floatConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.w.s\t$f2, $f2\n");
		}
		else 
		{
			fprintf(Data_Mips, "\twordConst_%d:\t.word %d\n", Count_Data, Val_Int);
			fprintf(Write_To_File_Mips, "\tl.s\t$f2, wordConst_%d\n", Count_Data++);
			fprintf(Write_To_File_Mips, "\tcvt.s.w\t$f2, $f2\n");
		}
	}

	generate_End_For_Mips(idToAssign, typeToAssign);
}


/*
The function takes in an identifier idToAssign and its type typeToAssign and generates the MIPS assembly code for the end of an assignment statement.
*/

void generate_End_For_Mips(char* idToAssign, char typeToAssign)
{

	if (typeToAssign == 'i' && operationInPrograss)
	{
		fprintf(Write_To_File_Mips, "\tcvt.w.s\t$f2, $f2\n");
	}

	fprintf(Write_To_File_Mips, "\ts.s\t$f2, %s\n\n", idToAssign);

	operationInPrograss = FALSE;
}



/*
The  function is adding a system call instruction to the MIPS code that will exit the program.
*/
void Mips_Exit()
{
	fprintf(Write_To_File_Mips, "\tli\t$v0, 10\n");// load the exit code value into $v0 register
	fprintf(Write_To_File_Mips, "\tsyscall\n\n");// execute the syscall to exit the program
	

}

/*
This function takes in an identifier id and prints an error message to the File_Error file indicating that there was a redeclaration of the identifier. 
*/

void Error_Redeclaration(char* id)
{
	fprintf(File_Error, "Error in line %d.\t: redeclaration of %s!\n", new_line - 1, id);
	Count_Errors++;
}

/*
generates an error message when a variable is used without being declared first. 
*/

void Error_undeclared_Var(char* id)
{
	fprintf(File_Error, "Error in line %d.\t: '%s' undeclared!\n", new_line - 1, id);
	Count_Errors++;
}

/*
This function generates an error message when an assignment to an expression with the wrong type is attempted.
*/

void Error_Wrong_Type_For_Assignment(char* id, char type)
{
	fprintf(File_Error, "Error in line %d.\t: assigment to expression with %s type, '%s'!\n", new_line - 1,
		(type == 's' ? "string" : (type == 'i' ? "int" : "float")), id);
	Count_Errors++;
}

/*
This function is used to report an error when trying to assign a value to a constant variable.
*/

void Error_Constent_Var(char* id)
{
	fprintf(File_Error, "Error in line %d.\t: assigment of read-only variable, '%s'!\n", new_line - 1, id);
	Count_Errors++;
}

/*
 The function is called when an error is encountered during the analysis or code generation phase, specifically when an operation involving a string type is encountered. 
*/

void Error_With_String_op()
{
	fprintf(File_Error, "Error in line %d.\t: op of string type!\n", new_line - 1);
	Count_Errors++;
}

/*
This function is used to report an error when an identifier in the code exceeds the maximum length of 9 characters.
*/

void Error_Longid()
{
	fprintf(File_Error, "Error in line %d.\t: maximum length of ID is 9!\n", new_line - 1);
	Count_Errors++;
}

/*
This error function is used to report an error when there are characters in the code that are not recognized by the compiler.
*/

void Error_NotReconized()
{
	fprintf(File_Error, "Error in line %d.\t: unrecognizable characters!\n", new_line - 1);
	Count_Errors++;
}

/*
This error message indicates that there is an attempt to store a value outside the range that can be represented by a float data type. 
*/

void Error_FloatOverflow()
{
	fprintf(File_Error, "Error in line %d.\t: float overflow!\n", new_line - 1);
	Count_Errors++;
}
void Error_TooManyArguments(char* id, int expectedArgs)
{
	fprintf(File_Error, "Error in line %d.\t: Too many arguments!\n", new_line - 1);
	Count_Errors++;
}
void Error_MismatchedTypes(char* id)
{
	fprintf(File_Error, "Error in line %d.\t: Miss match types!\n", new_line - 1);
	Count_Errors++;
}
void Error_OutOfBounds(char* id, int index)
{
	fprintf(File_Error, "Error in line %d.\t: Out of Bound!\n", new_line - 1);
	Count_Errors++;
}

