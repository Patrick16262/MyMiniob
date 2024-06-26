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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


  /**
    * @file yacc_sql.y
    * @brief SQL语法解析器的yacc文件
    * 
    * 注意：vscode插件对.y静态语法分析文件的支持不太好，编程时要谨慎
    *
    * @version 1.0
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}


#line 112 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_CALC = 9,                       /* CALC  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_DESC = 11,                      /* DESC  */
  YYSYMBOL_ASC = 12,                       /* ASC  */
  YYSYMBOL_SHOW = 13,                      /* SHOW  */
  YYSYMBOL_SYNC = 14,                      /* SYNC  */
  YYSYMBOL_INSERT = 15,                    /* INSERT  */
  YYSYMBOL_DELETE = 16,                    /* DELETE  */
  YYSYMBOL_UPDATE = 17,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 21,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 22,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 23,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 24,                     /* INT_T  */
  YYSYMBOL_STRING_T = 25,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 26,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 27,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 28,                    /* TEXT_T  */
  YYSYMBOL_THE_NULL = 29,                  /* THE_NULL  */
  YYSYMBOL_HELP = 30,                      /* HELP  */
  YYSYMBOL_EXIT = 31,                      /* EXIT  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_INTO = 33,                      /* INTO  */
  YYSYMBOL_VALUES = 34,                    /* VALUES  */
  YYSYMBOL_FROM = 35,                      /* FROM  */
  YYSYMBOL_WHERE = 36,                     /* WHERE  */
  YYSYMBOL_SET = 37,                       /* SET  */
  YYSYMBOL_ON = 38,                        /* ON  */
  YYSYMBOL_LOAD = 39,                      /* LOAD  */
  YYSYMBOL_DATA = 40,                      /* DATA  */
  YYSYMBOL_INFILE = 41,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 42,                   /* EXPLAIN  */
  YYSYMBOL_GROUP = 43,                     /* GROUP  */
  YYSYMBOL_BY = 44,                        /* BY  */
  YYSYMBOL_ORDER = 45,                     /* ORDER  */
  YYSYMBOL_HAVING = 46,                    /* HAVING  */
  YYSYMBOL_AS = 47,                        /* AS  */
  YYSYMBOL_JOIN = 48,                      /* JOIN  */
  YYSYMBOL_EXISTS = 49,                    /* EXISTS  */
  YYSYMBOL_IN = 50,                        /* IN  */
  YYSYMBOL_INNER = 51,                     /* INNER  */
  YYSYMBOL_UNIQUE = 52,                    /* UNIQUE  */
  YYSYMBOL_NUMBER = 53,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 54,                     /* FLOAT  */
  YYSYMBOL_ID = 55,                        /* ID  */
  YYSYMBOL_SSS = 56,                       /* SSS  */
  YYSYMBOL_IS = 57,                        /* IS  */
  YYSYMBOL_LIKE = 58,                      /* LIKE  */
  YYSYMBOL_OR = 59,                        /* OR  */
  YYSYMBOL_AND = 60,                       /* AND  */
  YYSYMBOL_NOT = 61,                       /* NOT  */
  YYSYMBOL_LT = 62,                        /* LT  */
  YYSYMBOL_GT = 63,                        /* GT  */
  YYSYMBOL_LE = 64,                        /* LE  */
  YYSYMBOL_GE = 65,                        /* GE  */
  YYSYMBOL_EQ = 66,                        /* EQ  */
  YYSYMBOL_NE = 67,                        /* NE  */
  YYSYMBOL_ADD = 68,                       /* ADD  */
  YYSYMBOL_SUB = 69,                       /* SUB  */
  YYSYMBOL_STAR = 70,                      /* STAR  */
  YYSYMBOL_DIV = 71,                       /* DIV  */
  YYSYMBOL_UMINUS = 72,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_commands = 74,                  /* commands  */
  YYSYMBOL_command_wrapper = 75,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 76,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 77,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 78,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 79,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 80,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 81,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 82,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 83,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 84,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 85,         /* create_index_stmt  */
  YYSYMBOL_opt_unique = 86,                /* opt_unique  */
  YYSYMBOL_index_col_list = 87,            /* index_col_list  */
  YYSYMBOL_drop_index_stmt = 88,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 89,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 90,             /* attr_def_list  */
  YYSYMBOL_attr_def = 91,                  /* attr_def  */
  YYSYMBOL_number = 92,                    /* number  */
  YYSYMBOL_type = 93,                      /* type  */
  YYSYMBOL_insert_stmt = 94,               /* insert_stmt  */
  YYSYMBOL_value_list = 95,                /* value_list  */
  YYSYMBOL_value = 96,                     /* value  */
  YYSYMBOL_delete_stmt = 97,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 98,               /* update_stmt  */
  YYSYMBOL_update_asgn_factor = 99,        /* update_asgn_factor  */
  YYSYMBOL_update_asgn_list = 100,         /* update_asgn_list  */
  YYSYMBOL_select_stmt = 101,              /* select_stmt  */
  YYSYMBOL_select_with_parenthesis = 102,  /* select_with_parenthesis  */
  YYSYMBOL_expression_list = 103,          /* expression_list  */
  YYSYMBOL_expression = 104,               /* expression  */
  YYSYMBOL_rel_attr = 105,                 /* rel_attr  */
  YYSYMBOL_opt_where = 106,                /* opt_where  */
  YYSYMBOL_table_factor = 107,             /* table_factor  */
  YYSYMBOL_opt_table_refs = 108,           /* opt_table_refs  */
  YYSYMBOL_table_ref = 109,                /* table_ref  */
  YYSYMBOL_opt_join_condition = 110,       /* opt_join_condition  */
  YYSYMBOL_table_ref_list = 111,           /* table_ref_list  */
  YYSYMBOL_expression_with_order = 112,    /* expression_with_order  */
  YYSYMBOL_expression_with_order_list = 113, /* expression_with_order_list  */
  YYSYMBOL_query_expression = 114,         /* query_expression  */
  YYSYMBOL_query_expression_list = 115,    /* query_expression_list  */
  YYSYMBOL_opt_order_by = 116,             /* opt_order_by  */
  YYSYMBOL_opt_group_by = 117,             /* opt_group_by  */
  YYSYMBOL_opt_order_type = 118,           /* opt_order_type  */
  YYSYMBOL_opt_having = 119,               /* opt_having  */
  YYSYMBOL_load_data_stmt = 120,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 121,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 122,        /* set_variable_stmt  */
  YYSYMBOL_opt_inner = 123,                /* opt_inner  */
  YYSYMBOL_opt_semicolon = 124,            /* opt_semicolon  */
  YYSYMBOL_opt_not = 125,                  /* opt_not  */
  YYSYMBOL_opt_alias = 126,                /* opt_alias  */
  YYSYMBOL_opt_as = 127,                   /* opt_as  */
  YYSYMBOL_opt_nullable = 128              /* opt_nullable  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   209,   209,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   239,   245,   250,   256,   262,   268,   274,   281,
     287,   295,   309,   310,   314,   319,   330,   341,   362,   365,
     378,   387,   399,   403,   404,   405,   406,   407,   411,   428,
     431,   443,   447,   451,   457,   464,   476,   489,   499,   504,
     517,   543,   553,   560,   565,   577,   586,   595,   604,   613,
     618,   629,   638,   647,   656,   665,   674,   683,   692,   701,
     704,   722,   729,   736,   752,   767,   781,   789,   797,   808,
     814,   821,   826,   837,   840,   845,   852,   861,   864,   869,
     877,   893,   896,   902,   907,   917,   926,   931,   941,   953,
     958,   969,   972,   979,   982,   989,   992,   996,  1003,  1006,
    1012,  1025,  1033,  1043,  1044,  1047,  1048,  1052,  1053,  1057,
    1058,  1063,  1064,  1067,  1068,  1069
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "DESC", "ASC",
  "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "THE_NULL", "HELP", "EXIT", "DOT", "INTO",
  "VALUES", "FROM", "WHERE", "SET", "ON", "LOAD", "DATA", "INFILE",
  "EXPLAIN", "GROUP", "BY", "ORDER", "HAVING", "AS", "JOIN", "EXISTS",
  "IN", "INNER", "UNIQUE", "NUMBER", "FLOAT", "ID", "SSS", "IS", "LIKE",
  "OR", "AND", "NOT", "LT", "GT", "LE", "GE", "EQ", "NE", "ADD", "SUB",
  "STAR", "DIV", "UMINUS", "$accept", "commands", "command_wrapper",
  "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt",
  "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "create_index_stmt", "opt_unique", "index_col_list",
  "drop_index_stmt", "create_table_stmt", "attr_def_list", "attr_def",
  "number", "type", "insert_stmt", "value_list", "value", "delete_stmt",
  "update_stmt", "update_asgn_factor", "update_asgn_list", "select_stmt",
  "select_with_parenthesis", "expression_list", "expression", "rel_attr",
  "opt_where", "table_factor", "opt_table_refs", "table_ref",
  "opt_join_condition", "table_ref_list", "expression_with_order",
  "expression_with_order_list", "query_expression",
  "query_expression_list", "opt_order_by", "opt_group_by",
  "opt_order_type", "opt_having", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_inner", "opt_semicolon", "opt_not",
  "opt_alias", "opt_as", "opt_nullable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     183,     4,    55,    99,    99,   -24,    37,  -144,    15,    30,
      11,  -144,  -144,  -144,  -144,  -144,    23,    32,   183,    79,
      77,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      26,  -144,    74,    31,    43,    -2,  -144,    65,  -144,  -144,
      -4,  -144,    99,    99,  -144,  -144,  -144,   176,  -144,    98,
    -144,    64,  -144,  -144,    66,    67,    82,    54,    83,  -144,
    -144,  -144,  -144,   105,    70,  -144,    88,   108,    45,    16,
    -144,    99,   -37,   221,  -144,  -144,    68,    99,    99,  -144,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     -28,  -144,    75,    99,   -12,    95,   100,    95,    80,    17,
      76,    81,   103,    87,  -144,  -144,   118,   113,  -144,  -144,
     109,   210,   232,     6,     6,     6,     6,     6,     6,   -51,
     -51,  -144,  -144,   125,    89,  -144,  -144,    16,  -144,   -23,
       9,  -144,    99,   101,   128,  -144,    84,   127,    95,  -144,
     116,    10,   131,   102,  -144,  -144,    99,  -144,    -2,  -144,
    -144,   137,  -144,   -12,  -144,   110,   198,   115,   119,    17,
      99,    80,  -144,   155,  -144,  -144,  -144,  -144,  -144,    -6,
      81,   143,   146,  -144,   147,  -144,  -144,   -12,    99,    99,
     140,   169,   198,  -144,   135,   138,  -144,   166,  -144,   131,
    -144,   148,  -144,   -23,  -144,   198,   157,  -144,    17,   188,
    -144,  -144,   189,  -144,  -144,   182,   190,   172,    28,   169,
    -144,   -20,   148,  -144,    99,  -144,  -144,  -144,   191,  -144,
      99,  -144,  -144,  -144,   198,    28,   198,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    32,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,    27,    23,    22,     0,     0,     0,     0,
     125,    21,    20,    13,    14,    15,    16,     8,     9,    10,
      11,    12,     7,     4,     6,     5,     3,    17,    18,    19,
       0,    33,     0,     0,     0,     0,    54,     0,    51,    52,
      89,    53,     0,     0,    92,    87,    69,   129,    88,   109,
      61,    97,    30,    29,     0,     0,     0,     0,     0,   121,
       1,   126,     2,     0,     0,    28,     0,     0,   127,     0,
      82,     0,     0,    81,    70,   132,   127,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,    93,     0,    93,     0,     0,
       0,     0,     0,     0,    62,    79,     0,    63,    90,    91,
       0,    78,    77,    72,    73,    74,    75,    71,    76,    65,
      66,    67,    68,     0,     0,   130,   110,     0,    95,   129,
     103,    98,     0,   113,     0,    55,     0,    58,    93,   122,
       0,     0,    38,     0,    36,    86,     0,    85,     0,    84,
      80,     0,    99,     0,   124,     0,    94,     0,   118,     0,
       0,     0,    56,     0,    43,    44,    45,    47,    46,   133,
       0,     0,     0,    64,     0,    96,   104,     0,     0,     0,
     111,    49,    57,    59,     0,     0,   135,     0,    41,    38,
      37,     0,    83,   129,   114,   119,     0,    60,     0,     0,
     120,    42,     0,   134,    39,    34,     0,   101,   115,    49,
      48,   133,     0,    31,     0,   100,   117,   116,   106,   112,
       0,    50,    40,    35,   102,   115,   105,   107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   194,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,    -7,  -144,  -144,    18,    36,  -144,
    -144,  -144,    -1,  -107,  -144,  -144,  -144,    48,     3,   -36,
    -143,    -3,  -144,   -90,    41,  -144,  -144,  -144,    61,  -144,
      -5,  -144,     0,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   163,  -134,  -144,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    42,   216,    31,    32,   181,   152,   212,
     179,    33,   209,    55,    34,    35,   147,   148,    77,    56,
     116,   117,    58,   143,   139,   105,   140,   225,   141,   228,
     229,    59,    60,   207,   168,   230,   190,    37,    38,    39,
     165,    72,   100,   101,   102,   198
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    57,   149,    36,    61,   162,   137,     3,     4,   196,
      40,    80,   195,   183,    81,   184,    45,   145,   118,    98,
      99,    36,   133,   196,    85,     3,     4,    46,    82,   163,
     134,    62,  -131,   119,   174,   175,   176,   177,   178,   226,
     227,   197,    78,   138,    63,   204,    46,    47,    64,    83,
      84,    48,    49,    50,    51,   197,    41,  -123,   172,    52,
     164,    43,   191,    44,   115,    65,    66,    53,    54,   217,
      48,    49,    68,    51,    96,    97,    98,    99,    67,    70,
      71,    73,    74,    79,   121,   122,    75,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   159,    76,   104,
      57,   219,    86,   136,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    45,   103,   108,
     109,   106,   107,   111,   110,   112,   113,   114,    46,    89,
     135,   142,   150,   156,   144,   146,   151,   155,   157,   166,
     161,   153,   154,   158,   167,   160,   169,   171,    47,   173,
     170,   180,    48,    49,    50,    51,   185,   182,   187,   188,
      52,   194,   200,  -127,   201,   189,   202,   192,    53,    54,
      86,  -127,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   206,   205,     1,     2,   208,
     210,   211,     3,     4,     5,   213,     6,     7,     8,     9,
      10,   218,   222,   215,    11,    12,    13,   220,   221,   223,
     224,   235,    69,    14,    15,   233,   199,   214,   231,   193,
      16,   234,    17,    85,   186,    18,  -127,   236,   203,   232,
     237,  -131,     0,    86,  -127,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,  -127,   120,
       0,     0,     0,     0,     0,    86,  -127,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,  -132,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99
};

static const yytype_int16 yycheck[] =
{
       3,     4,   109,     0,     4,   139,    18,     9,    10,    29,
       6,    47,    18,   156,    18,   158,    18,   107,    55,    70,
      71,    18,    50,    29,    47,     9,    10,    29,    32,    20,
      58,    55,    55,    70,    24,    25,    26,    27,    28,    11,
      12,    61,    45,    55,     7,   188,    29,    49,    33,    52,
      53,    53,    54,    55,    56,    61,    52,    48,   148,    61,
      51,     6,   169,     8,    19,    35,    55,    69,    70,   203,
      53,    54,    40,    56,    68,    69,    70,    71,    55,     0,
       3,    55,     8,    18,    87,    88,    55,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   133,    55,    35,
     103,   208,    57,   103,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    18,    20,    37,
      66,    55,    55,    18,    41,    55,    38,    19,    29,    61,
      55,    36,    56,    20,    34,    55,    55,    19,    29,   142,
     137,    38,    55,    18,    43,    56,    18,    20,    49,    33,
      66,    20,    53,    54,    55,    56,    19,    55,    48,    44,
      61,     6,    19,    50,    18,    46,    19,   170,    69,    70,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    45,   189,     4,     5,    20,
      55,    53,     9,    10,    11,    29,    13,    14,    15,    16,
      17,    44,    20,    55,    21,    22,    23,    19,    19,    19,
      38,    20,    18,    30,    31,   222,   180,   199,   219,   171,
      37,   224,    39,    47,   163,    42,    50,   230,   187,   221,
     235,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    50,    86,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    13,    14,    15,    16,
      17,    21,    22,    23,    30,    31,    37,    39,    42,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    88,    89,    94,    97,    98,   101,   120,   121,   122,
       6,    52,    86,     6,     8,    18,    29,    49,    53,    54,
      55,    56,    61,    69,    70,    96,   102,   104,   105,   114,
     115,   115,    55,     7,    33,    35,    55,    55,    40,    75,
       0,     3,   124,    55,     8,    55,    55,   101,   104,    18,
     102,    18,    32,   104,   104,    47,    57,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     125,   126,   127,    20,    35,   108,    55,    55,    37,    66,
      41,    18,    55,    38,    19,    19,   103,   104,    55,    70,
     125,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,    50,    58,    55,   115,    18,    55,   107,
     109,   111,    36,   106,    34,   106,    55,    99,   100,    96,
      56,    55,    91,    38,    55,    19,    20,    29,    18,   102,
      56,   101,   126,    20,    51,   123,   104,    43,   117,    18,
      66,    20,   106,    33,    24,    25,    26,    27,    28,    93,
      20,    90,    55,   103,   103,    19,   111,    48,    44,    46,
     119,    96,   104,   100,     6,    18,    29,    61,   128,    91,
      19,    18,    19,   107,   103,   104,    45,   116,    20,    95,
      55,    53,    92,    29,    90,    55,    87,   126,    44,    96,
      19,    19,    20,    19,    38,   110,    11,    12,   112,   113,
     118,    95,   128,    87,   104,    20,   104,   113
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    86,    87,    87,    88,    89,    90,    90,
      91,    91,    92,    93,    93,    93,    93,    93,    94,    95,
      95,    96,    96,    96,    96,    97,    98,    99,   100,   100,
     101,   101,   102,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   113,   113,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   121,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     9,     0,     1,     1,     3,     5,     7,     0,     3,
       6,     3,     1,     1,     1,     1,     1,     1,     8,     0,
       3,     1,     1,     1,     1,     4,     5,     3,     1,     3,
       7,     2,     3,     1,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     2,     6,     4,     4,     4,     1,     1,     1,
       3,     3,     1,     0,     2,     1,     3,     0,     2,     2,
       6,     0,     2,     1,     3,     2,     1,     3,     2,     1,
       3,     0,     3,     0,     3,     0,     1,     1,     0,     2,
       7,     2,     4,     0,     1,     0,     1,     0,     1,     0,
       2,     0,     1,     0,     2,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 210 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1824 "yacc_sql.cpp"
    break;

  case 22: /* exit_stmt: EXIT  */
