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
#line 1 "compiler.y"

#include "compiler.h"
#include <iostream>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

#line 79 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LEQ = 258,                     /* LEQ  */
    GEQ = 259,                     /* GEQ  */
    NEQ = 260,                     /* NEQ  */
    EQ = 261,                      /* EQ  */
    RETURN = 262,                  /* RETURN  */
    BFCT = 263,                    /* BFCT  */
    EFCT = 264,                    /* EFCT  */
    AND = 265,                     /* AND  */
    OR = 266,                      /* OR  */
    ID = 267,                      /* ID  */
    STRING = 268,                  /* STRING  */
    TIP = 269,                     /* TIP  */
    ASSIGN = 270,                  /* ASSIGN  */
    BGIN = 271,                    /* BGIN  */
    END = 272,                     /* END  */
    CLASS = 273,                   /* CLASS  */
    ECLASS = 274,                  /* ECLASS  */
    IF = 275,                      /* IF  */
    EIF = 276,                     /* EIF  */
    ELSE = 277,                    /* ELSE  */
    FOR = 278,                     /* FOR  */
    EFOR = 279,                    /* EFOR  */
    CONSTANT = 280,                /* CONSTANT  */
    WHILE = 281,                   /* WHILE  */
    EWHILE = 282,                  /* EWHILE  */
    DO = 283,                      /* DO  */
    EVAL = 284,                    /* EVAL  */
    TYPEOF = 285,                  /* TYPEOF  */
    CHAR = 286,                    /* CHAR  */
    NR = 287,                      /* NR  */
    NR_FLOAT = 288                 /* NR_FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LEQ 258
#define GEQ 259
#define NEQ 260
#define EQ 261
#define RETURN 262
#define BFCT 263
#define EFCT 264
#define AND 265
#define OR 266
#define ID 267
#define STRING 268
#define TIP 269
#define ASSIGN 270
#define BGIN 271
#define END 272
#define CLASS 273
#define ECLASS 274
#define IF 275
#define EIF 276
#define ELSE 277
#define FOR 278
#define EFOR 279
#define CONSTANT 280
#define WHILE 281
#define EWHILE 282
#define DO 283
#define EVAL 284
#define TYPEOF 285
#define CHAR 286
#define NR 287
#define NR_FLOAT 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "compiler.y"

    float floatval;
    int intval;
    char* strval;
    class AST* tree;

#line 205 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEQ = 3,                        /* LEQ  */
  YYSYMBOL_GEQ = 4,                        /* GEQ  */
  YYSYMBOL_NEQ = 5,                        /* NEQ  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_BFCT = 8,                       /* BFCT  */
  YYSYMBOL_EFCT = 9,                       /* EFCT  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_TIP = 14,                       /* TIP  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_BGIN = 16,                      /* BGIN  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_CLASS = 18,                     /* CLASS  */
  YYSYMBOL_ECLASS = 19,                    /* ECLASS  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_EIF = 21,                       /* EIF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_EFOR = 24,                      /* EFOR  */
  YYSYMBOL_CONSTANT = 25,                  /* CONSTANT  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_EWHILE = 27,                    /* EWHILE  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_EVAL = 29,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 30,                    /* TYPEOF  */
  YYSYMBOL_CHAR = 31,                      /* CHAR  */
  YYSYMBOL_NR = 32,                        /* NR  */
  YYSYMBOL_NR_FLOAT = 33,                  /* NR_FLOAT  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_progr = 48,                     /* progr  */
  YYSYMBOL_rest1 = 49,                     /* rest1  */
  YYSYMBOL_rest2 = 50,                     /* rest2  */
  YYSYMBOL_sectiunea1 = 51,                /* sectiunea1  */
  YYSYMBOL_sectiunea2 = 52,                /* sectiunea2  */
  YYSYMBOL_sectiunea3 = 53,                /* sectiunea3  */
  YYSYMBOL_declaratieVariabila = 54,       /* declaratieVariabila  */
  YYSYMBOL_declaratieVariabilaClasa = 55,  /* declaratieVariabilaClasa  */
  YYSYMBOL_declaratieFunctie = 56,         /* declaratieFunctie  */
  YYSYMBOL_declaratieFunctieClasa = 57,    /* declaratieFunctieClasa  */
  YYSYMBOL_lista_param = 58,               /* lista_param  */
  YYSYMBOL_param = 59,                     /* param  */
  YYSYMBOL_clasa = 60,                     /* clasa  */
  YYSYMBOL_sectiuneaclasa1 = 61,           /* sectiuneaclasa1  */
  YYSYMBOL_sectiuneaclasa2 = 62,           /* sectiuneaclasa2  */
  YYSYMBOL_interior_clasa = 63,            /* interior_clasa  */
  YYSYMBOL_lista_id = 64,                  /* lista_id  */
  YYSYMBOL_bloc = 65,                      /* bloc  */
  YYSYMBOL_list = 66,                      /* list  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_cond = 68,                      /* cond  */
  YYSYMBOL_cond_expr = 69,                 /* cond_expr  */
  YYSYMBOL_opr = 70,                       /* opr  */
  YYSYMBOL_if = 71,                        /* if  */
  YYSYMBOL_for = 72,                       /* for  */
  YYSYMBOL_do = 73,                        /* do  */
  YYSYMBOL_while = 74,                     /* while  */
  YYSYMBOL_e = 75,                         /* e  */
  YYSYMBOL_pseudo_e = 76,                  /* pseudo_e  */
  YYSYMBOL_lista_apel = 77                 /* lista_apel  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 44 "compiler.y"

int yyerror(const char *);
int yylex(void);

#line 313 "y.tab.c"


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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    39,    37,    43,    36,    46,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      34,     2,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    58,    61,    66,    67,    70,    71,    74,
      75,    80,    81,    86,    87,    92,    93,    94,    95,    98,
      99,   104,   105,   110,   117,   120,   121,   124,   125,   128,
     129,   130,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   155,   161,   162,   163,   164,   165,
     166,   177,   188,   189,   190,   191,   195,   207,   217,   222,
     227,   228,   231,   234,   245,   246,   258,   259,   260,   261,
     262,   263,   266,   267,   270,   271,   274,   277,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   297,   298,   305,
     314,   323,   332,   341,   342,   343,   344,   345,   346,   347,
     348,   351,   363,   380,   381,   382,   383,   384,   385
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
  "\"end of file\"", "error", "\"invalid token\"", "LEQ", "GEQ", "NEQ",
  "EQ", "RETURN", "BFCT", "EFCT", "AND", "OR", "ID", "STRING", "TIP",
  "ASSIGN", "BGIN", "END", "CLASS", "ECLASS", "IF", "EIF", "ELSE", "FOR",
  "EFOR", "CONSTANT", "WHILE", "EWHILE", "DO", "EVAL", "TYPEOF", "CHAR",
  "NR", "NR_FLOAT", "'<'", "'>'", "'-'", "'+'", "'/'", "'*'", "';'", "'('",
  "')'", "','", "'['", "']'", "'.'", "$accept", "progr", "rest1", "rest2",
  "sectiunea1", "sectiunea2", "sectiunea3", "declaratieVariabila",
  "declaratieVariabilaClasa", "declaratieFunctie",
  "declaratieFunctieClasa", "lista_param", "param", "clasa",
  "sectiuneaclasa1", "sectiuneaclasa2", "interior_clasa", "lista_id",
  "bloc", "list", "statement", "cond", "cond_expr", "opr", "if", "for",
  "do", "while", "e", "pseudo_e", "lista_apel", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,     4,     5,    34,   127,    25,    44,  -145,     4,  -145,
      59,  -145,    89,    38,  -145,  -145,   114,     4,    70,  -145,
      52,    97,    99,  -145,    -7,  -145,  -145,  -145,   -29,    80,
      85,  -145,   106,   132,   322,  -145,   109,    -6,   119,   128,
      92,  -145,  -145,   126,   139,   163,     4,     4,     4,   330,
     132,   132,   132,   132,     4,   179,   170,   193,   197,   201,
     236,   237,   213,   223,   128,   243,   246,    20,   228,   233,
     265,   235,  -145,  -145,  -145,   371,    93,   239,   240,  -145,
    -145,  -145,  -145,   141,   141,  -145,  -145,  -145,     4,  -145,
      92,   275,   272,   125,  -145,     4,  -145,  -145,   247,   243,
     278,   252,  -145,   144,   126,   264,   286,   176,   158,  -145,
     258,   261,   267,    92,   271,  -145,  -145,  -145,  -145,  -145,
    -145,   199,  -145,   126,  -145,   226,    92,  -145,    11,  -145,
    -145,   273,  -145,  -145,   371,   155,   283,    -8,   176,   274,
      78,   177,  -145,  -145,   158,   337,   202,    58,   202,   327,
    -145,  -145,  -145,  -145,   371,   164,   132,  -145,   238,  -145,
     280,  -145,   305,   132,   126,   281,    95,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,   132,   126,   300,   321,   344,
     158,   158,   158,   158,  -145,   202,    12,   190,   320,   324,
      16,   304,  -145,   351,   132,  -145,  -145,   132,   371,   167,
    -145,   371,   194,   296,   307,  -145,   203,   203,  -145,  -145,
      18,    95,   202,   202,    92,   132,   132,   331,    92,   202,
     340,   356,   371,  -145,  -145,  -145,   126,  -145,  -145,   341,
     250,   371,   361,   132,   277,    21,  -145,   343,   217,  -145,
      92,   202,   366,  -145,   175,  -145,  -145,   289,    66,   202,
    -145,  -145,    92,   108,   312,    92,    92,   328,   301,    92,
    -145,   314,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    32,    11,     0,     1,
       0,     2,     0,     0,     7,     5,     0,     0,     0,    12,
      32,     0,     0,     3,     0,     8,     9,     6,    83,    40,
      42,    84,    38,     0,    36,    34,     0,     0,     0,     0,
       0,    10,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,    21,
       0,     0,     0,     0,    30,    31,     0,     0,     0,     0,
       0,     0,   107,   105,   103,   101,     0,     0,    87,    41,
      43,    39,    82,    79,    78,    81,    80,    37,     0,    23,
       0,     0,     0,    32,    13,     0,    25,    27,     0,    29,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,    47,    48,    49,    50,    45,
      86,     0,    85,     0,    35,     0,     0,    22,     0,    14,
      26,     0,    28,    57,    51,     0,     0,     0,     0,     0,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      46,   108,   106,   104,   102,     0,     0,    16,     0,    20,
       0,    52,     0,     0,     0,     0,     0,    55,    66,    67,
      68,    69,    71,    70,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,    15,    19,     0,    56,     0,
      64,    65,     0,     0,    99,    93,    90,    89,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    58,    98,    97,     0,    60,    61,    62,
       0,    63,     0,     0,     0,     0,    18,     0,     0,    72,
       0,     0,     0,    77,     0,    17,   100,     0,     0,     0,
      76,    73,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,  -145,  -145,  -145,   358,   299,   352,
     -47,   -86,  -145,   347,  -145,   313,  -145,    -3,  -145,   -40,
     -69,  -144,   276,  -132,  -145,  -145,  -145,  -145,   -13,  -134,
    -102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    11,    23,     4,    12,    24,     5,    62,    14,
      63,    58,    59,    26,    64,    65,    66,     7,    42,   234,
      71,   186,   139,   175,   115,   116,   117,   118,   187,   145,
      76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   114,   135,    34,   190,    19,   127,   163,    56,    40,
     179,    22,    43,     1,    35,    44,     6,    45,   101,     8,
      49,   155,   212,   213,     2,    56,   212,   213,   212,   213,
      75,   212,   213,   164,     9,   103,    57,    83,    84,    85,
      86,   210,   160,    79,    80,    81,   206,   207,   208,   209,
     125,    87,   101,   159,   214,   215,   114,    94,   218,    16,
     227,   104,   199,   244,   105,    15,   106,    16,   228,   229,
     188,    20,   189,   149,   202,   235,   212,   213,    27,   215,
     114,   168,   169,   170,   171,   124,   158,    17,    18,   114,
     134,    75,   129,    37,   140,    17,    18,   248,   168,   169,
     170,   171,    36,    21,    67,   253,   252,    22,   154,    38,
      75,    39,   172,   173,    50,    51,    52,    53,   212,   213,
     174,    68,    69,    46,   238,   166,    28,    29,    47,   172,
     173,    50,    51,    52,    53,   120,   121,    82,    28,    72,
      16,    10,    60,   193,    28,    30,    31,    32,   255,    48,
     198,    75,     2,    61,    55,    33,    28,    73,    31,    74,
      37,   114,   201,    75,    31,   114,   128,    33,    17,    18,
     141,    77,   211,    33,   230,    78,    31,   133,   114,    52,
      53,   221,    89,   254,   222,    33,   257,    67,    28,   114,
     142,   143,   114,   168,   169,   170,   171,   161,   121,   144,
     247,    90,   231,   232,    68,    69,   192,   121,    31,   223,
     121,    28,   151,    75,    28,   250,   258,   138,   176,   261,
     242,   177,    88,   178,   172,   173,    50,    51,    52,    53,
     152,    31,   153,   156,    31,   157,   224,   121,    67,    91,
      33,   182,   183,   185,    92,   194,   110,   195,    93,   111,
      67,    95,   112,    96,   113,    68,    69,   100,   110,   246,
     121,   111,    67,    97,   112,   102,   113,    68,    69,   107,
     110,   239,   240,   111,   108,   119,   112,    67,   113,    68,
      69,   123,   109,   126,   122,   110,    56,   130,   111,    67,
     131,   112,   132,   113,    68,    69,   136,   110,   137,   146,
     111,    67,   147,   112,   243,   113,    68,    69,   148,   110,
     251,   150,   111,    67,   128,   112,   167,   113,    68,    69,
     197,   110,   196,   200,   111,   260,    67,   112,   162,   113,
      68,    69,   203,   204,   110,   216,   217,   111,   262,    67,
     112,   225,   113,    68,    69,   219,   233,   110,   226,   236,
     111,   212,   245,   191,   256,   113,    68,    69,    50,    51,
      52,    53,    13,    98,    25,    54,    50,    51,    52,    53,
     259,    41,    82,   180,   181,   182,   183,    99,     0,   184,
     180,   181,   182,   183,     0,     0,   205,    50,    51,    52,
      53,   220,    50,    51,    52,    53,   237,    50,    51,    52,
      53,   241,    50,    51,    52,    53,   249,    50,    51,    52,
      53,     0,     0,     0,   165
};

static const yytype_int16 yycheck[] =
{
      40,    70,   104,    16,   148,     8,    92,    15,    14,    16,
     144,    18,    41,    14,    17,    44,    12,    46,    65,    14,
      33,   123,    10,    11,    25,    14,    10,    11,    10,    11,
      43,    10,    11,    41,     0,    15,    42,    50,    51,    52,
      53,   185,   128,    46,    47,    48,   180,   181,   182,   183,
      90,    54,    99,    42,    42,   187,   125,    60,    42,    15,
      42,    41,   164,    42,    44,    40,    46,    15,   212,   213,
      12,    12,    14,   113,   176,   219,    10,    11,    40,   211,
     149,     3,     4,     5,     6,    88,   126,    43,    44,   158,
     103,   104,    95,    41,   107,    43,    44,   241,     3,     4,
       5,     6,    32,    14,    12,   249,    40,    18,   121,    12,
     123,    12,    34,    35,    36,    37,    38,    39,    10,    11,
      42,    29,    30,    43,   226,   138,    12,    13,    43,    34,
      35,    36,    37,    38,    39,    42,    43,    42,    12,    13,
      15,    14,    14,   156,    12,    31,    32,    33,    40,    43,
     163,   164,    25,    25,    45,    41,    12,    31,    32,    33,
      41,   230,   175,   176,    32,   234,    41,    41,    43,    44,
      12,    32,   185,    41,   214,    12,    32,    33,   247,    38,
      39,   194,    12,   252,   197,    41,   255,    12,    12,   258,
      32,    33,   261,     3,     4,     5,     6,    42,    43,    41,
     240,     8,   215,   216,    29,    30,    42,    43,    32,    42,
      43,    12,    13,   226,    12,    40,   256,    41,    41,   259,
     233,    44,    43,    46,    34,    35,    36,    37,    38,    39,
      31,    32,    33,     7,    32,     9,    42,    43,    12,    42,
      41,    38,    39,    41,    43,     7,    20,     9,    12,    23,
      12,    14,    26,    40,    28,    29,    30,    14,    20,    42,
      43,    23,    12,    40,    26,    19,    28,    29,    30,    41,
      20,    21,    22,    23,    41,    40,    26,    12,    28,    29,
      30,    41,    17,     8,    45,    20,    14,    40,    23,    12,
      12,    26,    40,    28,    29,    30,    32,    20,    12,    41,
      23,    12,    41,    26,    27,    28,    29,    30,    41,    20,
      21,    40,    23,    12,    41,    26,    42,    28,    29,    30,
      15,    20,    42,    42,    23,    24,    12,    26,    45,    28,
      29,    30,    32,    12,    20,    15,    12,    23,    24,    12,
      26,    45,    28,    29,    30,    41,    15,    20,    41,     9,
      23,    10,     9,    26,    42,    28,    29,    30,    36,    37,
      38,    39,     4,    64,    12,    43,    36,    37,    38,    39,
      42,    24,    42,    36,    37,    38,    39,    64,    -1,    42,
      36,    37,    38,    39,    -1,    -1,    42,    36,    37,    38,
      39,    40,    36,    37,    38,    39,    40,    36,    37,    38,
      39,    40,    36,    37,    38,    39,    40,    36,    37,    38,
      39,    -1,    -1,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    25,    48,    51,    54,    12,    64,    14,     0,
      14,    49,    52,    54,    56,    40,    15,    43,    44,    64,
      12,    14,    18,    50,    53,    56,    60,    40,    12,    13,
      31,    32,    33,    41,    75,    64,    32,    41,    12,    12,
      16,    60,    65,    41,    44,    46,    43,    43,    43,    75,
      36,    37,    38,    39,    43,    45,    14,    42,    58,    59,
      14,    25,    55,    57,    61,    62,    63,    12,    29,    30,
      66,    67,    13,    31,    33,    75,    77,    32,    12,    64,
      64,    64,    42,    75,    75,    75,    75,    64,    43,    12,
       8,    42,    43,    12,    64,    14,    40,    40,    55,    62,
      14,    57,    19,    15,    41,    44,    46,    41,    41,    17,
      20,    23,    26,    28,    67,    71,    72,    73,    74,    40,
      42,    43,    45,    41,    64,    66,     8,    58,    41,    64,
      40,    12,    40,    33,    75,    77,    32,    12,    41,    69,
      75,    12,    32,    33,    41,    76,    41,    41,    41,    66,
      40,    13,    31,    33,    75,    77,     7,     9,    66,    42,
      58,    42,    45,    15,    41,    69,    75,    42,     3,     4,
       5,     6,    34,    35,    42,    70,    41,    44,    46,    76,
      36,    37,    38,    39,    42,    41,    68,    75,    12,    14,
      68,    26,    42,    75,     7,     9,    42,    15,    75,    77,
      42,    75,    77,    32,    12,    42,    76,    76,    76,    76,
      68,    75,    10,    11,    42,    70,    15,    12,    42,    41,
      40,    75,    75,    42,    42,    45,    41,    42,    68,    68,
      66,    75,    75,    15,    66,    68,     9,    40,    77,    21,
      22,    40,    75,    27,    42,     9,    42,    66,    68,    40,
      40,    21,    40,    68,    67,    40,    42,    67,    66,    42,
      24,    66,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     3,     1,     2,     1,
       2,     2,     3,     2,     3,     8,     7,    11,    10,     5,
       4,     1,     3,     2,     4,     2,     3,     2,     3,     2,
       1,     1,     1,     4,     3,     6,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     2,     3,     2,     2,     2,
       2,     3,     4,     4,     4,     4,     5,     3,     6,     6,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     6,     8,    13,    12,     7,     6,     3,     3,
       3,     3,     3,     1,     1,     4,     4,     3,     6,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     4,     3,
       6,     1,     3,     1,     3,     1,     3,     1,     3
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
  case 2: /* progr: sectiunea1 rest1  */
