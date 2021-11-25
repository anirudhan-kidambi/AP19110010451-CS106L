/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    NUM = 259,
    HEADER = 260,
    REAL = 261,
    CHARVALUE = 262,
    CHAR = 263,
    INT = 264,
    FLOAT = 265,
    DOUBLE = 266,
    VOID = 267,
    IF = 268,
    ELSE = 269,
    SWITCH = 270,
    BREAK = 271,
    WHILE = 272,
    CASE = 273,
    DEFAULT = 274,
    RETURN = 275,
    ADD = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    INC = 280,
    DEC = 281,
    EQ = 282,
    LE = 283,
    GE = 284,
    AND = 285,
    OR = 286,
    XOR = 287,
    ASSIGN = 288,
    L = 289,
    G = 290,
    NEQ = 291,
    SEMICOLON = 292,
    COMMA = 293,
    OP = 294,
    CP = 295,
    OB = 296,
    CB = 297
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define NUM 259
#define HEADER 260
#define REAL 261
#define CHARVALUE 262
#define CHAR 263
#define INT 264
#define FLOAT 265
#define DOUBLE 266
#define VOID 267
#define IF 268
#define ELSE 269
#define SWITCH 270
#define BREAK 271
#define WHILE 272
#define CASE 273
#define DEFAULT 274
#define RETURN 275
#define ADD 276
#define SUB 277
#define MUL 278
#define DIV 279
#define INC 280
#define DEC 281
#define EQ 282
#define LE 283
#define GE 284
#define AND 285
#define OR 286
#define XOR 287
#define ASSIGN 288
#define L 289
#define G 290
#define NEQ 291
#define SEMICOLON 292
#define COMMA 293
#define OP 294
#define CP 295
#define OB 296
#define CB 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