#line 239 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1833 "yacc_sql.cpp"
    break;

  case 23: /* help_stmt: HELP  */
#line 245 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1841 "yacc_sql.cpp"
    break;

  case 24: /* sync_stmt: SYNC  */
#line 250 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1849 "yacc_sql.cpp"
    break;

  case 25: /* begin_stmt: TRX_BEGIN  */
#line 256 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1857 "yacc_sql.cpp"
    break;

  case 26: /* commit_stmt: TRX_COMMIT  */
#line 262 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1865 "yacc_sql.cpp"
    break;

  case 27: /* rollback_stmt: TRX_ROLLBACK  */
#line 268 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1873 "yacc_sql.cpp"
    break;

  case 28: /* drop_table_stmt: DROP TABLE ID  */
#line 274 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1883 "yacc_sql.cpp"
    break;

  case 29: /* show_tables_stmt: SHOW TABLES  */
#line 281 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1891 "yacc_sql.cpp"
    break;

  case 30: /* desc_table_stmt: DESC ID  */
#line 287 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1901 "yacc_sql.cpp"
    break;

  case 31: /* create_index_stmt: CREATE opt_unique INDEX ID ON ID LBRACE index_col_list RBRACE  */
#line 296 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].string_list));
      create_index.unique = (yyvsp[-7].booleans);
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      delete (yyvsp[-1].string_list);
    }
