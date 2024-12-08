/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "semantic.y"
 
	/* Para simplificar a notação, S é para sintetizar. A atualizar. V verificar */
	#include "analex.c" 
	#include "codigo.h"
	#define Funct 4
	/* Funcoes auxiliares podem ser declaradas aqui */
	void verifica_var_declarada(int id);
	void verifica_funcao_declarada(int id);
	void verifica_tipos_atrib(int tipo1, int tipo2);
	void verifica_numero_argumentos(int id, int num_args);
	void verifica_indice_valido(int id, int indice);
		
	

#line 86 "semantic.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "semantic.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_ENDIF = 8,                      /* ENDIF  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NEQ = 19,                       /* NEQ  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_ProgL = 39,                     /* ProgL  */
  YYSYMBOL_Prog = 40,                      /* Prog  */
  YYSYMBOL_Function = 41,                  /* Function  */
  YYSYMBOL_FunctionCall = 42,              /* FunctionCall  */
  YYSYMBOL_ArgList = 43,                   /* ArgList  */
  YYSYMBOL_ParamList = 44,                 /* ParamList  */
  YYSYMBOL_Decls = 45,                     /* Decls  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_IDs = 47,                       /* IDs  */
  YYSYMBOL_TypeF = 48,                     /* TypeF  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_Statement_Seq = 50,             /* Statement_Seq  */
  YYSYMBOL_Statement = 51,                 /* Statement  */
  YYSYMBOL_Compound_Stt = 52,              /* Compound_Stt  */
  YYSYMBOL_If = 53,                        /* If  */
  YYSYMBOL_While = 54,                     /* While  */
  YYSYMBOL_DoWhile = 55,                   /* DoWhile  */
  YYSYMBOL_Atribuicao = 56,                /* Atribuicao  */
  YYSYMBOL_Exp = 57                        /* Exp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      30,    32,    27,    25,    35,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      24,    22,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    77,    78,    82,    86,    93,   102,   114,
     125,   133,   142,   153,   158,   165,   182,   186,   193,   197,
     200,   203,   213,   214,   218,   219,   220,   224,   229,   237,
     241,   242,   243,   244,   248,   249,   253,   256,   262,   268,
     275,   283,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   310,   311,   312,   313
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "WHILE",
  "IF", "ELSE", "ENDIF", "CHAR", "INT", "FLOAT", "VOID", "OR", "AND",
  "NOT", "GE", "LE", "EQ", "NEQ", "DO", "STRING", "'='", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "'['", "')'", "'{'", "'}'",
  "','", "';'", "']'", "$accept", "ProgL", "Prog", "Function",
  "FunctionCall", "ArgList", "ParamList", "Decls", "Decl", "IDs", "TypeF",
  "Type", "Statement_Seq", "Statement", "Compound_Stt", "If", "While",
  "DoWhile", "Atribuicao", "Exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -74,   -74,   -74,   -74,    29,    16,   -74,    -1,   -74,
     -74,   -74,     0,     2,    25,    22,    51,    94,    27,    94,
     -74,    11,    32,    61,    94,    67,    42,    55,    82,     4,
      47,    88,    11,   -74,   -74,   -74,    59,    94,    39,   102,
     -74,    11,   -74,    48,     3,   126,    48,    48,    11,   -74,
     133,   -74,   -74,   -74,   -74,   -74,   136,   142,   120,   -74,
     124,   -74,    48,    48,   161,   -74,   132,    63,   119,    83,
     100,   131,   137,   144,    53,   -74,   -74,   165,   -74,   117,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,   -74,    48,   169,     4,     4,   -74,    48,   169,
     180,   159,   -74,   176,   189,   145,   145,   202,   202,   145,
     145,    65,    65,   -74,   -74,   -74,    48,   -74,   113,   134,
     160,   -74,   161,     4,   -74,   162,   169,   201,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    24,    26,    22,     0,     2,     4,     0,    23,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    30,    31,    32,     0,     0,    20,    15,
      21,     0,    11,     0,     0,     0,     0,     0,     0,    34,
       0,    33,     6,    27,    29,    13,     0,     0,     0,    56,
      59,    57,     0,     0,    41,     8,     0,    10,     0,     0,
       0,     0,     0,     0,    16,    17,     5,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,    35,     0,    19,
       0,     0,    55,    52,    53,    48,    49,    50,    51,    46,
      47,    42,    43,    44,    45,     9,     0,    38,     0,     0,
       0,    58,    40,     0,    36,     0,    18,     0,    39,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   204,   -74,   118,   -74,    -5,   -74,   -74,
     -74,   163,    21,   -29,   -73,   -74,   -74,   -74,   -21,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    30,    66,    15,    21,    22,    39,
       8,    23,    31,    32,    50,    33,    34,    35,    36,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    64,    40,    12,    69,    70,    59,    60,    26,    27,
      28,     1,     2,     3,    61,    26,    27,    28,    62,    41,
      78,    79,   117,   118,    29,     1,     2,     3,     4,    10,
      13,    29,    55,    63,    14,    65,    75,    48,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     127,    59,    60,    53,    18,    20,   119,    19,    17,    61,
      24,    43,    58,    62,    43,    38,    49,    49,    37,    71,
      56,    42,    44,    45,   122,    43,    80,    81,    63,    82,
      83,    84,    85,    51,   100,    46,    86,    87,    88,    89,
      90,    91,    90,    91,    49,    54,    80,    81,    93,    82,
      83,    84,    85,     1,     2,     3,    86,    87,    88,    89,
      90,    91,    47,    80,    81,    95,    82,    83,    84,    85,
     123,   124,    52,    86,    87,    88,    89,    90,    91,    68,
      80,    81,    96,    82,    83,    84,    85,    57,    72,    73,
      86,    87,    88,    89,    90,    91,    74,    80,    81,   102,
      82,    83,    84,    85,    76,    77,    94,    86,    87,    88,
      89,    90,    91,     9,    92,    97,   125,    98,   101,     9,
      88,    89,    90,    91,    80,    81,    16,    82,    83,    84,
      85,    99,    25,   120,    86,    87,    88,    89,    90,    91,
      81,   116,    82,    83,    84,    85,   121,   126,   128,    86,
      87,    88,    89,    90,    91,    82,    83,    84,    85,   129,
      11,   115,    86,    87,    88,    89,    90,    91,    82,    83,
      -1,    -1,     0,     0,     0,    86,    87,    88,    89,    90,
      91
};

static const yytype_int8 yycheck[] =
{
      29,    43,    23,     4,    46,    47,     3,     4,     4,     5,
       6,     9,    10,    11,    11,     4,     5,     6,    15,    24,
      62,    63,    95,    96,    20,     9,    10,    11,    12,     0,
      30,    20,    37,    30,    32,    32,    57,    33,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     123,     3,     4,    32,    32,     4,    98,    35,    33,    11,
      33,    22,    41,    15,    22,     4,    95,    96,    36,    48,
      31,     4,    30,    31,   116,    22,    13,    14,    30,    16,
      17,    18,    19,    36,    31,    30,    23,    24,    25,    26,
      27,    28,    27,    28,   123,    36,    13,    14,    35,    16,
      17,    18,    19,     9,    10,    11,    23,    24,    25,    26,
      27,    28,    30,    13,    14,    32,    16,    17,    18,    19,
       7,     8,    34,    23,    24,    25,    26,    27,    28,     3,
      13,    14,    32,    16,    17,    18,    19,    35,     5,     3,
      23,    24,    25,    26,    27,    28,     4,    13,    14,    32,
      16,    17,    18,    19,    34,    31,    37,    23,    24,    25,
      26,    27,    28,     0,    32,    34,    32,    30,     3,     6,
      25,    26,    27,    28,    13,    14,    13,    16,    17,    18,
      19,    37,    19,     3,    23,    24,    25,    26,    27,    28,
      14,    22,    16,    17,    18,    19,    37,    37,    36,    23,
      24,    25,    26,    27,    28,    16,    17,    18,    19,     8,
       6,    93,    23,    24,    25,    26,    27,    28,    16,    17,
      18,    19,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    39,    40,    41,    48,    49,
       0,    41,     4,    30,    32,    44,    49,    33,    32,    35,
       4,    45,    46,    49,    33,    49,     4,     5,     6,    20,
      42,    50,    51,    53,    54,    55,    56,    36,     4,    47,
      56,    45,     4,    22,    30,    31,    30,    30,    33,    51,
      52,    36,    34,    50,    36,    45,    31,    35,    50,     3,
       4,    11,    15,    30,    57,    32,    43,    57,     3,    57,
      57,    50,     5,     3,     4,    56,    34,    31,    57,    57,
      13,    14,    16,    17,    18,    19,    23,    24,    25,    26,
      27,    28,    32,    35,    37,    32,    32,    34,    30,    37,
      31,     3,    32,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    43,    22,    52,    52,    57,
       3,    37,    57,     7,     8,    32,    37,    52,    36,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     9,     8,     4,     3,     3,
       1,     4,     2,     3,     1,     2,     3,     3,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     3,     6,     8,     5,     7,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* ProgL: Prog  */