#line 55 "compiler.y"
                        {std::cout << "program corect sintactic\n";}
#line 1463 "y.tab.c"
    break;

  case 11: /* declaratieVariabila: TIP lista_id  */
#line 80 "compiler.y"
                                   { addInTable(0, 0, (yyvsp[-1].strval), "tip", 0, 0, "", "", 0, yylineno); }
#line 1469 "y.tab.c"
    break;

  case 12: /* declaratieVariabila: CONSTANT TIP lista_id  */
#line 81 "compiler.y"
                                            {addInTable(1, 0, (yyvsp[-2].strval), "tip", 0, 0, "", "", 0, yylineno);}
#line 1475 "y.tab.c"
    break;

  case 13: /* declaratieVariabilaClasa: TIP lista_id  */
#line 86 "compiler.y"
                                        { addInTable(0, 0, (yyvsp[-1].strval), "tip", 0, 0, "", "", 1, yylineno); }
#line 1481 "y.tab.c"
    break;

  case 14: /* declaratieVariabilaClasa: CONSTANT TIP lista_id  */
#line 87 "compiler.y"
                                                 {addInTable(1, 0, (yyvsp[-2].strval), "tip", 0, 0, "", "", 1, yylineno);}
#line 1487 "y.tab.c"
    break;

  case 15: /* declaratieFunctie: TIP ID '(' lista_param ')' BFCT list EFCT  */