#line 1917 "yacc_sql.cpp"
    break;

  case 32: /* opt_unique: %empty  */
#line 309 "yacc_sql.y"
    {(yyval.booleans) = false;}
#line 1923 "yacc_sql.cpp"
    break;

  case 33: /* opt_unique: UNIQUE  */
#line 310 "yacc_sql.y"
             {(yyval.booleans) = true;}
#line 1929 "yacc_sql.cpp"
    break;

  case 34: /* index_col_list: ID  */
#line 314 "yacc_sql.y"
                   {
      (yyval.string_list) = new std::vector<std::string>;
      (yyval.string_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 35: /* index_col_list: ID COMMA index_col_list  */
#line 319 "yacc_sql.y"
                                {
      if ((yyvsp[0].string_list) != nullptr) {
        (yyval.string_list) = (yyvsp[0].string_list);
      } else {
        (yyval.string_list) = new std::vector<std::string>;
      }
      (yyval.string_list)->insert((yyval.string_list)->begin(), (yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 1953 "yacc_sql.cpp"
    break;

  case 36: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 331 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1965 "yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 342 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 1986 "yacc_sql.cpp"
    break;

  case 38: /* attr_def_list: %empty  */
#line 362 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1994 "yacc_sql.cpp"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 366 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2008 "yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type LBRACE number RBRACE opt_nullable  */
#line 379 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-5].string));
    }
#line 2021 "yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type opt_nullable  */
#line 388 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;   /*length 默认为4, 这一点和Mysql不一样*/
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-2].string));
    }