#line 74 "semantic.y"
                     {printf("%s",(yyvsp[0].node).code);}
#line 1223 "semantic.c"
    break;

  case 3: /* Prog: Prog Function  */
#line 77 "semantic.y"
                             {create_cod(&(yyval.node).code); insert_cod(&(yyval.node).code,(yyvsp[-1].node).code); insert_cod(&(yyval.node).code,(yyvsp[0].node).code);}
#line 1229 "semantic.c"
    break;

  case 4: /* Prog: Function  */
#line 78 "semantic.y"
                           {}
#line 1235 "semantic.c"
    break;

  case 5: /* Function: TypeF ID '(' ParamList ')' '{' Decls Statement_Seq '}'  */
#line 82 "semantic.y"
                                                           {
        adiciona_funcao_tabela(obtemNome((yyvsp[-7].val)), (yyvsp[-8].val), &(yyvsp[-5].id_list));
        create_cod(&(yyval.node).code);
    }
#line 1244 "semantic.c"
    break;

  case 6: /* Function: TypeF ID '(' ')' '{' Decls Statement_Seq '}'  */
#line 86 "semantic.y"
                                                   {
        adiciona_funcao_tabela(obtemNome((yyvsp[-6].val)), (yyvsp[-7].val), NULL); 
        Funct(&(yyval.node), (yyvsp[-6].val), (yyvsp[-1].node));                
    }