#line 92 "compiler.y"
                                                              { addInTableFunction((yyvsp[-7].strval), (yyvsp[-6].strval), "tip", yylineno, 0, (yyvsp[-4].strval));}
#line 1493 "y.tab.c"
    break;

  case 16: /* declaratieFunctie: TIP ID '(' ')' BFCT list EFCT  */
#line 93 "compiler.y"
                                                  { addInTableFunction((yyvsp[-6].strval), (yyvsp[-5].strval), "tip", yylineno, 0, nullptr);}
#line 1499 "y.tab.c"
    break;

  case 17: /* declaratieFunctie: TIP ID '(' lista_param ')' BFCT list RETURN e ';' EFCT  */
#line 94 "compiler.y"
                                                                           { int val = evalAST((yyvsp[-2].tree), yylineno); addInTableFunction((yyvsp[-10].strval), (yyvsp[-9].strval), "tip", yylineno, 0, (yyvsp[-7].strval));}
#line 1505 "y.tab.c"
    break;

  case 18: /* declaratieFunctie: TIP ID '(' ')' BFCT list RETURN e ';' EFCT  */
#line 95 "compiler.y"
                                                               { int val = evalAST((yyvsp[-2].tree), yylineno); addInTableFunction((yyvsp[-9].strval), (yyvsp[-8].strval), "tip", yylineno, 0, nullptr);}