#line 2034 "yacc_sql.cpp"
    break;

  case 42: /* number: NUMBER  */
#line 399 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2040 "yacc_sql.cpp"
    break;

  case 43: /* type: INT_T  */
#line 403 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2046 "yacc_sql.cpp"
    break;

  case 44: /* type: STRING_T  */
#line 404 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2052 "yacc_sql.cpp"
    break;

  case 45: /* type: FLOAT_T  */
#line 405 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2058 "yacc_sql.cpp"
    break;

  case 46: /* type: TEXT_T  */
#line 406 "yacc_sql.y"
               { (yyval.number)=TEXTS; }
#line 2064 "yacc_sql.cpp"
    break;

  case 47: /* type: DATE_T  */
#line 407 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2070 "yacc_sql.cpp"
    break;

  case 48: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 412 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2087 "yacc_sql.cpp"
    break;

  case 49: /* value_list: %empty  */
#line 428 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2095 "yacc_sql.cpp"
    break;

  case 50: /* value_list: COMMA value value_list  */
#line 431 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2109 "yacc_sql.cpp"
    break;

  case 51: /* value: NUMBER  */
#line 443 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2118 "yacc_sql.cpp"
    break;

  case 52: /* value: FLOAT  */
#line 447 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2127 "yacc_sql.cpp"
    break;

  case 53: /* value: SSS  */