#line 1253 "semantic.c"
    break;

  case 7: /* FunctionCall: ID '(' ArgList ')'  */
#line 93 "semantic.y"
                       {
        int funcPos = (yyvsp[-3].val); 
        if (funcPos == -1) {
            yyerror("Função não declarada!");
        } else if (Tabela[funcPos].tam_arg_list != (yyvsp[-1].id_list).tam) {
            yyerror("Número de argumentos incompatível!");
        }
        Call(&(yyval.node), funcPos, &(yyvsp[-1].id_list));
    }
#line 1267 "semantic.c"
    break;

  case 8: /* FunctionCall: ID '(' ')'  */
#line 102 "semantic.y"
                 {
        int funcPos = procura(obtemNome((yyvsp[-2].val)));
        if (funcPos == -1) {
            yyerror("Função não declarada!");
        } else if (Tabela[funcPos].tam_arg_list != 0) {
            yyerror("Número de argumentos incompatível!");
        }
        Call_blank(&(yyval.node));
    }
#line 1281 "semantic.c"
    break;

  case 9: /* ArgList: Exp ',' ArgList  */
#line 114 "semantic.y"
                    {
        create_cod(&(yyval.id_list).code);
        (yyval.id_list).tam = (yyvsp[0].id_list).tam + 1; 
        (yyval.id_list).ids[0] = (yyvsp[-2].node).place; 
        for (int i = 0; i < (yyvsp[0].id_list).tam; i++) 
        {
            (yyval.id_list).ids[i + 1] = (yyvsp[0].id_list).ids[i];
        }
        insert_cod(&(yyval.id_list).code, (yyvsp[-2].node).code);
        insert_cod(&(yyval.id_list).code, (yyvsp[0].id_list).code);
    }
#line 1297 "semantic.c"
    break;

  case 10: /* ArgList: Exp  */
#line 125 "semantic.y"
          {
        create_cod(&(yyval.id_list).code);
        (yyval.id_list).tam = 1;
        (yyval.id_list).ids[0] = (yyvsp[0].node).place;
        insert_cod(&(yyval.id_list).code, (yyvsp[0].node).code);
    }
#line 1308 "semantic.c"
    break;

  case 11: /* ParamList: ParamList ',' Type ID  */
#line 133 "semantic.y"
                          {
        (yyval.id_list).ids[(yyval.id_list).tam] = insere(obtemNome((yyvsp[0].val)));
        if(getTipo((yyvsp[0].val)) == -1)
            set_type((yyval.id_list).ids[(yyval.id_list).tam], (yyvsp[-1].val));
        else 
            if(getTipo((yyvsp[0].val)) != (yyvsp[-1].val))
                yyerror("Tipos de argumentos incompatíveis!");
        (yyval.id_list).tam++;
    }