#line 1511 "y.tab.c"
    break;

  case 19: /* declaratieFunctieClasa: TIP ID '(' lista_param ')'  */
#line 98 "compiler.y"
                                                    { addInTableFunction((yyvsp[-4].strval), (yyvsp[-3].strval), "tip", yylineno, 1, (yyvsp[-1].strval));}
#line 1517 "y.tab.c"
    break;

  case 20: /* declaratieFunctieClasa: TIP ID '(' ')'  */
#line 99 "compiler.y"
                                        { addInTableFunction((yyvsp[-3].strval), (yyvsp[-2].strval), "tip", yylineno, 1, nullptr);}
#line 1523 "y.tab.c"
    break;

  case 21: /* lista_param: param  */
#line 104 "compiler.y"
                    {(yyval.strval) = (yyvsp[0].strval);}
#line 1529 "y.tab.c"
    break;

  case 22: /* lista_param: param ',' lista_param  */
#line 105 "compiler.y"
                                    { (yyval.strval) = ConstrRaspuns((yyvsp[-2].strval), (yyvsp[0].strval), ",");}
#line 1535 "y.tab.c"
    break;

  case 23: /* param: TIP ID  */
#line 110 "compiler.y"
               {
                (yyval.strval) = ConstrRaspuns((yyvsp[-1].strval), (yyvsp[0].strval), " ");
               }
