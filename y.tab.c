/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cpm.y"

    #include <stdio.h>
	#include "cpm.c"

/* Line 371 of yacc.c  */
#line 73 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 212 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 240 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    13,    17,    18,    21,    23,    24,
      29,    33,    36,    38,    40,    42,    50,    58,    59,    62,
      63,    65,    70,    72,    74,    76,    78,    84,    90,    96,
     101,   102,   103,   114,   115,   116,   124,   125,   136,   137,
     148,   149,   157,   159,   163,   171,   173,   175,   176,   177,
     187,   188,   193,   199,   205,   209,   213,   215,   216,   222,
     226,   230,   232,   236,   238,   242,   244
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    19,     9,    25,    44,    51,    12,    -1,
       1,    33,    -1,    30,    45,    50,    -1,    -1,    45,    46,
      -1,    46,    -1,    -1,    49,    47,    34,    48,    -1,     9,
      35,    48,    -1,     9,    36,    -1,    16,    -1,    26,    -1,
      31,    -1,    28,    49,     9,     6,     8,    36,    50,    -1,
      28,    49,     9,     6,    10,    36,    50,    -1,    -1,    51,
      52,    -1,    -1,    55,    -1,     9,     6,    10,    36,    -1,
      56,    -1,    54,    -1,    53,    -1,    64,    -1,    15,    37,
      75,    38,    36,    -1,    15,    37,    10,    38,    36,    -1,
      20,    37,     9,    38,    36,    -1,     9,     6,    75,    36,
      -1,    -1,    -1,    18,    37,    72,    38,    22,    57,    52,
      13,    58,    52,    -1,    -1,    -1,    29,    59,    37,    72,
      38,    60,    64,    -1,    -1,    11,     9,     6,     8,    14,
       8,    61,    32,    71,    52,    -1,    -1,    11,     9,     6,
       8,    14,     9,    62,    32,    71,    52,    -1,    -1,    21,
      63,    64,    14,    37,    72,    38,    -1,    65,    -1,    39,
      51,    40,    -1,    27,    37,    66,    38,    39,    67,    40,
      -1,     9,    -1,     8,    -1,    -1,    -1,    23,     8,    34,
      68,    51,    24,    36,    69,    67,    -1,    -1,    17,    34,
      70,    51,    -1,     9,     6,     9,     4,     8,    -1,     9,
       6,     9,     5,     8,    -1,    72,     7,    73,    -1,    73,
       7,    73,    -1,    73,    -1,    -1,    41,    74,    37,    73,
      38,    -1,    75,     3,    75,    -1,    75,     4,    76,    -1,
      76,    -1,    76,     5,    77,    -1,    77,    -1,    37,    75,
      38,    -1,     9,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   106,   122,   124,   136,   138,   155,   154,
     170,   192,   221,   225,   229,   239,   280,   293,   296,   297,
     314,   316,   339,   341,   343,   345,   363,   407,   426,   473,
     540,   544,   539,   552,   556,   551,   564,   563,   576,   575,
     589,   588,   597,   603,   609,   624,   629,   651,   655,   650,
     661,   660,   677,   691,   714,   727,   739,   753,   752,   761,
     814,   879,   894,   961,   979,   984,  1016
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "relop", "_addop", "_mulop", "_assignop",
  "AndandOrop", "_num", "_id", "_sentence", "_foreach", "end", "_else",
  "till", "out", "intt", "DEFAULT", "_if", "program", "in", "DO", "thenn",
  "CASE", "BREAK", "start", "real", "SWITCHH", "final", "_while", "decl",
  "string", "_with", "'\\n'", "':'", "','", "';'", "'('", "')'", "'{'",
  "'}'", "\"<\"", "$accept", "PROGRAM", "DECLARATIONS", "DECLARLIST",
  "DECL", "$@1", "LIST", "TYPE", "CDECL", "STMTLIST", "STMT", "OUT_STMT",
  "IN_STMT", "ASSIGNMENT_STMT", "CONTROL_STMT", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "STMT_BLOCK", "SWITCH", "IDD", "CASES", "$@9",
  "$@10", "$@11", "STEP", "BOOLEXPR", "BOOLFACTOR", "$@12", "EXPRESSION",
  "TERM", "FACTOR", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    10,    58,    44,    59,    40,    41,   123,
     125,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    47,    46,
      48,    48,    49,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    55,
      57,    58,    56,    59,    60,    56,    61,    56,    62,    56,
      63,    56,    56,    64,    65,    66,    66,    68,    69,    67,
      70,    67,    71,    71,    72,    72,    72,    74,    73,    73,
      75,    75,    76,    76,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     3,     0,     2,     1,     0,     4,
       3,     2,     1,     1,     1,     7,     7,     0,     2,     0,
       1,     4,     1,     1,     1,     1,     5,     5,     5,     4,
       0,     0,    10,     0,     0,     7,     0,    10,     0,    10,
       0,     7,     1,     3,     7,     1,     1,     0,     0,     9,
       0,     4,     5,     5,     3,     3,     1,     0,     5,     3,
       3,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     5,     0,    19,
      12,    13,    14,    17,     7,     8,     0,     0,     6,     4,
       0,     0,     0,     2,     0,     0,     0,    40,     0,    33,
      19,    18,    24,    23,    20,    22,    25,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    66,    65,     0,     0,     0,    61,    63,     0,
       0,     0,    57,     0,    56,     0,     0,     0,    46,    45,
       0,     0,    43,     0,     0,    11,    21,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    64,    60,    62,     0,
      27,    26,     0,    54,    30,    55,    59,    28,     0,     0,
      34,    17,    17,    36,    38,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,     0,    58,     0,    41,    50,
       0,    44,    35,     0,     0,    31,    19,    47,     0,     0,
       0,     0,    51,    19,     0,    37,    39,    32,     0,     0,
       0,     0,     0,    48,    52,    53,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,    13,    14,    20,    51,    15,    19,    16,
      31,    32,    33,    34,    35,   116,   141,    47,   121,   124,
     125,    45,    36,    37,    70,   120,   143,   156,   136,   139,
      63,    64,    84,    65,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int16 yypact[] =
{
       7,   -21,     6,    32,   -69,    19,   -69,    18,   103,   -69,
     -69,   -69,   -69,    -7,   -69,   -69,    49,   103,   -69,   -69,
      29,    53,    65,   -69,    42,    48,    50,   -69,    62,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    95,    98,
      20,   102,    44,     5,   111,    72,    14,    85,    16,   118,
     -25,   -69,   -69,   -69,    89,    57,     2,   121,   -69,   119,
      90,     1,   -69,     9,   123,    68,    93,   122,   -69,   -69,
      97,     5,   -69,    25,    98,   -69,   -69,     3,    57,   -69,
      57,   124,    96,   101,   104,     5,   117,     5,    57,   106,
     107,   108,    11,   109,   110,   -69,   -69,   121,   -69,    75,
     -69,   -69,     5,   -69,   -69,   -69,   136,   -69,     5,    45,
     -69,   115,   115,   -69,   -69,   112,    94,    13,   114,   141,
     113,    72,   -69,   -69,   120,   125,   -69,   138,   -69,   -69,
     126,   -69,   -69,   145,   145,   -69,   -69,   -69,   149,    94,
      94,    94,    94,   -69,   147,   -69,   -69,   -69,    71,    92,
     127,   150,   151,   -69,   -69,   -69,    45,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,   148,   -69,    88,   152,   -10,   -30,
     -23,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -44,   -69,   -69,     8,   -69,   -69,   -69,    31,
     -68,   -12,   -69,   -38,    99,    86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,    67,    56,    92,    61,    78,    78,    78,     1,    10,
      74,    75,     4,    52,    53,     5,    85,    77,    85,    11,
      85,    17,    68,    69,    12,    21,     2,    22,    52,    53,
      54,    24,     6,    93,    25,    94,    26,    27,    79,    83,
     117,    96,    55,    28,     7,    29,    62,    86,     8,   110,
     106,   128,    52,    53,    60,    30,    72,    55,    21,    40,
      22,    23,   118,    39,    24,    52,    53,    25,   119,    26,
      27,    88,    78,   103,    41,   105,    28,   132,    29,    42,
      21,    55,    22,   113,   114,    43,    24,    44,    30,    25,
     115,    26,    27,   127,    55,   150,   151,   152,    28,    46,
      29,   122,   123,    21,    49,    22,   142,    50,    59,    24,
      30,    30,    25,   148,    26,    27,   145,   146,   147,    10,
      66,    28,    71,    29,    73,    76,    80,    81,    82,    11,
      87,    89,   100,    30,    12,    91,    90,   101,    99,   104,
      78,   102,   107,    17,   108,   111,   112,   109,   129,   130,
     126,   135,   133,   131,   138,   144,   149,   134,   154,   155,
     137,    18,    95,   153,   157,   140,    98,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,    97
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      30,    45,    40,    71,    42,     4,     4,     4,     1,    16,
      35,    36,    33,     8,     9,     9,     7,    55,     7,    26,
       7,    28,     8,     9,    31,     9,    19,    11,     8,     9,
      10,    15,     0,     8,    18,    10,    20,    21,    36,    38,
     108,    38,    37,    27,    25,    29,    41,    38,    30,    38,
      88,    38,     8,     9,    10,    39,    40,    37,     9,     6,
      11,    12,    17,    34,    15,     8,     9,    18,    23,    20,
      21,     3,     4,    85,     9,    87,    27,   121,    29,    37,
       9,    37,    11,     8,     9,    37,    15,    37,    39,    18,
     102,    20,    21,   116,    37,    24,     4,     5,    27,    37,
      29,   111,   112,     9,     9,    11,   136,     9,     6,    15,
      39,    39,    18,   143,    20,    21,   139,   140,   141,    16,
       9,    27,    37,    29,     6,    36,     5,     8,    38,    26,
       7,    38,    36,    39,    31,    38,    14,    36,    14,    22,
       4,    37,    36,    28,    37,    36,    36,    39,    34,     8,
      38,    13,    32,    40,     9,     6,     9,    32,     8,     8,
      34,    13,    74,    36,   156,   134,    80,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    19,    43,    33,     9,     0,    25,    30,    44,
      16,    26,    31,    45,    46,    49,    51,    28,    46,    50,
      47,     9,    11,    12,    15,    18,    20,    21,    27,    29,
      39,    52,    53,    54,    55,    56,    64,    65,    49,    34,
       6,     9,    37,    37,    37,    63,    37,    59,    51,     9,
       9,    48,     8,     9,    10,    37,    75,    76,    77,     6,
      10,    75,    41,    72,    73,    75,     9,    64,     8,     9,
      66,    37,    40,     6,    35,    36,    36,    75,     4,    36,
       5,     8,    38,    38,    74,     7,    38,     7,     3,    38,
      14,    38,    72,     8,    10,    48,    38,    76,    77,    14,
      36,    36,    37,    73,    22,    73,    75,    36,    37,    39,
      38,    36,    36,     8,     9,    73,    57,    72,    17,    23,
      67,    60,    50,    50,    61,    62,    38,    52,    38,    34,
       8,    40,    64,    32,    32,    13,    70,    34,     9,    71,
      71,    58,    51,    68,     6,    52,    52,    52,    51,     9,
      24,     4,     5,    36,     8,     8,    69,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 105 "cpm.y"
    {Mips_Exit();}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 107 "cpm.y"
    {
				yyerrok;  
				yyclearin;
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 155 "cpm.y"
    { decl_type = (yyvsp[(1) - (1)].type);  }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 171 "cpm.y"
    {	
				if (!IsId((yyvsp[(1) - (3)].Var).id))  
				{
                  if (decl_type == 'i')
				 {
                    push_Int_To_List((yyvsp[(1) - (3)].Var).id, 0, FALSE, FALSE);
                    push_Int_To_Mips((yyvsp[(1) - (3)].Var).id, 0);
                  } else
				   if (decl_type == 'f')
	              {
                    push_Float_To_List((yyvsp[(1) - (3)].Var).id, 0.0, FALSE, FALSE);
                    push_Float_To_Mips((yyvsp[(1) - (3)].Var).id, 0.0);
                   } else 
				   if (decl_type == 's') 
	               {
                    push_String_To_List((yyvsp[(1) - (3)].Var).id, NULL, FALSE, FALSE);
                    push_String_To_Mips((yyvsp[(1) - (3)].Var).id, NULL);
                   }
                } else Error_Redeclaration((yyvsp[(1) - (3)].Var).id);
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 193 "cpm.y"
    {	
				if (!IsId((yyvsp[(1) - (2)].Var).id)) 
				{
                  if (decl_type == 'i')
				 {
                    push_Int_To_List((yyvsp[(1) - (2)].Var).id, 0, FALSE, FALSE);
                    push_Int_To_Mips((yyvsp[(1) - (2)].Var).id, 0);
                  } else
				   if (decl_type == 'f')
	              {
                    push_Float_To_List((yyvsp[(1) - (2)].Var).id, 0.0, FALSE, FALSE);
                    push_Float_To_Mips((yyvsp[(1) - (2)].Var).id, 0.0);
                   } else 
				   if (decl_type == 's') 
	               {
                    push_String_To_List((yyvsp[(1) - (2)].Var).id, NULL, FALSE, FALSE);
                    push_String_To_Mips((yyvsp[(1) - (2)].Var).id, NULL);
                   }
                } else Error_Redeclaration((yyvsp[(1) - (2)].Var).id);
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 222 "cpm.y"
    {
				(yyval.type) = 'i';
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 226 "cpm.y"
    {
				(yyval.type) = 'f';
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 230 "cpm.y"
    {
				(yyval.type) = 's';
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 240 "cpm.y"
    {
               if (!IsId((yyvsp[(3) - (7)].Var).id)) // $3 holds the identifier for the variable
                {
                      if ((yyvsp[(2) - (7)].type) == 'i') // $2 holds the type of the variable being declared
                 {
                        if ((yyvsp[(5) - (7)].Var).type == 'i') // $5 holds the value being assigned to the variable
                       {
                         push_Int_To_Mips((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Val_Int);
                         push_Int_To_List((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Val_Int, TRUE, TRUE);
                       }
                       else // ($5.type == 'f')
                       {
                         int Val_Int = (int)(yyvsp[(5) - (7)].Var).value.Var_Float;
                         push_Int_To_Mips((yyvsp[(3) - (7)].Var).id, Val_Int);
                         push_Int_To_List((yyvsp[(3) - (7)].Var).id, Val_Int, TRUE, TRUE);
                       }
                  }
                             else // $2 == 'f'
                          {
                                      if ((yyvsp[(5) - (7)].Var).type == 'i') // $5 holds the value being assigned to the variable
                                    {
                                      float Var_Float = (float)(yyvsp[(5) - (7)].Var).value.Val_Int;
                                      push_Float_To_Mips((yyvsp[(3) - (7)].Var).id, Var_Float);
                                      push_Float_To_List((yyvsp[(3) - (7)].Var).id, Var_Float, TRUE, TRUE);
                                    }
                                    else // ($5.type == 'f') // $5 holds the value being assigned to the variable
                                    {
                                       push_Float_To_Mips((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Var_Float);
                                       push_Float_To_List((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Var_Float, TRUE, TRUE);
                                    }
                          }
                }
                                   else
                           {
                          Error_Redeclaration((yyvsp[(3) - (7)].Var).id);
                       }
        }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 281 "cpm.y"
    {
                     if (!IsId((yyvsp[(3) - (7)].Var).id))
                     {
                       push_String_To_List((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Val_String, TRUE, TRUE);
                       push_String_To_Mips((yyvsp[(3) - (7)].Var).id, (yyvsp[(5) - (7)].Var).value.Val_String);
                     }
                       else
                      {
                        Error_Redeclaration((yyvsp[(3) - (7)].Var).id);
                      }
         }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 317 "cpm.y"
    {
				Node_Symbol_In_Table* node = find_Node_using_Id ((yyvsp[(1) - (4)].Var).id);

				if (node == NULL)
				{
					Error_undeclared_Var((yyvsp[(1) - (4)].Var).id);
				}
				else if (node->type != 's')
				{
					Error_Wrong_Type_For_Assignment(node->id, node->type);
				}
				else if (node->isImmutable)
				{
					Error_Constent_Var((yyvsp[(1) - (4)].Var).id);
				}
				else
				{
					assign_String_Value((yyvsp[(1) - (4)].Var).id, (yyvsp[(3) - (4)].Var).value.Val_String);
					assign_To_String_In_Mips((yyvsp[(1) - (4)].Var).id, (yyvsp[(3) - (4)].Var).value.Val_String);
				}
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 364 "cpm.y"
    {
	
		Node_Symbol_In_Table* node = find_Node_using_Id ((yyvsp[(3) - (5)].Var).id);

		if ((yyvsp[(3) - (5)].Var).id != NULL && !node->hasBeenAssigned)
		{
			Error_undeclared_Var((yyvsp[(3) - (5)].Var).id);
		}
		else
		{
			if ((yyvsp[(3) - (5)].Var).id == NULL)
			{
				if ((yyvsp[(3) - (5)].Var).type == 'i')
				{	
					emit_Out_put_Code_For_Mips(NULL, 'i', (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float);
				}
				else if ((yyvsp[(3) - (5)].Var).type == 'f')
				{
					emit_Out_put_Code_For_Mips(NULL, 'f', (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float);
				}
				else if ((yyvsp[(3) - (5)].Var).type == 's')
				{
					emit_Out_put_Code_For_Mips(NULL, 's', (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float);
				}
			}
			else
			{
				if (node->type == 'i')
				{
					emit_Out_put_Code_For_Mips(node->id, 'i', 0, 0.0);
				}
				else if (node->type == 'f')
				{
					emit_Out_put_Code_For_Mips(node->id, 'f', 0, 0.0);
				}
				else if (node->type == 's')
				{
					emit_Out_put_Code_For_Mips(node->id, 's', 0, 0.0);
				}
			}
		}
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 408 "cpm.y"
    {
		emit_Out_put_Code_For_Mips((yyvsp[(3) - (5)].Var).value.Val_String, 'e', 0, 0.0);
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 427 "cpm.y"
    {
				Node_Symbol_In_Table* node = find_Node_using_Id ((yyvsp[(3) - (5)].Var).id);
				if (node != NULL)
                  {
                     if (node->type == 'i')
                       {
                        emit_Read_Code_For_Mips(node->id, 'i');
                         node->hasBeenAssigned = TRUE;
                       }
                         else if (node->type == 'f')
                        {
                         emit_Read_Code_For_Mips(node->id, 'f');
                         node->hasBeenAssigned = TRUE;
                        }
                             else if (node->type == 's')
                        {
                         emit_Read_Code_For_Mips(node->id, 's');
                         node->hasBeenAssigned = TRUE;
                        }
                               }
                              else
                                   {
                                     Error_undeclared_Var((yyvsp[(3) - (5)].Var).id);
                                   }

			  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 474 "cpm.y"
    {
        Node_Symbol_In_Table* node = find_Node_using_Id((yyvsp[(1) - (4)].Var).id);

        if (node == NULL) {
            Error_undeclared_Var((yyvsp[(1) - (4)].Var).id);
        }
        else if (node->type == 's') {
            Error_Wrong_Type_For_Assignment(node->id, node->type);
        }
        else if (node->isImmutable) {
            Error_Constent_Var(node->id);
        }
        else {
            Node_Symbol_In_Table* Node_IN_Symbol = find_Node_using_Id((yyvsp[(3) - (4)].Var).id);
            if ((yyvsp[(3) - (4)].Var).id != NULL && Node_IN_Symbol == NULL) {
                Error_undeclared_Var((yyvsp[(3) - (4)].Var).id);
            }
            else if ((yyvsp[(3) - (4)].Var).id != NULL && Node_IN_Symbol->type == 's') {
                Error_Wrong_Type_For_Assignment(Node_IN_Symbol->id, Node_IN_Symbol->type);
            }
            else {
                if (operationInPrograss) {
                    generate_End_For_Mips(node->id, node->type);
                }
                else {
                    generate_Assignment_Code_For_Mips(node->id, node->type, (yyvsp[(3) - (4)].Var).id, (yyvsp[(3) - (4)].Var).value.Val_Int, (yyvsp[(3) - (4)].Var).value.Var_Float, (yyvsp[(3) - (4)].Var).type);
                }

                if (node->type == 'i') {
                    assign_Integer_To_Variable((yyvsp[(1) - (4)].Var).id, (yyvsp[(3) - (4)].Var).value.Val_Int);
                }
                else {
                    assign_Float_To_Variable((yyvsp[(1) - (4)].Var).id, (yyvsp[(3) - (4)].Var).value.Var_Float);
                }
            }
        }
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 540 "cpm.y"
    {
				generate_Comparison_Validation_Code_For_Mips();
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 544 "cpm.y"
    {
				generate_Else_Code_For_Mips();
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 548 "cpm.y"
    {
				generate_End_If_Code_For_Mips();
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 552 "cpm.y"
    {
				generate_Start_While_Code_For_Mips();
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 556 "cpm.y"
    {
				generate_While_Validation_Code_For_Mips();
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 560 "cpm.y"
    {
				generate_End_While_Code_For_Mips();
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 564 "cpm.y"
    {
				push_Int_To_List((yyvsp[(2) - (6)].Var).id, (yyvsp[(4) - (6)].Var).value.Val_Int, FALSE, TRUE);
				push_Int_To_Mips((yyvsp[(2) - (6)].Var).id, (yyvsp[(4) - (6)].Var).value.Val_Int);
				generate_Start_For_each_Code_For_Mips();
				generate_Comparison_Mips("ne", (yyvsp[(2) - (6)].Var).id, NULL, (yyvsp[(2) - (6)].Var).value.Val_Int, (yyvsp[(6) - (6)].Var).value.Val_Int, (yyvsp[(2) - (6)].Var).value.Var_Float, (yyvsp[(6) - (6)].Var).value.Var_Float, 'i', (yyvsp[(6) - (6)].Var).type);
				generate_Foreach_Validation_Code_Mips();
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 572 "cpm.y"
    {
				generate_Mips_Code_For_End_Of_Foreach_Loop_Mips();
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 576 "cpm.y"
    {
				push_Int_To_List((yyvsp[(2) - (6)].Var).id, (yyvsp[(4) - (6)].Var).value.Val_Int, FALSE, TRUE);
				push_Int_To_Mips((yyvsp[(2) - (6)].Var).id, (yyvsp[(4) - (6)].Var).value.Val_Int);
				generate_Start_For_each_Code_For_Mips();
				generate_Comparison_Mips("ne", (yyvsp[(2) - (6)].Var).id, (yyvsp[(6) - (6)].Var).id, (yyvsp[(2) - (6)].Var).value.Val_Int, (yyvsp[(6) - (6)].Var).value.Val_Int, (yyvsp[(2) - (6)].Var).value.Var_Float, (yyvsp[(6) - (6)].Var).value.Var_Float, 'i', (yyvsp[(6) - (6)].Var).type);
				generate_Foreach_Validation_Code_Mips();
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 584 "cpm.y"
    {
				generate_Mips_Code_For_End_Of_Foreach_Loop_Mips();
				remove_Symbol_From_Table((yyvsp[(2) - (10)].Var).id);
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 589 "cpm.y"
    {
				generate_Do_While_Start_For_Mips();
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 593 "cpm.y"
    {
				 generate_Do_Validation_Mips_Statement();
				generate_End_Of_Do_Statement_In_For_Mips();
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 625 "cpm.y"
    {
				generate_Mips_Code_For_Switch_Case((yyvsp[(1) - (1)].Var).id, 0, 0.0, (yyvsp[(1) - (1)].Var).type);
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 630 "cpm.y"
    {
				generate_Mips_Code_For_Switch_Case(NULL, (yyvsp[(1) - (1)].Var).value.Val_Int, (yyvsp[(1) - (1)].Var).value.Var_Float, (yyvsp[(1) - (1)].Var).type);
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 651 "cpm.y"
    {
				generate_Mips_Assembly_For_Switch_Case((yyvsp[(2) - (3)].Var).value.Val_Int, (yyvsp[(2) - (3)].Var).value.Var_Float, (yyvsp[(2) - (3)].Var).type);
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 655 "cpm.y"
    {
				generate_Switch_Break_For_Mips();
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 661 "cpm.y"
    {
				generate_Switch_Choice_For_Mips();
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 665 "cpm.y"
    {
				generate_Switch_End_Label_For_Mips();
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 678 "cpm.y"
    {
				if ((yyvsp[(4) - (5)].op) = addop) // $4 is a reference to the fourth item in the syntax rule 
				{
					generate_Arithmetic_Op_For_Mips("add", (yyvsp[(3) - (5)].Var).id, NULL, (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(5) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float, (yyvsp[(5) - (5)].Var).value.Var_Float, 'i', (yyvsp[(5) - (5)].Var).type);
					generate_End_For_Mips((yyvsp[(1) - (5)].Var).id, 'i');
				}
				else //($4 == subop) // $4 is a reference to the fourth item in the syntax rule 
				{
					generate_Arithmetic_Op_For_Mips("sub", (yyvsp[(3) - (5)].Var).id, NULL, (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(5) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float, (yyvsp[(5) - (5)].Var).value.Var_Float, 'i', (yyvsp[(5) - (5)].Var).type);
					generate_End_For_Mips((yyvsp[(1) - (5)].Var).id, 'i');
				}
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 692 "cpm.y"
    {
				if ((yyvsp[(4) - (5)].op) = mulop) //  $4 is a reference to the fourth item in the syntax rule 
				{
					generate_Arithmetic_Op_For_Mips("mul", (yyvsp[(3) - (5)].Var).id, NULL, (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(5) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float, (yyvsp[(5) - (5)].Var).value.Var_Float, 'i', (yyvsp[(5) - (5)].Var).type);
					generate_End_For_Mips((yyvsp[(1) - (5)].Var).id, 'i');
				}
				else //($4 == divop) // $4 is a reference to the fourth item in the syntax rule 
				{
					generate_Arithmetic_Op_For_Mips("div", (yyvsp[(3) - (5)].Var).id, NULL, (yyvsp[(3) - (5)].Var).value.Val_Int, (yyvsp[(5) - (5)].Var).value.Val_Int, (yyvsp[(3) - (5)].Var).value.Var_Float, (yyvsp[(5) - (5)].Var).value.Var_Float, 'i', (yyvsp[(5) - (5)].Var).type);
					generate_End_For_Mips((yyvsp[(1) - (5)].Var).id, 'i');
				}
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 715 "cpm.y"
    {
				if ((yyvsp[(2) - (3)].op) == andop)
				{
					generate_And_or_Or_For_Mips("and");
				}
				
				else // ($2 == orop)
				{
					generate_And_or_Or_For_Mips("or");
				}
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 728 "cpm.y"
    {
				if ((yyvsp[(2) - (3)].op) == andop)
				{
					generate_And_or_Or_For_Mips("and");
				}
				else // ($2 == orop)
				{
					generate_And_or_Or_For_Mips("or");
				}
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 753 "cpm.y"
    {
				Flag_Not = TRUE;
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 757 "cpm.y"
    {
				Flag_Not = FALSE;	
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 762 "cpm.y"
    {
				if ((yyvsp[(1) - (3)].Var).type == 's' || (yyvsp[(3) - (3)].Var).type == 's')
				{
					Error_With_String_op();
				}
				else
				{
					if ((yyvsp[(2) - (3)].op) == equalop)
                    {
                        generate_Comparison_Mips("eq", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                    }
                    else 
					if ((yyvsp[(2) - (3)].op) == notequalop)
                        {
                          generate_Comparison_Mips("ne", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                        }
                      else 
					  if ((yyvsp[(2) - (3)].op) == lessthanop)
                            {
                               generate_Comparison_Mips("lt", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                            }
                            else 
							if ((yyvsp[(2) - (3)].op) == greaterthanop)
                                  {
                                     generate_Comparison_Mips("gt", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                                  }
                                    else 
									if ((yyvsp[(2) - (3)].op) == greatorequalop)
                                     {
                                       generate_Comparison_Mips("ge", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                                     }
                                      else 
									  if ((yyvsp[(2) - (3)].op) == lessorequal)
                                        {
                                         generate_Comparison_Mips("le", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
                                        }
				}
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 815 "cpm.y"
    {
				Node_Symbol_In_Table* node1 = find_Node_using_Id ((yyvsp[(1) - (3)].Var).id);
				Node_Symbol_In_Table* node2 = find_Node_using_Id ((yyvsp[(3) - (3)].Var).id);
				if ((yyvsp[(1) - (3)].Var).type == 's' || (yyvsp[(3) - (3)].Var). type == 's')
				{
					Error_With_String_op();
				}
				else if ((yyvsp[(1) - (3)].Var).id != NULL && !node1->hasBeenAssigned)
				{
					Error_undeclared_Var((yyvsp[(1) - (3)].Var).id);
				}
				else if ((yyvsp[(3) - (3)].Var).id != NULL && !node2->hasBeenAssigned)
				{
					Error_undeclared_Var((yyvsp[(3) - (3)].Var).id);
				}
				else
				{
					if ((yyvsp[(2) - (3)].op) == addop)
					{
						if (operationInPrograss)
						{
							generate_Mips_Arith_Expr("add", (yyvsp[(3) - (3)].Var).id, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).type);
						}
						else
						{
							generate_Arithmetic_Op_For_Mips("add", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
						}

						if ((yyvsp[(1) - (3)].Var).type == 'i' && (yyvsp[(3) - (3)].Var).type == 'i')
						{
							(yyval.Var).type = 'i';
							(yyval.Var).value.Val_Int = (yyvsp[(1) - (3)].Var).value.Val_Int + (yyvsp[(3) - (3)].Var).value.Val_Int;
						}
						else
						{
							(yyval.Var).type = 'f';
							(yyval.Var).value.Var_Float = ((yyvsp[(1) - (3)].Var).type == 'i' ? (yyvsp[(1) - (3)].Var).value.Val_Int : (yyvsp[(1) - (3)].Var).value.Var_Float) + ((yyvsp[(3) - (3)].Var).type == 'i' ? (yyvsp[(3) - (3)].Var).value.Val_Int : (yyvsp[(3) - (3)].Var).value.Var_Float);
						}
					}
					else // ($2 == subop)
					{
						if (operationInPrograss)
						{
							generate_Mips_Arith_Expr("sub", (yyvsp[(1) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type);
						}
						else
						{
							generate_Arithmetic_Op_For_Mips("sub", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
						}

						if ((yyvsp[(1) - (3)].Var).type == 'i' && (yyvsp[(3) - (3)].Var).type == 'i')
						{
							(yyval.Var).type = 'i';
							(yyval.Var).value.Val_Int = (yyvsp[(1) - (3)].Var).value.Val_Int - (yyvsp[(3) - (3)].Var).value.Val_Int;
						}
						else
						{
							(yyval.Var).type = 'f';
							(yyval.Var).value.Var_Float = ((yyvsp[(1) - (3)].Var).type == 'i' ? (yyvsp[(1) - (3)].Var).value.Val_Int : (yyvsp[(1) - (3)].Var).value.Var_Float) - ((yyvsp[(3) - (3)].Var).type == 'i' ? (yyvsp[(3) - (3)].Var).value.Val_Int : (yyvsp[(3) - (3)].Var).value.Var_Float);
						}
					}
				}
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 880 "cpm.y"
    {
				(yyval.Var) = (yyvsp[(1) - (1)].Var);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 895 "cpm.y"
    {
				Node_Symbol_In_Table* node1 = find_Node_using_Id ((yyvsp[(1) - (3)].Var).id);
				Node_Symbol_In_Table* node2 = find_Node_using_Id ((yyvsp[(3) - (3)].Var).id);


				if ((yyvsp[(1) - (3)].Var).type == 's' || (yyvsp[(3) - (3)].Var). type == 's')
				{
					Error_With_String_op();
				}
				else if ((yyvsp[(1) - (3)].Var).id != NULL && !node1->hasBeenAssigned)
				{
					Error_undeclared_Var((yyvsp[(1) - (3)].Var).id);
				}
				else if ((yyvsp[(3) - (3)].Var).id != NULL && !node2->hasBeenAssigned)
				{
					Error_undeclared_Var((yyvsp[(3) - (3)].Var).id);
				}
				else
				{
					if ((yyvsp[(2) - (3)].op) == mulop)
					{
						if (operationInPrograss)
						{
							generate_Mips_Arith_Expr("mul", (yyvsp[(1) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type);
						}
						else
						{
							generate_Arithmetic_Op_For_Mips("mul", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
						}

						if ((yyvsp[(1) - (3)].Var).type == 'i' && (yyvsp[(3) - (3)].Var).type == 'i')
						{
							(yyval.Var).type = 'i';
							(yyval.Var).value.Val_Int = (yyvsp[(1) - (3)].Var).value.Val_Int * (yyvsp[(3) - (3)].Var).value.Val_Int;
						}
						else
						{
							(yyval.Var).type = 'f';
							(yyval.Var).value.Var_Float = ((yyvsp[(1) - (3)].Var).type == 'i' ? (yyvsp[(1) - (3)].Var).value.Val_Int : (yyvsp[(1) - (3)].Var).value.Var_Float) * ((yyvsp[(3) - (3)].Var).type == 'i' ? (yyvsp[(3) - (3)].Var).value.Val_Int : (yyvsp[(3) - (3)].Var).value.Var_Float);
						}
					}
					else // ($2 == divop)
					{
						if (operationInPrograss)
						{
							generate_Mips_Arith_Expr("div", (yyvsp[(1) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type);
						}
						else
						{
							generate_Arithmetic_Op_For_Mips("div", (yyvsp[(1) - (3)].Var).id, (yyvsp[(3) - (3)].Var).id, (yyvsp[(1) - (3)].Var).value.Val_Int, (yyvsp[(3) - (3)].Var).value.Val_Int, (yyvsp[(1) - (3)].Var).value.Var_Float, (yyvsp[(3) - (3)].Var).value.Var_Float, (yyvsp[(1) - (3)].Var).type, (yyvsp[(3) - (3)].Var).type);
						}

						if ((yyvsp[(1) - (3)].Var).type == 'i' && (yyvsp[(3) - (3)].Var).type == 'i')
						{
							(yyval.Var).type = 'i';
							(yyval.Var).value.Val_Int = (yyvsp[(1) - (3)].Var).value.Val_Int * (yyvsp[(3) - (3)].Var).value.Val_Int;
						}
						else
						{
							(yyval.Var).type = 'f';
							(yyval.Var).value.Var_Float = ((yyvsp[(1) - (3)].Var).type == 'i' ? (yyvsp[(1) - (3)].Var).value.Val_Int : (yyvsp[(1) - (3)].Var).value.Var_Float) * ((yyvsp[(3) - (3)].Var).type == 'i' ? (yyvsp[(3) - (3)].Var).value.Val_Int : (yyvsp[(3) - (3)].Var).value.Var_Float);
						}
					}
				}
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 962 "cpm.y"
    {
				(yyval.Var) = (yyvsp[(1) - (1)].Var);
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 980 "cpm.y"
    {
				(yyval.Var) = (yyvsp[(2) - (3)].Var);
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 985 "cpm.y"
    {
				Node_Symbol_In_Table* node = find_Node_using_Id ((yyvsp[(1) - (1)].Var).id);

				if (node == NULL)
				{
					Error_undeclared_Var((yyvsp[(1) - (1)].Var).id);
				}
				else
				{
					(yyval.Var).id = (yyvsp[(1) - (1)].Var).id;

					switch (node->type)
					{
						case 'i':
							(yyval.Var).type = 'i';
							(yyval.Var).value.Val_Int = (yyvsp[(1) - (1)].Var).value.Val_Int;
							break;

						case 'f':
							(yyval.Var).type = 'f';
							(yyval.Var).value.Var_Float = (yyvsp[(1) - (1)].Var).value.Var_Float;
							break;

						case 's':
							(yyval.Var).type = 's';
							(yyval.Var).value.Val_String = (yyvsp[(1) - (1)].Var).value.Val_String;
							break;
					}
				}
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1017 "cpm.y"
    {
				(yyval.Var).id = NULL;

				if ((yyvsp[(1) - (1)].Var).type == 'i')
				{
					(yyval.Var).type = 'i';
					(yyval.Var).value.Val_Int = (yyvsp[(1) - (1)].Var).value.Val_Int;
				}
				else
				{
					(yyval.Var).type = 'f';
					(yyval.Var).value.Var_Float = (yyvsp[(1) - (1)].Var).value.Var_Float;
				}
			}
    break;


/* Line 1792 of yacc.c  */
#line 2365 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1032 "cpm.y"
