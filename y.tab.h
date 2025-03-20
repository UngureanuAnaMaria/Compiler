/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 140 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