#line 1543 "y.tab.c"
    break;

  case 24: /* clasa: CLASS ID interior_clasa ECLASS  */
#line 117 "compiler.y"
                                       {Clasa((yyvsp[-2].strval));}
#line 1549 "y.tab.c"
    break;

  case 32: /* lista_id: ID  */
#line 140 "compiler.y"
              {addInTable(0, 0, (yyvsp[0].strval), "variabila", 0, 0, "", "", 0, yylineno);}
#line 1555 "y.tab.c"
    break;

  case 33: /* lista_id: ID '[' NR ']'  */
#line 141 "compiler.y"
                         { addInTable(0, (yyvsp[-1].intval), (yyvsp[-3].strval), "variabila", 0, 0, "", "", 0, yylineno);}
#line 1561 "y.tab.c"
    break;

  case 34: /* lista_id: ID ',' lista_id  */
#line 142 "compiler.y"
                           { addInTable(0, 0, (yyvsp[-2].strval), "variabila", 0, 0, "", "", 0, yylineno);}
#line 1567 "y.tab.c"
    break;

  case 35: /* lista_id: ID '[' NR ']' ',' lista_id  */
#line 143 "compiler.y"
                                      { addInTable(0, (yyvsp[-3].intval), (yyvsp[-5].strval), "variabila", 0, 0, "", "", 0, yylineno);}
#line 1573 "y.tab.c"
    break;

  case 36: /* lista_id: ID ASSIGN e  */
#line 144 "compiler.y"
                       { int val = Eval((yyvsp[0].tree), yylineno); addInTable(0, 0, (yyvsp[-2].strval), "variabila", val, 0, "", "", 0, yylineno);}
#line 1579 "y.tab.c"
    break;

  case 37: /* lista_id: ID ASSIGN e ',' lista_id  */
#line 145 "compiler.y"
                                    { int val = Eval((yyvsp[-2].tree), yylineno); addInTable(0, 0, (yyvsp[-4].strval), "variabila", 0, 0, "", "", 0, yylineno);}
#line 1585 "y.tab.c"
    break;

  case 38: /* lista_id: ID ASSIGN NR_FLOAT  */
#line 146 "compiler.y"
                              { addInTable(0, 0, (yyvsp[-2].strval), "variabila", 0, (yyvsp[0].floatval), "", "", 0, yylineno);}
#line 1591 "y.tab.c"
    break;

  case 39: /* lista_id: ID ASSIGN NR_FLOAT ',' lista_id  */
#line 147 "compiler.y"
                                           { addInTable(0, 0, (yyvsp[-4].strval), "variabila", 0, (yyvsp[-2].floatval), "", "", 0, yylineno);}
#line 1597 "y.tab.c"
    break;

  case 40: /* lista_id: ID ASSIGN STRING  */
#line 148 "compiler.y"
                            { addInTable(0, 0, (yyvsp[-2].strval), "variabila", 0, 0, "", (yyvsp[0].strval), 0, yylineno);}
#line 1603 "y.tab.c"
    break;

  case 41: /* lista_id: ID ASSIGN STRING ',' lista_id  */
#line 149 "compiler.y"
                                         { addInTable(0, 0, (yyvsp[-4].strval), "variabila", 0, 0, "", (yyvsp[-2].strval), 0, yylineno);}
#line 1609 "y.tab.c"
    break;

  case 42: /* lista_id: ID ASSIGN CHAR  */
#line 150 "compiler.y"
                          { addInTable(0, 0, (yyvsp[-2].strval), "variabila", 0, 0, (yyvsp[0].strval), "", 0, yylineno);}
#line 1615 "y.tab.c"
    break;

  case 43: /* lista_id: ID ASSIGN CHAR ',' lista_id  */
#line 151 "compiler.y"
                                       { addInTable(0, 0, (yyvsp[-4].strval), "variabila", 0, 0, (yyvsp[-2].strval), "", 0, yylineno);}
#line 1621 "y.tab.c"
    break;

  case 51: /* statement: ID ASSIGN e  */