#line 1322 "semantic.c"
    break;

  case 12: /* ParamList: Type ID  */
#line 142 "semantic.y"
              {
        (yyval.id_list).ids[(yyval.id_list).tam] = insere(obtemNome((yyvsp[0].val)));
        if(getTipo((yyvsp[0].val)) == -1)
            set_type((yyval.id_list).ids[(yyval.id_list).tam], (yyvsp[-1].val));
        else 
            if(getTipo((yyvsp[0].val)) != (yyvsp[-1].val))
                yyerror("Tipos de argumentos incompatíveis!");
        }
#line 1335 "semantic.c"
    break;

  case 13: /* Decls: Decl ';' Decls  */
#line 153 "semantic.y"
                   {
        create_cod(&(yyval.node).code);
        insert_cod(&(yyval.node).code, (yyvsp[-2].node).code);
        insert_cod(&(yyval.node).code, (yyvsp[0].node).code);
    }
#line 1345 "semantic.c"
    break;

  case 14: /* Decls: Decl  */
#line 158 "semantic.y"
           {
        create_cod(&(yyval.node).code);
        insert_cod(&(yyval.node).code, (yyvsp[0].node).code);
    }
#line 1354 "semantic.c"
    break;

  case 15: /* Decl: Type IDs  */
#line 165 "semantic.y"
             {
        int tipo;
        create_cod(&(yyval.node).code);
        if ((yyvsp[0].id_list).code != NULL)
            insert_cod(&(yyval.node).code, (yyvsp[0].id_list).code);
        for (int i = 0; i < (yyvsp[0].id_list).tam; i++) 
        {
            tipo = getTipo((yyvsp[0].id_list).ids[i]);
            if(tipo != (yyvsp[-1].val))
                yyerror("Erro Semântico");
            set_type((yyvsp[0].id_list).ids[i], (yyvsp[-1].val));
        }
    }
#line 1372 "semantic.c"
    break;

  case 16: /* IDs: IDs ',' ID  */
#line 182 "semantic.y"
               {
        (yyval.id_list).ids[(yyval.id_list).tam] = procura(obtemNome((yyvsp[0].val)));
        (yyval.id_list).tam++;
    }
#line 1381 "semantic.c"
    break;

  case 17: /* IDs: IDs ',' Atribuicao  */
#line 186 "semantic.y"
                         {
        int pos = procura(obtemNome((yyvsp[0].node).place));
        create_cod(&(yyval.id_list).code);
        insert_cod(&(yyval.id_list).code, (yyvsp[0].node).code);
        (yyval.id_list).ids[(yyval.id_list).tam] = pos;
        (yyval.id_list).tam++;
    }
#line 1393 "semantic.c"
    break;

  case 18: /* IDs: IDs ',' ID '[' NUM ']'  */
#line 193 "semantic.y"
                             {
        (yyval.id_list).ids[(yyval.id_list).tam] = procura(obtemNome((yyvsp[-3].val)));
        (yyval.id_list).tam++;
    }
#line 1402 "semantic.c"
    break;

  case 19: /* IDs: ID '[' NUM ']'  */
#line 197 "semantic.y"
                     {
        (yyval.id_list).ids[(yyval.id_list).tam] = procura(obtemNome((yyvsp[-3].val)));
    }
#line 1410 "semantic.c"
    break;

  case 20: /* IDs: ID  */
#line 200 "semantic.y"
         {
        (yyval.id_list).ids[(yyval.id_list).tam] = procura(obtemNome((yyvsp[0].val)));
    }
#line 1418 "semantic.c"
    break;

  case 21: /* IDs: Atribuicao  */
#line 203 "semantic.y"
                 {
        int pos = procura(obtemNome((yyvsp[0].node).place));
        create_cod(&(yyval.id_list).code);
        insert_cod(&(yyval.id_list).code, (yyvsp[0].node).code);
        (yyval.id_list).ids[(yyval.id_list).tam] = pos;
    }
#line 1429 "semantic.c"
    break;

  case 22: /* TypeF: VOID  */
#line 213 "semantic.y"
               {(yyval.val) = VOID;}
#line 1435 "semantic.c"
    break;

  case 23: /* TypeF: Type  */