#line 451 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2138 "yacc_sql.cpp"
    break;

  case 54: /* value: THE_NULL  */
#line 457 "yacc_sql.y"
              {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
    }
#line 2147 "yacc_sql.cpp"
    break;

  case 55: /* delete_stmt: DELETE FROM ID opt_where  */
#line 465 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].expression) != nullptr) {
        (yyval.sql_node)->deletion.condition = (yyvsp[0].expression);
      }
      free((yyvsp[-1].string));
    }
#line 2160 "yacc_sql.cpp"
    break;

  case 56: /* update_stmt: UPDATE ID SET update_asgn_list opt_where  */
#line 477 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.assignments.swap(*(yyvsp[-1].update_asgn_list));
      if ((yyvsp[0].expression) != nullptr) {
        (yyval.sql_node)->update.condition = (yyvsp[0].expression);
      }
      free((yyvsp[-3].string));
    }
#line 2174 "yacc_sql.cpp"
    break;

  case 57: /* update_asgn_factor: ID EQ expression  */
#line 490 "yacc_sql.y"
    {
      UpdateAssignmentSqlNode *tmp = new UpdateAssignmentSqlNode;
      tmp->attribute_name = (yyvsp[-2].string);
      tmp->value = (yyvsp[0].expression);

      (yyval.update_asgn_factor) = tmp;
    }
#line 2186 "yacc_sql.cpp"
    break;

  case 58: /* update_asgn_list: update_asgn_factor  */
#line 500 "yacc_sql.y"
    {
      (yyval.update_asgn_list) = new std::vector<UpdateAssignmentSqlNode *>;
      (yyval.update_asgn_list)->push_back((yyvsp[0].update_asgn_factor));
    }
#line 2195 "yacc_sql.cpp"
    break;

  case 59: /* update_asgn_list: update_asgn_factor COMMA update_asgn_list  */
#line 505 "yacc_sql.y"
    {
      if ((yyvsp[0].update_asgn_list) != nullptr) {
        (yyval.update_asgn_list) = (yyvsp[0].update_asgn_list);
      } else {
        (yyval.update_asgn_list) = new std::vector<UpdateAssignmentSqlNode *>;
      }
      (yyval.update_asgn_list)->insert((yyval.update_asgn_list)->begin(), (yyvsp[-2].update_asgn_factor));
    }
#line 2208 "yacc_sql.cpp"
    break;

  case 60: /* select_stmt: SELECT query_expression_list opt_table_refs opt_where opt_group_by opt_having opt_order_by  */
#line 518 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].expression_with_alias_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-5].expression_with_alias_list));
        delete (yyvsp[-5].expression_with_alias_list);
      }
      if ((yyvsp[-4].table_reference_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].table_reference_list));
        delete (yyvsp[-4].table_reference_list);
      }
      if ((yyvsp[-3].expression) != nullptr) {
        (yyval.sql_node)->selection.condition = (yyvsp[-3].expression);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-2].expression_list));
        delete (yyvsp[-2].expression_list);
      }
      if ((yyvsp[-1].expression) != nullptr) {
        (yyval.sql_node)->selection.having = (yyvsp[-1].expression);
      }
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_by.swap(*(yyvsp[0].order_by_list));
        delete (yyvsp[0].order_by_list);
      }
    }
#line 2238 "yacc_sql.cpp"
    break;

  case 61: /* select_stmt: CALC query_expression_list  */
#line 544 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_with_alias_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[0].expression_with_alias_list));
        delete (yyvsp[0].expression_with_alias_list);
      }
    }
#line 2250 "yacc_sql.cpp"
    break;

  case 62: /* select_with_parenthesis: LBRACE select_stmt RBRACE  */
#line 554 "yacc_sql.y"
    {
      (yyval.subquery) = new SubqueryExpressionSqlNode;
      (yyval.subquery)->subquery = (yyvsp[-1].sql_node);
    }
#line 2259 "yacc_sql.cpp"
    break;

  case 63: /* expression_list: expression  */
#line 561 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<ExpressionSqlNode *>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2268 "yacc_sql.cpp"
    break;

  case 64: /* expression_list: expression COMMA expression_list  */