#line 177 "compiler.y"
                        { 
                            Verif((yyvsp[-2].strval), yylineno, 0);
                            if(strcmp(getIdType((yyvsp[-2].strval)), "int"))
                            {
                                std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                print_error();
                                std::exit(0);
                            }
                            int val = Eval((yyvsp[0].tree), yylineno);
                            actualizareTabel((yyvsp[-2].strval), "int", val, yylineno, 0, "");
                        }
#line 1637 "y.tab.c"
    break;

  case 52: /* statement: ID '(' lista_apel ')'  */
#line 188 "compiler.y"
                                 {VerifFct((yyvsp[-3].strval), (yyvsp[-1].strval), yylineno);}
#line 1643 "y.tab.c"
    break;

  case 53: /* statement: TYPEOF '(' pseudo_e ')'  */
#line 189 "compiler.y"
                                   {std::cout << (yyvsp[-1].strval) << "\n";}
#line 1649 "y.tab.c"
    break;

  case 54: /* statement: EVAL '(' e ')'  */
#line 190 "compiler.y"
                          {std::cout << Eval((yyvsp[-1].tree), yylineno) << "\n";}
#line 1655 "y.tab.c"
    break;

  case 55: /* statement: EVAL '(' cond_expr ')'  */
#line 191 "compiler.y"
                                  {
              if((yyvsp[-1].intval) == 1) std::cout<<"true"<<"\n";
              else std::cout<<"false"<<"\n";
         }
#line 1664 "y.tab.c"
    break;

  case 56: /* statement: ID '.' ID ASSIGN e  */