#line 214 "semantic.y"
               {(yyval.val) = (yyvsp[0].val);}
#line 1441 "semantic.c"
    break;

  case 24: /* Type: INT  */
#line 218 "semantic.y"
              {(yyval.val) = INT;}
#line 1447 "semantic.c"
    break;

  case 25: /* Type: CHAR  */
#line 219 "semantic.y"
               {(yyval.val) = CHAR;}
#line 1453 "semantic.c"
    break;

  case 26: /* Type: FLOAT  */
#line 220 "semantic.y"
                {(yyval.val) = FLOAT;}
#line 1459 "semantic.c"
    break;

  case 27: /* Statement_Seq: Statement Statement_Seq  */
#line 224 "semantic.y"
                            {
        create_cod(&(yyval.node).code);
        insert_cod(&(yyval.node).code, (yyvsp[-1].node).code);
        insert_cod(&(yyval.node).code, (yyvsp[0].node).code);
    }
#line 1469 "semantic.c"
    break;

  case 28: /* Statement_Seq: Statement  */
#line 229 "semantic.y"
                {
        create_cod(&(yyval.node).code);
        insert_cod(&(yyval.node).code, (yyvsp[0].node).code);
    }
#line 1478 "semantic.c"
    break;

  case 29: /* Statement: Atribuicao ';'  */
#line 237 "semantic.y"
                         {
        procura(obtemNome((yyvsp[-1].node).place));
        rtd(Tabela[(yyvsp[-1].node).place].tipo, (yyvsp[-1].node).tipo);
    }
#line 1487 "semantic.c"
    break;

  case 35: /* Compound_Stt: '{' Statement_Seq '}'  */
#line 249 "semantic.y"
                                {(yyval.node) = (yyvsp[-1].node);}
#line 1493 "semantic.c"
    break;

  case 36: /* If: IF '(' Exp ')' Compound_Stt ENDIF  */
#line 253 "semantic.y"
                                            { 
		If(&(yyval.node), (yyvsp[-3].node),(yyvsp[-1].node));
	}
#line 1501 "semantic.c"
    break;

  case 37: /* If: IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF  */
#line 256 "semantic.y"
                                                              {
		IfElse(&(yyval.node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node));
	}
#line 1509 "semantic.c"
    break;

  case 38: /* While: WHILE '(' Exp ')' Compound_Stt  */
#line 262 "semantic.y"
                                   {
        While(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1517 "semantic.c"
    break;

  case 39: /* DoWhile: DO Compound_Stt WHILE '(' Exp ')' ';'  */
#line 268 "semantic.y"
                                          {
        DoWhile(&(yyval.node), (yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 1525 "semantic.c"
    break;

  case 40: /* Atribuicao: ID '[' NUM ']' '=' Exp  */
#line 275 "semantic.y"
                               {
    	if (procura(obtemNome((yyvsp[-5].val))) != -1)
    		Atrib(&(yyval.node), (yyvsp[-3].node));
    	else
    		yyerror("Erro Semântico");

        (yyval.node).tipo = rtd(getTipo((yyvsp[-5].val)), (yyvsp[0].node).tipo);
	}
#line 1538 "semantic.c"
    break;

  case 41: /* Atribuicao: ID '=' Exp  */
#line 283 "semantic.y"
                 {
    	if (procura(obtemNome((yyvsp[-2].val))) != -1)
    		Atrib(&(yyval.node), (yyvsp[0].node));
    	else
    		yyerror("Erro Semântico");

        (yyval.node).tipo = rtd(getTipo((yyvsp[-2].val)), (yyvsp[0].node).tipo);
    }
#line 1551 "semantic.c"
    break;

  case 42: /* Exp: Exp '+' Exp  */
#line 294 "semantic.y"
                            {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo); Exp_Ari(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node),"add");}
#line 1557 "semantic.c"
    break;

  case 43: /* Exp: Exp '-' Exp  */
#line 295 "semantic.y"
                              {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo); Exp_Ari(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "sub");}
#line 1563 "semantic.c"
    break;

  case 44: /* Exp: Exp '*' Exp  */
#line 296 "semantic.y"
                              {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo); Exp_Ari(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "mul");}
#line 1569 "semantic.c"
    break;

  case 45: /* Exp: Exp '/' Exp  */
#line 297 "semantic.y"
                              {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo);Exp_Ari(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "div");}