#line 566 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<ExpressionSqlNode *>;
      }
      (yyval.expression_list)->insert((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2281 "yacc_sql.cpp"
    break;

  case 65: /* expression: expression ADD expression  */
#line 577 "yacc_sql.y"
                              {
      ArithmeticExpressionSqlNode* tmp = new ArithmeticExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->arithmetic_type = ArithmeticType::ADD;

      (yyval.expression) = tmp;
      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2295 "yacc_sql.cpp"
    break;

  case 66: /* expression: expression SUB expression  */
#line 586 "yacc_sql.y"
                                {
      ArithmeticExpressionSqlNode* tmp = new ArithmeticExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->arithmetic_type = ArithmeticType::SUB;

      (yyval.expression) = tmp;
      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2309 "yacc_sql.cpp"
    break;

  case 67: /* expression: expression STAR expression  */
#line 595 "yacc_sql.y"
                                 {
      ArithmeticExpressionSqlNode* tmp = new ArithmeticExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->arithmetic_type = ArithmeticType::MUL;

      (yyval.expression) = tmp;
      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2323 "yacc_sql.cpp"
    break;

  case 68: /* expression: expression DIV expression  */
#line 604 "yacc_sql.y"
                                {
      ArithmeticExpressionSqlNode* tmp = new ArithmeticExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->arithmetic_type = ArithmeticType::DIV;

      (yyval.expression) = tmp;
      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2337 "yacc_sql.cpp"
    break;

  case 69: /* expression: select_with_parenthesis  */
#line 613 "yacc_sql.y"
                              {
      (yyval.expression) = (yyvsp[0].subquery);

      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2347 "yacc_sql.cpp"
    break;

  case 70: /* expression: SUB expression  */
#line 618 "yacc_sql.y"
                                  {
      ArithmeticExpressionSqlNode* tmp = new ArithmeticExpressionSqlNode;
      tmp->right = (yyvsp[0].expression);
      tmp->left = new ValueExpressionSqlNode;
      tmp->arithmetic_type = ArithmeticType::SUB;

      ((ValueExpressionSqlNode *)(tmp->left))->value = Value(0);

      (yyval.expression) = tmp;
      (yyval.expression)->name = token_name(sql_string, &(yyloc));
    }
#line 2363 "yacc_sql.cpp"
    break;

  case 71: /* expression: expression EQ expression  */
#line 629 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = EQUAL_TO;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression LT expression  */
#line 638 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = LESS_THAN;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 73: /* expression: expression GT expression  */
#line 647 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = GREAT_THAN;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2405 "yacc_sql.cpp"
    break;

  case 74: /* expression: expression LE expression  */
#line 656 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = LESS_EQUAL;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2419 "yacc_sql.cpp"
    break;

  case 75: /* expression: expression GE expression  */
#line 665 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = GREAT_EQUAL;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2433 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression NE expression  */
#line 674 "yacc_sql.y"
                               {
      ComparisonExpressionSqlNode *tmp = new ComparisonExpressionSqlNode;
      tmp->comp_op = NOT_EQUAL;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2447 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression AND expression  */
#line 683 "yacc_sql.y"
                                {
      ConjunctionExpressionSqlNode *tmp = new ConjunctionExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->conjunction_type = ConjunctionType::AND;
      
      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2461 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression OR expression  */
#line 692 "yacc_sql.y"
                               {
      ConjunctionExpressionSqlNode *tmp = new ConjunctionExpressionSqlNode;
      tmp->left = (yyvsp[-2].expression);
      tmp->right = (yyvsp[0].expression);
      tmp->conjunction_type = ConjunctionType::OR;
      
      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2475 "yacc_sql.cpp"
    break;

  case 79: /* expression: LBRACE expression RBRACE  */
#line 701 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2483 "yacc_sql.cpp"
    break;

  case 80: /* expression: expression opt_not LIKE SSS  */
#line 704 "yacc_sql.y"
                                  {
      LikeExpressionSqlNode *tmp = new LikeExpressionSqlNode;
      tmp->child = (yyvsp[-3].expression);
      char *dupped_str = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      tmp->pattern = dupped_str;
      free(dupped_str);
      free((yyvsp[0].string));

      (yyval.expression) = tmp;

      if ((yyvsp[-2].booleans)) {
        NotExpressionSqlNode* not_p = new NotExpressionSqlNode;
        not_p->child = (yyval.expression);
        (yyval.expression) = not_p;
      }

      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2506 "yacc_sql.cpp"
    break;

  case 81: /* expression: NOT expression  */
#line 722 "yacc_sql.y"
                     {
      NotExpressionSqlNode *tmp = new NotExpressionSqlNode;
      tmp->child = (yyvsp[0].expression);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 82: /* expression: EXISTS select_with_parenthesis  */
#line 729 "yacc_sql.y"
                                     {
      ExistsExpressionSqlNode *tmp = new ExistsExpressionSqlNode;
      tmp->subquery = (yyvsp[0].subquery);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2530 "yacc_sql.cpp"
    break;

  case 83: /* expression: expression opt_not IN LBRACE expression_list RBRACE  */
#line 736 "yacc_sql.y"
                                                          {
      InExpressionSqlNode *tmp = new InExpressionSqlNode;
      tmp->child = (yyvsp[-5].expression);
      tmp->value_list.swap(*(yyvsp[-1].expression_list));
      delete (yyvsp[-1].expression_list);

      (yyval.expression) = tmp;

      if ((yyvsp[-4].booleans)) {
        NotExpressionSqlNode* not_p = new NotExpressionSqlNode;
        not_p->child = (yyval.expression);
        (yyval.expression) = not_p;
      }

      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2551 "yacc_sql.cpp"
    break;

  case 84: /* expression: expression opt_not IN select_with_parenthesis  */
#line 752 "yacc_sql.y"
                                                    {
      InExpressionSqlNode *tmp = new InExpressionSqlNode;
      tmp->child = (yyvsp[-3].expression);
      tmp->subquery = (yyvsp[0].subquery);

      (yyval.expression) = tmp;

      if ((yyvsp[-2].booleans)) {
        NotExpressionSqlNode* not_p = new NotExpressionSqlNode;
        not_p->child = (yyval.expression);
        (yyval.expression) = not_p;
      }

      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2571 "yacc_sql.cpp"
    break;

  case 85: /* expression: expression IS opt_not THE_NULL  */
#line 767 "yacc_sql.y"
                                     {
      IsNullExpressionSqlNode *tmp = new IsNullExpressionSqlNode;
      tmp->child = (yyvsp[-3].expression);

      (yyval.expression) = tmp;

      if ((yyvsp[-1].booleans)) {
        NotExpressionSqlNode* not_p = new NotExpressionSqlNode;
        not_p->child = (yyval.expression);
        (yyval.expression) = not_p;
      }

      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2590 "yacc_sql.cpp"
    break;

  case 86: /* expression: ID LBRACE expression_list RBRACE  */
#line 781 "yacc_sql.y"
                                       {
      FunctionExpressionSqlNode *tmp = new FunctionExpressionSqlNode;
      tmp->param_exprs.swap(*(yyvsp[-1].expression_list));
      tmp->function_name = (yyvsp[-3].string);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2603 "yacc_sql.cpp"
    break;

  case 87: /* expression: value  */
#line 789 "yacc_sql.y"
            {
      ValueExpressionSqlNode *tmp = new ValueExpressionSqlNode;
      tmp->value = *(yyvsp[0].value);
      delete (yyvsp[0].value);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2616 "yacc_sql.cpp"
    break;

  case 88: /* expression: rel_attr  */
#line 797 "yacc_sql.y"
               {
      FieldExpressionSqlNode *tmp = new FieldExpressionSqlNode;
      tmp->field = *(yyvsp[0].rel_attr);
      delete (yyvsp[0].rel_attr);

      (yyval.expression) = tmp;
      (yyval.expression)->name = (token_name(sql_string, &(yyloc)));
    }
#line 2629 "yacc_sql.cpp"
    break;

  case 89: /* rel_attr: ID  */
#line 808 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2640 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: ID DOT ID  */
#line 814 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2652 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: ID DOT STAR  */
#line 821 "yacc_sql.y"
                  {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = "*";
    }
#line 2662 "yacc_sql.cpp"
    break;

  case 92: /* rel_attr: STAR  */
#line 826 "yacc_sql.y"
           {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = "";
      (yyval.rel_attr)->attribute_name = "*";
    }
#line 2672 "yacc_sql.cpp"
    break;

  case 93: /* opt_where: %empty  */
#line 837 "yacc_sql.y"
    {
      (yyval.expression) = nullptr;
    }
#line 2680 "yacc_sql.cpp"
    break;

  case 94: /* opt_where: WHERE expression  */
#line 840 "yacc_sql.y"
                       {
      (yyval.expression) = (yyvsp[0].expression);  
    }
#line 2688 "yacc_sql.cpp"
    break;

  case 95: /* table_factor: ID  */
#line 846 "yacc_sql.y"
    {
      TablePrimarySqlNode* tmp = new TablePrimarySqlNode;
      tmp->relation_name = (yyvsp[0].string);

      (yyval.table_factor_node) = tmp;
    }
#line 2699 "yacc_sql.cpp"
    break;

  case 96: /* table_factor: LBRACE select_stmt RBRACE  */
#line 853 "yacc_sql.y"
    {
      TableSubquerySqlNode* tmp = new TableSubquerySqlNode;
      tmp->subquery = (yyvsp[-1].sql_node)->selection;

      (yyval.table_factor_node) = tmp;
    }
#line 2710 "yacc_sql.cpp"
    break;

  case 97: /* opt_table_refs: %empty  */
#line 861 "yacc_sql.y"
    {
      (yyval.table_reference_list) = nullptr;
    }
#line 2718 "yacc_sql.cpp"
    break;

  case 98: /* opt_table_refs: FROM table_ref_list  */
#line 865 "yacc_sql.y"
    {
      (yyval.table_reference_list) = (yyvsp[0].table_reference_list);
    }
#line 2726 "yacc_sql.cpp"
    break;

  case 99: /* table_ref: table_factor opt_alias  */
#line 870 "yacc_sql.y"
    {
      (yyval.table_reference) = (yyvsp[-1].table_factor_node);
      if ((yyvsp[0].string) != nullptr) {
        (yyval.table_reference)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2738 "yacc_sql.cpp"
    break;

  case 100: /* table_ref: table_ref opt_inner JOIN table_factor opt_alias opt_join_condition  */
#line 878 "yacc_sql.y"
    {
      TableJoinSqlNode *tmp = new TableJoinSqlNode;
      tmp->left = (yyvsp[-5].table_reference);
      tmp->right = (yyvsp[-2].table_factor_node);
      if ((yyvsp[-1].string)) {
        tmp->right->alias = (yyvsp[-1].string);
      }
      if ((yyvsp[0].expression)) {
        tmp->condition = (yyvsp[0].expression);
      }

      (yyval.table_reference) = tmp;
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 101: /* opt_join_condition: %empty  */
#line 893 "yacc_sql.y"
    {
      (yyval.expression) = nullptr;
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 102: /* opt_join_condition: ON expression  */
#line 897 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2772 "yacc_sql.cpp"
    break;

  case 103: /* table_ref_list: table_ref  */
#line 903 "yacc_sql.y"
    {
      (yyval.table_reference_list) = new std::vector<TableReferenceSqlNode *>;
      (yyval.table_reference_list)->push_back((yyvsp[0].table_reference));
    }
#line 2781 "yacc_sql.cpp"
    break;

  case 104: /* table_ref_list: table_ref COMMA table_ref_list  */
#line 908 "yacc_sql.y"
    {
      if ((yyvsp[0].table_reference_list) != nullptr) {
        (yyval.table_reference_list) = (yyvsp[0].table_reference_list);
      } else {
        (yyval.table_reference_list) = new std::vector<TableReferenceSqlNode *>;
      }
      (yyval.table_reference_list)->insert((yyval.table_reference_list)->begin(), (yyvsp[-2].table_reference));
    }
#line 2794 "yacc_sql.cpp"
    break;

  case 105: /* expression_with_order: opt_order_type expression  */
#line 918 "yacc_sql.y"
    {
      ExpressionWithOrderSqlNode *tmp = new ExpressionWithOrderSqlNode;
      tmp->expr = (yyvsp[0].expression);
      tmp->order_type = (yyvsp[-1].order_type);

      (yyval.order_by_node) = tmp;
    }
#line 2806 "yacc_sql.cpp"
    break;

  case 106: /* expression_with_order_list: expression_with_order  */
#line 927 "yacc_sql.y"
    {
      (yyval.order_by_list) = new std::vector<ExpressionWithOrderSqlNode *>;
      (yyval.order_by_list)->push_back((yyvsp[0].order_by_node));
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 107: /* expression_with_order_list: expression_with_order COMMA expression_with_order_list  */
#line 932 "yacc_sql.y"
    {
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.order_by_list) = (yyvsp[0].order_by_list);
      } else {
        (yyval.order_by_list) = new std::vector<ExpressionWithOrderSqlNode *>;
      }
      (yyval.order_by_list)->insert((yyval.order_by_list)->begin(), (yyvsp[-2].order_by_node));
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 108: /* query_expression: expression opt_alias  */
#line 942 "yacc_sql.y"
    {
      ExpressionWithAliasSqlNode *tmp = new ExpressionWithAliasSqlNode;
      tmp->expr = (yyvsp[-1].expression);
      if ((yyvsp[0].string) != nullptr) {
        tmp->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }

      (yyval.expression_with_alias) = tmp;
    }
#line 2843 "yacc_sql.cpp"
    break;

  case 109: /* query_expression_list: query_expression  */
#line 954 "yacc_sql.y"
    {
      (yyval.expression_with_alias_list) = new std::vector<ExpressionWithAliasSqlNode *>;
      (yyval.expression_with_alias_list)->push_back((yyvsp[0].expression_with_alias));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 110: /* query_expression_list: query_expression COMMA query_expression_list  */
#line 959 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_with_alias_list) != nullptr) {
        (yyval.expression_with_alias_list) = (yyvsp[0].expression_with_alias_list);
      } else {
        (yyval.expression_with_alias_list) = new std::vector<ExpressionWithAliasSqlNode *>;
      }
      (yyval.expression_with_alias_list)->insert((yyval.expression_with_alias_list)->begin(), (yyvsp[-2].expression_with_alias));
    }
#line 2865 "yacc_sql.cpp"
    break;

  case 111: /* opt_order_by: %empty  */
#line 969 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2873 "yacc_sql.cpp"
    break;

  case 112: /* opt_order_by: ORDER BY expression_with_order_list  */
#line 973 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
    }
#line 2881 "yacc_sql.cpp"
    break;

  case 113: /* opt_group_by: %empty  */
#line 979 "yacc_sql.y"
    {
      (yyval.expression_list) =nullptr;
    }
#line 2889 "yacc_sql.cpp"
    break;

  case 114: /* opt_group_by: GROUP BY expression_list  */
#line 983 "yacc_sql.y"
    {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 2897 "yacc_sql.cpp"
    break;

  case 115: /* opt_order_type: %empty  */
#line 989 "yacc_sql.y"
    {
      (yyval.order_type) = OrderType::ASC;
    }
#line 2905 "yacc_sql.cpp"
    break;

  case 116: /* opt_order_type: ASC  */
#line 993 "yacc_sql.y"
    {
      (yyval.order_type) = OrderType::ASC;
    }
#line 2913 "yacc_sql.cpp"
    break;

  case 117: /* opt_order_type: DESC  */
#line 997 "yacc_sql.y"
    {
      (yyval.order_type) = OrderType::DESC;
    }
#line 2921 "yacc_sql.cpp"
    break;

  case 118: /* opt_having: %empty  */
#line 1003 "yacc_sql.y"
    {
      (yyval.expression) = nullptr;
    }
#line 2929 "yacc_sql.cpp"
    break;

  case 119: /* opt_having: HAVING expression  */
#line 1007 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2937 "yacc_sql.cpp"
    break;

  case 120: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1013 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2951 "yacc_sql.cpp"
    break;

  case 121: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1026 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2960 "yacc_sql.cpp"
    break;

  case 122: /* set_variable_stmt: SET ID EQ value  */
#line 1034 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 127: /* opt_not: %empty  */
#line 1052 "yacc_sql.y"
    {(yyval.booleans) = false;}
#line 2978 "yacc_sql.cpp"
    break;

  case 128: /* opt_not: NOT  */
#line 1053 "yacc_sql.y"
          {(yyval.booleans) = true;}
#line 2984 "yacc_sql.cpp"
    break;

  case 129: /* opt_alias: %empty  */
#line 1057 "yacc_sql.y"
    {(yyval.string) = nullptr;}
#line 2990 "yacc_sql.cpp"
    break;

  case 130: /* opt_alias: opt_as ID  */
#line 1059 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2998 "yacc_sql.cpp"
    break;

  case 133: /* opt_nullable: %empty  */
#line 1067 "yacc_sql.y"
               {(yyval.booleans) = true;}
#line 3004 "yacc_sql.cpp"
    break;

  case 134: /* opt_nullable: NOT THE_NULL  */
#line 1068 "yacc_sql.y"
                   {(yyval.booleans) = false;}
#line 3010 "yacc_sql.cpp"
    break;

  case 135: /* opt_nullable: THE_NULL  */
#line 1069 "yacc_sql.y"
               {(yyval.booleans) = true;}
#line 3016 "yacc_sql.cpp"
    break;


#line 3020 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1072 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