#line 195 "compiler.y"
                              { 
                                std::snprintf(buff,100,"%s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval));
                                Verif(buff, yylineno, 0);
                                if(strcmp(getIdType((yyvsp[-4].strval)), "int"))
                                {
                                    std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                    print_error();
                                    std::exit(0);
                                }
                                int val = Eval((yyvsp[0].tree), yylineno);
                                actualizareTabel(buff, "int", val, yylineno, 0, "");
                              }
#line 1681 "y.tab.c"
    break;

  case 57: /* statement: ID ASSIGN NR_FLOAT  */
#line 207 "compiler.y"
                              {
                                Verif((yyvsp[-2].strval), yylineno, 0);
                                if(strcmp(getIdType((yyvsp[-2].strval)), "float"))
                                {
                                    std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                    print_error();
                                    std::exit(0);
                                }
                                actualizareTabel((yyvsp[-2].strval), "float", 0, yylineno, (yyvsp[0].floatval), "");
                              }
#line 1696 "y.tab.c"
    break;

  case 58: /* statement: ID '.' ID '(' lista_apel ')'  */
#line 217 "compiler.y"
                                        {
                                            std::snprintf(buff,100,"%s.%s", (yyvsp[-5].strval), (yyvsp[-3].strval));
                                            VerifFct(buff, (yyvsp[-1].strval), yylineno);

                                        }
#line 1706 "y.tab.c"
    break;

  case 59: /* statement: ID '[' NR ']' ASSIGN e  */
#line 222 "compiler.y"
                                  { Verif((yyvsp[-5].strval), yylineno, (yyvsp[-3].intval));}
#line 1712 "y.tab.c"
    break;

  case 60: /* cond: '(' cond ')'  */
#line 227 "compiler.y"
                    {(yyval.intval) = (yyvsp[-1].intval);}
#line 1718 "y.tab.c"
    break;

  case 61: /* cond: cond AND cond  */
#line 228 "compiler.y"
                     { int rez1=(yyvsp[-2].intval); int rez2=(yyvsp[0].intval); 
                       (yyval.intval)=(rez1 && rez2);
                     }
#line 1726 "y.tab.c"
    break;

  case 62: /* cond: cond OR cond  */
#line 231 "compiler.y"
                    { int rez1=(yyvsp[-2].intval); int rez2=(yyvsp[0].intval);
                      (yyval.intval)=(rez1 || rez2);
                    }
#line 1734 "y.tab.c"
    break;

  case 63: /* cond: e opr e  */
#line 234 "compiler.y"
               { 
                int rez1=evalAST((yyvsp[-2].tree), yylineno); int rez2=evalAST((yyvsp[0].tree), yylineno);
                if (strcmp((yyvsp[-1].strval), "<=")) (yyval.intval)=(rez1 <= rez2);
                if (strcmp((yyvsp[-1].strval), ">=")) (yyval.intval)=(rez1 >= rez2);
                if (strcmp((yyvsp[-1].strval), "!=")) (yyval.intval)=(rez1 != rez2);
                if (strcmp((yyvsp[-1].strval), "==")) (yyval.intval)=(rez1 == rez2);
                if (strcmp((yyvsp[-1].strval), ">")) (yyval.intval)=(rez1 > rez2);
                if (strcmp((yyvsp[-1].strval), "<")) (yyval.intval)=(rez1 < rez2);
                }
#line 1748 "y.tab.c"
    break;

  case 64: /* cond_expr: '(' cond_expr ')'  */
#line 245 "compiler.y"
                              {(yyval.intval) = (yyvsp[-1].intval);}
#line 1754 "y.tab.c"
    break;

  case 65: /* cond_expr: e opr e  */
#line 246 "compiler.y"
                    {
                int rez1 = evalAST((yyvsp[-2].tree), yylineno);
                int rez2 = evalAST((yyvsp[0].tree), yylineno);
                if (strcmp((yyvsp[-1].strval), "<=")) (yyval.intval) = (rez1 <= rez2);
                if (strcmp((yyvsp[-1].strval), ">=")) (yyval.intval) = (rez1 >= rez2);
                if (strcmp((yyvsp[-1].strval), "!=")) (yyval.intval) = (rez1 != rez2);
                if (strcmp((yyvsp[-1].strval), "==")) (yyval.intval) = (rez1 == rez2);
                if (strcmp((yyvsp[-1].strval), ">")) (yyval.intval) = (rez1 > rez2);
                if (strcmp((yyvsp[-1].strval), "<")) (yyval.intval) = (rez1 < rez2);
            }
#line 1769 "y.tab.c"
    break;

  case 66: /* opr: LEQ  */
#line 258 "compiler.y"
          {(yyval.strval) = (yyvsp[0].strval);}
#line 1775 "y.tab.c"
    break;

  case 67: /* opr: GEQ  */
#line 259 "compiler.y"
          {(yyval.strval) = (yyvsp[0].strval);}
#line 1781 "y.tab.c"
    break;

  case 68: /* opr: NEQ  */
#line 260 "compiler.y"
          {(yyval.strval) = (yyvsp[0].strval);}
#line 1787 "y.tab.c"
    break;

  case 69: /* opr: EQ  */
#line 261 "compiler.y"
          {(yyval.strval) = (yyvsp[0].strval);}
#line 1793 "y.tab.c"
    break;

  case 70: /* opr: '>'  */
#line 262 "compiler.y"
          {(yyval.strval) = const_cast<char*>(">");}
#line 1799 "y.tab.c"
    break;

  case 71: /* opr: '<'  */
#line 263 "compiler.y"
          {(yyval.strval) = const_cast<char*>("<");}
#line 1805 "y.tab.c"
    break;

  case 78: /* e: e '+' e  */
#line 286 "compiler.y"
            { (yyval.tree) = new AST("+", (yyvsp[-2].tree), (yyvsp[0].tree), OPERATOR); }
#line 1811 "y.tab.c"
    break;

  case 79: /* e: e '-' e  */
#line 287 "compiler.y"
            { (yyval.tree) = new AST("-", (yyvsp[-2].tree), (yyvsp[0].tree), OPERATOR); }
#line 1817 "y.tab.c"
    break;

  case 80: /* e: e '*' e  */
#line 288 "compiler.y"
            { (yyval.tree) = new AST("*", (yyvsp[-2].tree), (yyvsp[0].tree), OPERATOR); }
#line 1823 "y.tab.c"
    break;

  case 81: /* e: e '/' e  */
#line 289 "compiler.y"
            { (yyval.tree) = new AST("/", (yyvsp[-2].tree), (yyvsp[0].tree), OPERATOR); }
#line 1829 "y.tab.c"
    break;

  case 82: /* e: '(' e ')'  */
#line 290 "compiler.y"
              { (yyval.tree) = (yyvsp[-1].tree); }
#line 1835 "y.tab.c"
    break;

  case 83: /* e: ID  */
#line 291 "compiler.y"
       { Verif((yyvsp[0].strval), yylineno, 0); (yyval.tree) = new AST((yyvsp[0].strval), nullptr, nullptr, IDENTIFICATOR);}
#line 1841 "y.tab.c"
    break;

  case 84: /* e: NR  */
#line 292 "compiler.y"
       { char nr[100]; memset(nr, 0, 100); std::sprintf(nr, "%d", (yyvsp[0].intval)); (yyval.tree) = new AST(nr, nullptr, nullptr, NUMAR); }
#line 1847 "y.tab.c"
    break;

  case 85: /* e: ID '[' NR ']'  */
#line 293 "compiler.y"
                  {Verif((yyvsp[-3].strval), yylineno, 1); int val = getArrVal((yyvsp[-3].strval), (yyvsp[-1].intval), yylineno); char nr[100]; memset(nr, 0, 100); std::sprintf(nr, "%d", val); (yyval.tree) = new AST(nr, nullptr, nullptr, NUMAR); }
#line 1853 "y.tab.c"
    break;

  case 86: /* e: ID '(' lista_apel ')'  */
#line 294 "compiler.y"
                          { VerifFct((yyvsp[-3].strval), (yyvsp[-1].strval), yylineno);
                            (yyval.tree) = new AST("0", nullptr, nullptr, NUMAR);
                          }
#line 1861 "y.tab.c"
    break;

  case 87: /* e: ID '.' ID  */
#line 297 "compiler.y"
              { std::snprintf(buff,100,"%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); Verif(buff, yylineno, 0);  (yyval.tree) = new AST((yyvsp[-2].strval), nullptr, nullptr, IDENTIFICATOR);}
#line 1867 "y.tab.c"
    break;

  case 88: /* e: ID '.' ID '(' lista_apel ')'  */
#line 298 "compiler.y"
                                 { std::snprintf(buff,100,"%s.%s", (yyvsp[-5].strval), (yyvsp[-3].strval)); VerifFct(buff, (yyvsp[-3].strval), yylineno); (yyval.tree) = new AST("0", nullptr, nullptr, NUMAR);}
#line 1873 "y.tab.c"
    break;

  case 89: /* pseudo_e: pseudo_e '+' pseudo_e  */
#line 305 "compiler.y"
                                 {
                                    if(strcmp((yyvsp[-2].strval), (yyvsp[0].strval)))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    (yyval.strval) = (yyvsp[-2].strval);
                                 }
#line 1887 "y.tab.c"
    break;

  case 90: /* pseudo_e: pseudo_e '-' pseudo_e  */
#line 314 "compiler.y"
                                 {
                                    if(strcmp((yyvsp[-2].strval), (yyvsp[0].strval)))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    (yyval.strval) = (yyvsp[-2].strval);
                                 }
#line 1901 "y.tab.c"
    break;

  case 91: /* pseudo_e: pseudo_e '/' pseudo_e  */
#line 323 "compiler.y"
                                 {
                                    if(strcmp((yyvsp[-2].strval), (yyvsp[0].strval)))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    (yyval.strval) = (yyvsp[-2].strval);
                                 }
#line 1915 "y.tab.c"
    break;

  case 92: /* pseudo_e: pseudo_e '*' pseudo_e  */
#line 332 "compiler.y"
                                 {
                                    if(strcmp((yyvsp[-2].strval), (yyvsp[0].strval)))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    (yyval.strval) = (yyvsp[-2].strval);
                                 }
#line 1929 "y.tab.c"
    break;

  case 93: /* pseudo_e: '(' pseudo_e ')'  */
#line 341 "compiler.y"
                            { (yyval.strval) = (yyvsp[-1].strval); }
#line 1935 "y.tab.c"
    break;

  case 94: /* pseudo_e: ID  */
#line 342 "compiler.y"
              {Verif((yyvsp[0].strval), yylineno, 0); (yyval.strval) = getIdType((yyvsp[0].strval));}
#line 1941 "y.tab.c"
    break;

  case 95: /* pseudo_e: NR  */
#line 343 "compiler.y"
              {(yyval.strval) = const_cast<char*>("int");}
#line 1947 "y.tab.c"
    break;

  case 96: /* pseudo_e: NR_FLOAT  */
#line 344 "compiler.y"
                    {(yyval.strval) = const_cast<char*>("float");}
#line 1953 "y.tab.c"
    break;

  case 97: /* pseudo_e: ID '[' NR ']'  */
#line 345 "compiler.y"
                         {Verif((yyvsp[-3].strval), yylineno, 1); (yyval.strval) = getIdType((yyvsp[-3].strval));}
#line 1959 "y.tab.c"
    break;

  case 98: /* pseudo_e: ID '(' lista_apel ')'  */
#line 346 "compiler.y"
                                 { VerifFct((yyvsp[-3].strval), (yyvsp[-1].strval), yylineno); (yyval.strval) = FctRetType((yyvsp[-3].strval));}
#line 1965 "y.tab.c"
    break;

  case 99: /* pseudo_e: ID '.' ID  */
#line 347 "compiler.y"
                     {std::snprintf(buff,100,"%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); Verif((yyvsp[-2].strval), yylineno, 1); (yyval.strval) = getIdType(buff);}
#line 1971 "y.tab.c"
    break;

  case 100: /* pseudo_e: ID '.' ID '(' lista_apel ')'  */
#line 348 "compiler.y"
                                        { std::snprintf(buff,100,"%s.%s", (yyvsp[-5].strval), (yyvsp[-3].strval)); VerifFct(buff, (yyvsp[-1].strval), yylineno); (yyval.strval) = FctRetType(buff);}
#line 1977 "y.tab.c"
    break;

  case 101: /* lista_apel: e  */
#line 351 "compiler.y"
               {
                AST* tree = (yyvsp[0].tree);
                if(tree->st == NULL && tree->dr == NULL)
                {
                    if(tree->nodeType == IDENTIFICATOR)
                        (yyval.strval) = getIdType(tree->nume);
                    else
                        (yyval.strval) = const_cast<char*>("int");
                }
                else
                    (yyval.strval) = const_cast<char*>("int");
            }
#line 1994 "y.tab.c"
    break;

  case 102: /* lista_apel: lista_apel ',' e  */
#line 363 "compiler.y"
                              {
                    AST* tree = (yyvsp[0].tree);
                    char tip[20];
                        if(tree->st == NULL && tree->dr == NULL)
                        {
                            if(tree->nodeType == IDENTIFICATOR)
                                strcpy(tip, getIdType(tree->nume));
                            else
                                strcpy(tip, "int");
                        }
                        else
                            strcpy(tip, "int");
                        strcpy(buff, (yyvsp[-2].strval));
                        strcat(buff, ",");
                        strcat(buff, tip);
                        (yyval.strval) = buff;
                }
#line 2016 "y.tab.c"
    break;

  case 103: /* lista_apel: NR_FLOAT  */
#line 380 "compiler.y"
                      {(yyval.strval) = const_cast<char*>("float");}
#line 2022 "y.tab.c"
    break;

  case 104: /* lista_apel: lista_apel ',' NR_FLOAT  */
#line 381 "compiler.y"
                                     { std::snprintf(buff,100,"%s,float",(yyvsp[-2].strval)); (yyval.strval) = buff;}
#line 2028 "y.tab.c"
    break;

  case 105: /* lista_apel: CHAR  */
#line 382 "compiler.y"
                  {(yyval.strval) = const_cast<char*>("char");}
#line 2034 "y.tab.c"
    break;

  case 106: /* lista_apel: lista_apel ',' CHAR  */
#line 383 "compiler.y"
                                 {std::snprintf(buff,100,"%s,char",(yyvsp[-2].strval)); (yyval.strval) = buff;}
#line 2040 "y.tab.c"
    break;

  case 107: /* lista_apel: STRING  */
#line 384 "compiler.y"
                    {(yyval.strval) = const_cast<char*>("string");}
#line 2046 "y.tab.c"
    break;

  case 108: /* lista_apel: lista_apel ',' STRING  */
#line 385 "compiler.y"
                                   {std::snprintf(buff,100,"%s,string",(yyvsp[-2].strval)); (yyval.strval) = buff;}
#line 2052 "y.tab.c"
    break;


#line 2056 "y.tab.c"

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

#line 388 "compiler.y"


int yyerror(const char * s)
{
    std::cout<<"eroare: " << s << " la linia: " << yylineno <<"\n";
    return 0;
}


int main(int argc, char** argv) 
{
    std::ofstream fd("symbol_table.txt", std::ofstream::out | std::ofstream::trunc);/*pt tabela de simboluri*/
    
    if (!fd.is_open()) {
        std::cout << "Nu se poate deschide fisierul.\n";
        return 1;
    }

    initialize();/*init tabela cu val 0/nullptr*/

    yyin = fopen(argv[1], "r");
    
    yyparse();/*generează un arbore de analiză sintactică, în care nodurile arborelui corespund diferitelor producții ale gramaticii */
    printVars(fd);
    printFunctions(fd);

    return 0;
}