#line 1575 "semantic.c"
    break;

  case 46: /* Exp: Exp '>' Exp  */
#line 298 "semantic.y"
                              {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo); Exp_Rel(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "bgt");}
#line 1581 "semantic.c"
    break;

  case 47: /* Exp: Exp '<' Exp  */
#line 299 "semantic.y"
                              {(yyval.node).tipo = rtd((yyvsp[-2].node).tipo, (yyvsp[0].node).tipo); Exp_Rel(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "blt");}
#line 1587 "semantic.c"
    break;

  case 48: /* Exp: Exp GE Exp  */
#line 300 "semantic.y"
                             {(yyval.node).tipo = INT;}
#line 1593 "semantic.c"
    break;

  case 49: /* Exp: Exp LE Exp  */
#line 301 "semantic.y"
                             {(yyval.node).tipo = INT;}
#line 1599 "semantic.c"
    break;

  case 50: /* Exp: Exp EQ Exp  */
#line 302 "semantic.y"
                             {(yyval.node).tipo = INT;}
#line 1605 "semantic.c"
    break;

  case 51: /* Exp: Exp NEQ Exp  */
#line 303 "semantic.y"
                              {(yyval.node).tipo = INT;}
#line 1611 "semantic.c"
    break;

  case 52: /* Exp: Exp OR Exp  */
#line 304 "semantic.y"
                             {(yyval.node).tipo = INT; Exp_Log(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "or");}
#line 1617 "semantic.c"
    break;

  case 53: /* Exp: Exp AND Exp  */
#line 305 "semantic.y"
                              {(yyval.node).tipo = INT; Exp_Log(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node), "and");}
#line 1623 "semantic.c"
    break;

  case 54: /* Exp: NOT Exp  */
#line 306 "semantic.y"
                          {(yyval.node).tipo = INT;}
#line 1629 "semantic.c"
    break;

  case 55: /* Exp: '(' Exp ')'  */
#line 307 "semantic.y"
                              {
			(yyval.node).tipo = (yyvsp[-1].node).tipo;
		}
#line 1637 "semantic.c"
    break;

  case 56: /* Exp: NUM  */
#line 310 "semantic.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1643 "semantic.c"
    break;

  case 57: /* Exp: FLOAT  */
#line 311 "semantic.y"
                        {(yyval.node).tipo = FLOAT;}
#line 1649 "semantic.c"
    break;

  case 58: /* Exp: ID '[' NUM ']'  */
#line 312 "semantic.y"
                                 {}
#line 1655 "semantic.c"
    break;

  case 59: /* Exp: ID  */
#line 313 "semantic.y"
                      {
        	(yyval.node).tipo = getTipo((yyvsp[0].val));
        	if((yyval.node).tipo == -1)
        {
            yyerror("Erro Semântico, var não declarada");
        } 
	}
#line 1667 "semantic.c"
    break;


#line 1671 "semantic.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 322 "semantic.y"
  
	int main(int argc, char **argv) {     
	yyin = fopen(argv[1],"r");
	yyparse();      
	} 

	/* Funcoes auxiliares podem ser implementadas aqui */
	void verifica_var_declarada(int id) {
		if (Tabela[id].tipo == 0) { 
			fprintf(stderr, "Erro: Variável %s não foi declarada.\n", Tabela[id].nome);
			exit(1); 
		}
	}

	void verifica_funcao_declarada(int id) {
		if (Tabela[id].tipo != Funct) {
			fprintf(stderr, "Erro: Função %s não foi declarada.\n", Tabela[id].nome);
			exit(1);
		}
	}

	void verifica_tipos_atrib(int tipo1, int tipo2) {
		if (tipo1 != tipo2) {
			fprintf(stderr, "Erro: Tipos incompatíveis na atribuição.\n");
			exit(1);
		}
	}

	void verifica_numero_argumentos(int id, int num_args) {
		if (Tabela[id].tam_arg_list != num_args) {
			fprintf(stderr, "Erro: Função %s esperava %d argumentos, mas recebeu %d.\n",
					Tabela[id].nome, Tabela[id].tam_arg_list, num_args);
			exit(1);
		}
	}

	void verifica_indice_valido(int id, int indice) {
		if (indice < 0 || indice >= Tabela[id].tam) {
			fprintf(stderr, "Erro: Índice %d fora dos limites do vetor %s.\n", indice, Tabela[id].nome);
			exit(1);
		}
	}
