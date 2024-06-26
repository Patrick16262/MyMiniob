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

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
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
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    INDEX = 263,                   /* INDEX  */
    CALC = 264,                    /* CALC  */
    SELECT = 265,                  /* SELECT  */
    DESC = 266,                    /* DESC  */
    ASC = 267,                     /* ASC  */
    SHOW = 268,                    /* SHOW  */
    SYNC = 269,                    /* SYNC  */
    INSERT = 270,                  /* INSERT  */
    DELETE = 271,                  /* DELETE  */
    UPDATE = 272,                  /* UPDATE  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    COMMA = 275,                   /* COMMA  */
    TRX_BEGIN = 276,               /* TRX_BEGIN  */
    TRX_COMMIT = 277,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 278,            /* TRX_ROLLBACK  */
    INT_T = 279,                   /* INT_T  */
    STRING_T = 280,                /* STRING_T  */
    FLOAT_T = 281,                 /* FLOAT_T  */
    DATE_T = 282,                  /* DATE_T  */
    TEXT_T = 283,                  /* TEXT_T  */
    THE_NULL = 284,                /* THE_NULL  */
    HELP = 285,                    /* HELP  */
    EXIT = 286,                    /* EXIT  */
    DOT = 287,                     /* DOT  */
    INTO = 288,                    /* INTO  */
    VALUES = 289,                  /* VALUES  */
    FROM = 290,                    /* FROM  */
    WHERE = 291,                   /* WHERE  */
    SET = 292,                     /* SET  */
    ON = 293,                      /* ON  */
    LOAD = 294,                    /* LOAD  */
    DATA = 295,                    /* DATA  */
    INFILE = 296,                  /* INFILE  */
    EXPLAIN = 297,                 /* EXPLAIN  */
    GROUP = 298,                   /* GROUP  */
    BY = 299,                      /* BY  */
    ORDER = 300,                   /* ORDER  */
    HAVING = 301,                  /* HAVING  */
    AS = 302,                      /* AS  */
    JOIN = 303,                    /* JOIN  */
    EXISTS = 304,                  /* EXISTS  */
    IN = 305,                      /* IN  */
    INNER = 306,                   /* INNER  */
    UNIQUE = 307,                  /* UNIQUE  */
    NUMBER = 308,                  /* NUMBER  */
    FLOAT = 309,                   /* FLOAT  */
    ID = 310,                      /* ID  */
    SSS = 311,                     /* SSS  */
    IS = 312,                      /* IS  */
    LIKE = 313,                    /* LIKE  */
    OR = 314,                      /* OR  */
    AND = 315,                     /* AND  */
    NOT = 316,                     /* NOT  */
    LT = 317,                      /* LT  */
    GT = 318,                      /* GT  */
    LE = 319,                      /* LE  */
    GE = 320,                      /* GE  */
    EQ = 321,                      /* EQ  */
    NE = 322,                      /* NE  */
    ADD = 323,                     /* ADD  */
    SUB = 324,                     /* SUB  */
    STAR = 325,                    /* STAR  */
    DIV = 326,                     /* DIV  */
    UMINUS = 327                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 108 "yacc_sql.y"

  ParsedSqlNode *                           sql_node;
  Value *                                   value;
  RelAttrSqlNode *                          rel_attr;
  SubqueryExpressionSqlNode *               subquery;
  std::vector<AttrInfoSqlNode> *            attr_infos;
  AttrInfoSqlNode *                         attr_info;
  ExpressionSqlNode *                       expression;
  std::vector<ExpressionSqlNode *> *        expression_list;
  std::vector<Value> *                      value_list;
  std::vector<std::string> *                string_list;
  char *                                    string;
  int                                       number;
  float                                     floats;
  bool                                      booleans;
  ArithmeticType                            math_type;
  TableReferenceSqlNode *                   table_reference;
  std::vector<TableReferenceSqlNode *> *          table_reference_list;
  TableReferenceSqlNode *                         table_factor_node;
  ExpressionWithOrderSqlNode *                    order_by_node;
  std::vector<ExpressionWithOrderSqlNode *> *     order_by_list;
  ExpressionWithAliasSqlNode *                    expression_with_alias;
  std::vector<ExpressionWithAliasSqlNode *> *     expression_with_alias_list;
  UpdateAssignmentSqlNode *                       update_asgn_factor;
  std::vector<UpdateAssignmentSqlNode *> *        update_asgn_list;
  OrderType                                       order_type;

#line 164 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
