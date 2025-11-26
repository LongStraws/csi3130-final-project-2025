/* A Bison parser, made by GNU Bison 3.7.5.  */

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
    SQL_ALLOCATE = 258,            /* SQL_ALLOCATE  */
    SQL_AUTOCOMMIT = 259,          /* SQL_AUTOCOMMIT  */
    SQL_BOOL = 260,                /* SQL_BOOL  */
    SQL_BREAK = 261,               /* SQL_BREAK  */
    SQL_CALL = 262,                /* SQL_CALL  */
    SQL_CARDINALITY = 263,         /* SQL_CARDINALITY  */
    SQL_CONNECT = 264,             /* SQL_CONNECT  */
    SQL_CONTINUE = 265,            /* SQL_CONTINUE  */
    SQL_COUNT = 266,               /* SQL_COUNT  */
    SQL_CURRENT = 267,             /* SQL_CURRENT  */
    SQL_DATA = 268,                /* SQL_DATA  */
    SQL_DATETIME_INTERVAL_CODE = 269, /* SQL_DATETIME_INTERVAL_CODE  */
    SQL_DATETIME_INTERVAL_PRECISION = 270, /* SQL_DATETIME_INTERVAL_PRECISION  */
    SQL_DESCRIBE = 271,            /* SQL_DESCRIBE  */
    SQL_DESCRIPTOR = 272,          /* SQL_DESCRIPTOR  */
    SQL_DISCONNECT = 273,          /* SQL_DISCONNECT  */
    SQL_ENUM = 274,                /* SQL_ENUM  */
    SQL_FOUND = 275,               /* SQL_FOUND  */
    SQL_FREE = 276,                /* SQL_FREE  */
    SQL_GO = 277,                  /* SQL_GO  */
    SQL_GOTO = 278,                /* SQL_GOTO  */
    SQL_IDENTIFIED = 279,          /* SQL_IDENTIFIED  */
    SQL_INDICATOR = 280,           /* SQL_INDICATOR  */
    SQL_KEY_MEMBER = 281,          /* SQL_KEY_MEMBER  */
    SQL_LENGTH = 282,              /* SQL_LENGTH  */
    SQL_LONG = 283,                /* SQL_LONG  */
    SQL_NAME = 284,                /* SQL_NAME  */
    SQL_NULLABLE = 285,            /* SQL_NULLABLE  */
    SQL_OCTET_LENGTH = 286,        /* SQL_OCTET_LENGTH  */
    SQL_OPEN = 287,                /* SQL_OPEN  */
    SQL_OUTPUT = 288,              /* SQL_OUTPUT  */
    SQL_REFERENCE = 289,           /* SQL_REFERENCE  */
    SQL_RETURNED_LENGTH = 290,     /* SQL_RETURNED_LENGTH  */
    SQL_RETURNED_OCTET_LENGTH = 291, /* SQL_RETURNED_OCTET_LENGTH  */
    SQL_SCALE = 292,               /* SQL_SCALE  */
    SQL_SECTION = 293,             /* SQL_SECTION  */
    SQL_SHORT = 294,               /* SQL_SHORT  */
    SQL_SIGNED = 295,              /* SQL_SIGNED  */
    SQL_SQL = 296,                 /* SQL_SQL  */
    SQL_SQLERROR = 297,            /* SQL_SQLERROR  */
    SQL_SQLPRINT = 298,            /* SQL_SQLPRINT  */
    SQL_SQLWARNING = 299,          /* SQL_SQLWARNING  */
    SQL_START = 300,               /* SQL_START  */
    SQL_STOP = 301,                /* SQL_STOP  */
    SQL_STRUCT = 302,              /* SQL_STRUCT  */
    SQL_UNSIGNED = 303,            /* SQL_UNSIGNED  */
    SQL_VALUE = 304,               /* SQL_VALUE  */
    SQL_VAR = 305,                 /* SQL_VAR  */
    SQL_WHENEVER = 306,            /* SQL_WHENEVER  */
    S_ADD = 307,                   /* S_ADD  */
    S_AND = 308,                   /* S_AND  */
    S_ANYTHING = 309,              /* S_ANYTHING  */
    S_AUTO = 310,                  /* S_AUTO  */
    S_CONST = 311,                 /* S_CONST  */
    S_DEC = 312,                   /* S_DEC  */
    S_DIV = 313,                   /* S_DIV  */
    S_DOTPOINT = 314,              /* S_DOTPOINT  */
    S_EQUAL = 315,                 /* S_EQUAL  */
    S_EXTERN = 316,                /* S_EXTERN  */
    S_INC = 317,                   /* S_INC  */
    S_LSHIFT = 318,                /* S_LSHIFT  */
    S_MEMPOINT = 319,              /* S_MEMPOINT  */
    S_MEMBER = 320,                /* S_MEMBER  */
    S_MOD = 321,                   /* S_MOD  */
    S_MUL = 322,                   /* S_MUL  */
    S_NEQUAL = 323,                /* S_NEQUAL  */
    S_OR = 324,                    /* S_OR  */
    S_REGISTER = 325,              /* S_REGISTER  */
    S_RSHIFT = 326,                /* S_RSHIFT  */
    S_STATIC = 327,                /* S_STATIC  */
    S_SUB = 328,                   /* S_SUB  */
    S_VOLATILE = 329,              /* S_VOLATILE  */
    S_TYPEDEF = 330,               /* S_TYPEDEF  */
    TYPECAST = 331,                /* TYPECAST  */
    ABORT_P = 332,                 /* ABORT_P  */
    ABSOLUTE_P = 333,              /* ABSOLUTE_P  */
    ACCESS = 334,                  /* ACCESS  */
    ACTION = 335,                  /* ACTION  */
    ADD = 336,                     /* ADD  */
    ADMIN = 337,                   /* ADMIN  */
    AFTER = 338,                   /* AFTER  */
    AGGREGATE = 339,               /* AGGREGATE  */
    ALL = 340,                     /* ALL  */
    ALSO = 341,                    /* ALSO  */
    ALTER = 342,                   /* ALTER  */
    ANALYSE = 343,                 /* ANALYSE  */
    ANALYZE = 344,                 /* ANALYZE  */
    AND = 345,                     /* AND  */
    ANY = 346,                     /* ANY  */
    ARRAY = 347,                   /* ARRAY  */
    AS = 348,                      /* AS  */
    ASC = 349,                     /* ASC  */
    ASSERTION = 350,               /* ASSERTION  */
    ASSIGNMENT = 351,              /* ASSIGNMENT  */
    ASYMMETRIC = 352,              /* ASYMMETRIC  */
    AT = 353,                      /* AT  */
    AUTHORIZATION = 354,           /* AUTHORIZATION  */
    BACKWARD = 355,                /* BACKWARD  */
    BEFORE = 356,                  /* BEFORE  */
    BEGIN_P = 357,                 /* BEGIN_P  */
    BETWEEN = 358,                 /* BETWEEN  */
    BIGINT = 359,                  /* BIGINT  */
    BINARY = 360,                  /* BINARY  */
    BIT = 361,                     /* BIT  */
    BOOLEAN_P = 362,               /* BOOLEAN_P  */
    BOTH = 363,                    /* BOTH  */
    BY = 364,                      /* BY  */
    CACHE = 365,                   /* CACHE  */
    CALLED = 366,                  /* CALLED  */
    CASCADE = 367,                 /* CASCADE  */
    CASE = 368,                    /* CASE  */
    CAST = 369,                    /* CAST  */
    CHAIN = 370,                   /* CHAIN  */
    CHAR_P = 371,                  /* CHAR_P  */
    CHARACTER = 372,               /* CHARACTER  */
    CHARACTERISTICS = 373,         /* CHARACTERISTICS  */
    CHECK = 374,                   /* CHECK  */
    CHECKPOINT = 375,              /* CHECKPOINT  */
    CLASS = 376,                   /* CLASS  */
    CLOSE = 377,                   /* CLOSE  */
    CLUSTER = 378,                 /* CLUSTER  */
    COALESCE = 379,                /* COALESCE  */
    COLLATE = 380,                 /* COLLATE  */
    COLUMN = 381,                  /* COLUMN  */
    COMMENT = 382,                 /* COMMENT  */
    COMMIT = 383,                  /* COMMIT  */
    COMMITTED = 384,               /* COMMITTED  */
    CONNECTION = 385,              /* CONNECTION  */
    CONSTRAINT = 386,              /* CONSTRAINT  */
    CONSTRAINTS = 387,             /* CONSTRAINTS  */
    CONVERSION_P = 388,            /* CONVERSION_P  */
    CONVERT = 389,                 /* CONVERT  */
    COPY = 390,                    /* COPY  */
    CREATE = 391,                  /* CREATE  */
    CREATEDB = 392,                /* CREATEDB  */
    CREATEROLE = 393,              /* CREATEROLE  */
    CREATEUSER = 394,              /* CREATEUSER  */
    CROSS = 395,                   /* CROSS  */
    CSV = 396,                     /* CSV  */
    CURRENT_DATE = 397,            /* CURRENT_DATE  */
    CURRENT_ROLE = 398,            /* CURRENT_ROLE  */
    CURRENT_TIME = 399,            /* CURRENT_TIME  */
    CURRENT_TIMESTAMP = 400,       /* CURRENT_TIMESTAMP  */
    CURRENT_USER = 401,            /* CURRENT_USER  */
    CURSOR = 402,                  /* CURSOR  */
    CYCLE = 403,                   /* CYCLE  */
    DATABASE = 404,                /* DATABASE  */
    DAY_P = 405,                   /* DAY_P  */
    DEALLOCATE = 406,              /* DEALLOCATE  */
    DEC = 407,                     /* DEC  */
    DECIMAL_P = 408,               /* DECIMAL_P  */
    DECLARE = 409,                 /* DECLARE  */
    DEFAULT = 410,                 /* DEFAULT  */
    DEFAULTS = 411,                /* DEFAULTS  */
    DEFERRABLE = 412,              /* DEFERRABLE  */
    DEFERRED = 413,                /* DEFERRED  */
    DEFINER = 414,                 /* DEFINER  */
    DELETE_P = 415,                /* DELETE_P  */
    DELIMITER = 416,               /* DELIMITER  */
    DELIMITERS = 417,              /* DELIMITERS  */
    DESC = 418,                    /* DESC  */
    DISABLE_P = 419,               /* DISABLE_P  */
    DISTINCT = 420,                /* DISTINCT  */
    DO = 421,                      /* DO  */
    DOMAIN_P = 422,                /* DOMAIN_P  */
    DOUBLE_P = 423,                /* DOUBLE_P  */
    DROP = 424,                    /* DROP  */
    EACH = 425,                    /* EACH  */
    ELSE = 426,                    /* ELSE  */
    ENABLE_P = 427,                /* ENABLE_P  */
    ENCODING = 428,                /* ENCODING  */
    ENCRYPTED = 429,               /* ENCRYPTED  */
    END_P = 430,                   /* END_P  */
    ESCAPE = 431,                  /* ESCAPE  */
    EXCEPT = 432,                  /* EXCEPT  */
    EXCLUSIVE = 433,               /* EXCLUSIVE  */
    EXCLUDING = 434,               /* EXCLUDING  */
    EXECUTE = 435,                 /* EXECUTE  */
    EXISTS = 436,                  /* EXISTS  */
    EXPLAIN = 437,                 /* EXPLAIN  */
    EXTERNAL = 438,                /* EXTERNAL  */
    EXTRACT = 439,                 /* EXTRACT  */
    FALSE_P = 440,                 /* FALSE_P  */
    FETCH = 441,                   /* FETCH  */
    FIRST_P = 442,                 /* FIRST_P  */
    FLOAT_P = 443,                 /* FLOAT_P  */
    FOR = 444,                     /* FOR  */
    FORCE = 445,                   /* FORCE  */
    FOREIGN = 446,                 /* FOREIGN  */
    FORWARD = 447,                 /* FORWARD  */
    FREEZE = 448,                  /* FREEZE  */
    FROM = 449,                    /* FROM  */
    FULL = 450,                    /* FULL  */
    FUNCTION = 451,                /* FUNCTION  */
    GET = 452,                     /* GET  */
    GLOBAL = 453,                  /* GLOBAL  */
    GRANT = 454,                   /* GRANT  */
    GRANTED = 455,                 /* GRANTED  */
    GREATEST = 456,                /* GREATEST  */
    GROUP_P = 457,                 /* GROUP_P  */
    HANDLER = 458,                 /* HANDLER  */
    HAVING = 459,                  /* HAVING  */
    HEADER = 460,                  /* HEADER  */
    HOLD = 461,                    /* HOLD  */
    HOUR_P = 462,                  /* HOUR_P  */
    ILIKE = 463,                   /* ILIKE  */
    IMMEDIATE = 464,               /* IMMEDIATE  */
    IMMUTABLE = 465,               /* IMMUTABLE  */
    IMPLICIT_P = 466,              /* IMPLICIT_P  */
    IN_P = 467,                    /* IN_P  */
    INCLUDING = 468,               /* INCLUDING  */
    INCREMENT = 469,               /* INCREMENT  */
    INDEX = 470,                   /* INDEX  */
    INHERIT = 471,                 /* INHERIT  */
    INHERITS = 472,                /* INHERITS  */
    INITIALLY = 473,               /* INITIALLY  */
    INNER_P = 474,                 /* INNER_P  */
    INOUT = 475,                   /* INOUT  */
    INPUT_P = 476,                 /* INPUT_P  */
    INSENSITIVE = 477,             /* INSENSITIVE  */
    INSERT = 478,                  /* INSERT  */
    INSTEAD = 479,                 /* INSTEAD  */
    INT_P = 480,                   /* INT_P  */
    INTEGER = 481,                 /* INTEGER  */
    INTERSECT = 482,               /* INTERSECT  */
    INTERVAL = 483,                /* INTERVAL  */
    INTO = 484,                    /* INTO  */
    INVOKER = 485,                 /* INVOKER  */
    IS = 486,                      /* IS  */
    ISNULL = 487,                  /* ISNULL  */
    ISOLATION = 488,               /* ISOLATION  */
    JOIN = 489,                    /* JOIN  */
    KEY = 490,                     /* KEY  */
    LANCOMPILER = 491,             /* LANCOMPILER  */
    LANGUAGE = 492,                /* LANGUAGE  */
    LARGE_P = 493,                 /* LARGE_P  */
    LAST_P = 494,                  /* LAST_P  */
    LEADING = 495,                 /* LEADING  */
    LEAST = 496,                   /* LEAST  */
    LEFT = 497,                    /* LEFT  */
    LEVEL = 498,                   /* LEVEL  */
    LIKE = 499,                    /* LIKE  */
    LIMIT = 500,                   /* LIMIT  */
    LISTEN = 501,                  /* LISTEN  */
    LOAD = 502,                    /* LOAD  */
    LOCAL = 503,                   /* LOCAL  */
    LOCALTIME = 504,               /* LOCALTIME  */
    LOCALTIMESTAMP = 505,          /* LOCALTIMESTAMP  */
    LOCATION = 506,                /* LOCATION  */
    LOCK_P = 507,                  /* LOCK_P  */
    LOGIN_P = 508,                 /* LOGIN_P  */
    MATCH = 509,                   /* MATCH  */
    MAXVALUE = 510,                /* MAXVALUE  */
    MINUTE_P = 511,                /* MINUTE_P  */
    MINVALUE = 512,                /* MINVALUE  */
    MODE = 513,                    /* MODE  */
    MONTH_P = 514,                 /* MONTH_P  */
    MOVE = 515,                    /* MOVE  */
    NAMES = 516,                   /* NAMES  */
    NATIONAL = 517,                /* NATIONAL  */
    NATURAL = 518,                 /* NATURAL  */
    NCHAR = 519,                   /* NCHAR  */
    NEW = 520,                     /* NEW  */
    NEXT = 521,                    /* NEXT  */
    NO = 522,                      /* NO  */
    NOCREATEDB = 523,              /* NOCREATEDB  */
    NOCREATEROLE = 524,            /* NOCREATEROLE  */
    NOCREATEUSER = 525,            /* NOCREATEUSER  */
    NOINHERIT = 526,               /* NOINHERIT  */
    NOLOGIN_P = 527,               /* NOLOGIN_P  */
    NONE = 528,                    /* NONE  */
    NOSUPERUSER = 529,             /* NOSUPERUSER  */
    NOT = 530,                     /* NOT  */
    NOTHING = 531,                 /* NOTHING  */
    NOTIFY = 532,                  /* NOTIFY  */
    NOTNULL = 533,                 /* NOTNULL  */
    NOWAIT = 534,                  /* NOWAIT  */
    NULL_P = 535,                  /* NULL_P  */
    NULLIF = 536,                  /* NULLIF  */
    NUMERIC = 537,                 /* NUMERIC  */
    OBJECT_P = 538,                /* OBJECT_P  */
    OF = 539,                      /* OF  */
    OFF = 540,                     /* OFF  */
    OFFSET = 541,                  /* OFFSET  */
    OIDS = 542,                    /* OIDS  */
    OLD = 543,                     /* OLD  */
    ON = 544,                      /* ON  */
    ONLY = 545,                    /* ONLY  */
    OPERATOR = 546,                /* OPERATOR  */
    OPTION = 547,                  /* OPTION  */
    OR = 548,                      /* OR  */
    ORDER = 549,                   /* ORDER  */
    OUT_P = 550,                   /* OUT_P  */
    OUTER_P = 551,                 /* OUTER_P  */
    OVERLAPS = 552,                /* OVERLAPS  */
    OVERLAY = 553,                 /* OVERLAY  */
    OWNER = 554,                   /* OWNER  */
    PARTIAL = 555,                 /* PARTIAL  */
    PASSWORD = 556,                /* PASSWORD  */
    PLACING = 557,                 /* PLACING  */
    POSITION = 558,                /* POSITION  */
    PRECISION = 559,               /* PRECISION  */
    PRESERVE = 560,                /* PRESERVE  */
    PREPARE = 561,                 /* PREPARE  */
    PREPARED = 562,                /* PREPARED  */
    PRIMARY = 563,                 /* PRIMARY  */
    PRIOR = 564,                   /* PRIOR  */
    PRIVILEGES = 565,              /* PRIVILEGES  */
    PROCEDURAL = 566,              /* PROCEDURAL  */
    PROCEDURE = 567,               /* PROCEDURE  */
    QUOTE = 568,                   /* QUOTE  */
    READ = 569,                    /* READ  */
    REAL = 570,                    /* REAL  */
    RECHECK = 571,                 /* RECHECK  */
    REFERENCES = 572,              /* REFERENCES  */
    REINDEX = 573,                 /* REINDEX  */
    RELATIVE_P = 574,              /* RELATIVE_P  */
    RELEASE = 575,                 /* RELEASE  */
    RENAME = 576,                  /* RENAME  */
    REPEATABLE = 577,              /* REPEATABLE  */
    REPLACE = 578,                 /* REPLACE  */
    RESET = 579,                   /* RESET  */
    RESTART = 580,                 /* RESTART  */
    RESTRICT = 581,                /* RESTRICT  */
    RETURNS = 582,                 /* RETURNS  */
    REVOKE = 583,                  /* REVOKE  */
    RIGHT = 584,                   /* RIGHT  */
    ROLE = 585,                    /* ROLE  */
    ROLLBACK = 586,                /* ROLLBACK  */
    ROW = 587,                     /* ROW  */
    ROWS = 588,                    /* ROWS  */
    RULE = 589,                    /* RULE  */
    SAVEPOINT = 590,               /* SAVEPOINT  */
    SCHEMA = 591,                  /* SCHEMA  */
    SCROLL = 592,                  /* SCROLL  */
    SECOND_P = 593,                /* SECOND_P  */
    SECURITY = 594,                /* SECURITY  */
    SELECT = 595,                  /* SELECT  */
    SEQUENCE = 596,                /* SEQUENCE  */
    SERIALIZABLE = 597,            /* SERIALIZABLE  */
    SESSION = 598,                 /* SESSION  */
    SESSION_USER = 599,            /* SESSION_USER  */
    SET = 600,                     /* SET  */
    SETOF = 601,                   /* SETOF  */
    SHARE = 602,                   /* SHARE  */
    SHOW = 603,                    /* SHOW  */
    SIMILAR = 604,                 /* SIMILAR  */
    SIMPLE = 605,                  /* SIMPLE  */
    SMALLINT = 606,                /* SMALLINT  */
    SOME = 607,                    /* SOME  */
    STABLE = 608,                  /* STABLE  */
    START = 609,                   /* START  */
    STATEMENT = 610,               /* STATEMENT  */
    STATISTICS = 611,              /* STATISTICS  */
    STDIN = 612,                   /* STDIN  */
    STDOUT = 613,                  /* STDOUT  */
    STORAGE = 614,                 /* STORAGE  */
    STRICT_P = 615,                /* STRICT_P  */
    SUBSTRING = 616,               /* SUBSTRING  */
    SUPERUSER_P = 617,             /* SUPERUSER_P  */
    SYMMETRIC = 618,               /* SYMMETRIC  */
    SYSID = 619,                   /* SYSID  */
    SYSTEM_P = 620,                /* SYSTEM_P  */
    TABLE = 621,                   /* TABLE  */
    TABLESPACE = 622,              /* TABLESPACE  */
    TEMP = 623,                    /* TEMP  */
    TEMPLATE = 624,                /* TEMPLATE  */
    TEMPORARY = 625,               /* TEMPORARY  */
    THEN = 626,                    /* THEN  */
    TIME = 627,                    /* TIME  */
    TIMESTAMP = 628,               /* TIMESTAMP  */
    TO = 629,                      /* TO  */
    TOAST = 630,                   /* TOAST  */
    TRAILING = 631,                /* TRAILING  */
    TRANSACTION = 632,             /* TRANSACTION  */
    TREAT = 633,                   /* TREAT  */
    TRIGGER = 634,                 /* TRIGGER  */
    TRIM = 635,                    /* TRIM  */
    TRUE_P = 636,                  /* TRUE_P  */
    TRUNCATE = 637,                /* TRUNCATE  */
    TRUSTED = 638,                 /* TRUSTED  */
    TYPE_P = 639,                  /* TYPE_P  */
    UNCOMMITTED = 640,             /* UNCOMMITTED  */
    UNENCRYPTED = 641,             /* UNENCRYPTED  */
    UNION = 642,                   /* UNION  */
    UNIQUE = 643,                  /* UNIQUE  */
    UNKNOWN = 644,                 /* UNKNOWN  */
    UNLISTEN = 645,                /* UNLISTEN  */
    UNTIL = 646,                   /* UNTIL  */
    UPDATE = 647,                  /* UPDATE  */
    USER = 648,                    /* USER  */
    USING = 649,                   /* USING  */
    VACUUM = 650,                  /* VACUUM  */
    VALID = 651,                   /* VALID  */
    VALIDATOR = 652,               /* VALIDATOR  */
    VALUES = 653,                  /* VALUES  */
    VARCHAR = 654,                 /* VARCHAR  */
    VARYING = 655,                 /* VARYING  */
    VERBOSE = 656,                 /* VERBOSE  */
    VIEW = 657,                    /* VIEW  */
    VOLATILE = 658,                /* VOLATILE  */
    WHEN = 659,                    /* WHEN  */
    WHERE = 660,                   /* WHERE  */
    WITH = 661,                    /* WITH  */
    WITHOUT = 662,                 /* WITHOUT  */
    WORK = 663,                    /* WORK  */
    WRITE = 664,                   /* WRITE  */
    YEAR_P = 665,                  /* YEAR_P  */
    ZONE = 666,                    /* ZONE  */
    UNIONJOIN = 667,               /* UNIONJOIN  */
    IDENT = 668,                   /* IDENT  */
    SCONST = 669,                  /* SCONST  */
    Op = 670,                      /* Op  */
    CSTRING = 671,                 /* CSTRING  */
    CVARIABLE = 672,               /* CVARIABLE  */
    CPP_LINE = 673,                /* CPP_LINE  */
    IP = 674,                      /* IP  */
    BCONST = 675,                  /* BCONST  */
    XCONST = 676,                  /* XCONST  */
    ICONST = 677,                  /* ICONST  */
    PARAM = 678,                   /* PARAM  */
    FCONST = 679,                  /* FCONST  */
    POSTFIXOP = 680,               /* POSTFIXOP  */
    UMINUS = 681                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SQL_ALLOCATE 258
#define SQL_AUTOCOMMIT 259
#define SQL_BOOL 260
#define SQL_BREAK 261
#define SQL_CALL 262
#define SQL_CARDINALITY 263
#define SQL_CONNECT 264
#define SQL_CONTINUE 265
#define SQL_COUNT 266
#define SQL_CURRENT 267
#define SQL_DATA 268
#define SQL_DATETIME_INTERVAL_CODE 269
#define SQL_DATETIME_INTERVAL_PRECISION 270
#define SQL_DESCRIBE 271
#define SQL_DESCRIPTOR 272
#define SQL_DISCONNECT 273
#define SQL_ENUM 274
#define SQL_FOUND 275
#define SQL_FREE 276
#define SQL_GO 277
#define SQL_GOTO 278
#define SQL_IDENTIFIED 279
#define SQL_INDICATOR 280
#define SQL_KEY_MEMBER 281
#define SQL_LENGTH 282
#define SQL_LONG 283
#define SQL_NAME 284
#define SQL_NULLABLE 285
#define SQL_OCTET_LENGTH 286
#define SQL_OPEN 287
#define SQL_OUTPUT 288
#define SQL_REFERENCE 289
#define SQL_RETURNED_LENGTH 290
#define SQL_RETURNED_OCTET_LENGTH 291
#define SQL_SCALE 292
#define SQL_SECTION 293
#define SQL_SHORT 294
#define SQL_SIGNED 295
#define SQL_SQL 296
#define SQL_SQLERROR 297
#define SQL_SQLPRINT 298
#define SQL_SQLWARNING 299
#define SQL_START 300
#define SQL_STOP 301
#define SQL_STRUCT 302
#define SQL_UNSIGNED 303
#define SQL_VALUE 304
#define SQL_VAR 305
#define SQL_WHENEVER 306
#define S_ADD 307
#define S_AND 308
#define S_ANYTHING 309
#define S_AUTO 310
#define S_CONST 311
#define S_DEC 312
#define S_DIV 313
#define S_DOTPOINT 314
#define S_EQUAL 315
#define S_EXTERN 316
#define S_INC 317
#define S_LSHIFT 318
#define S_MEMPOINT 319
#define S_MEMBER 320
#define S_MOD 321
#define S_MUL 322
#define S_NEQUAL 323
#define S_OR 324
#define S_REGISTER 325
#define S_RSHIFT 326
#define S_STATIC 327
#define S_SUB 328
#define S_VOLATILE 329
#define S_TYPEDEF 330
#define TYPECAST 331
#define ABORT_P 332
#define ABSOLUTE_P 333
#define ACCESS 334
#define ACTION 335
#define ADD 336
#define ADMIN 337
#define AFTER 338
#define AGGREGATE 339
#define ALL 340
#define ALSO 341
#define ALTER 342
#define ANALYSE 343
#define ANALYZE 344
#define AND 345
#define ANY 346
#define ARRAY 347
#define AS 348
#define ASC 349
#define ASSERTION 350
#define ASSIGNMENT 351
#define ASYMMETRIC 352
#define AT 353
#define AUTHORIZATION 354
#define BACKWARD 355
#define BEFORE 356
#define BEGIN_P 357
#define BETWEEN 358
#define BIGINT 359
#define BINARY 360
#define BIT 361
#define BOOLEAN_P 362
#define BOTH 363
#define BY 364
#define CACHE 365
#define CALLED 366
#define CASCADE 367
#define CASE 368
#define CAST 369
#define CHAIN 370
#define CHAR_P 371
#define CHARACTER 372
#define CHARACTERISTICS 373
#define CHECK 374
#define CHECKPOINT 375
#define CLASS 376
#define CLOSE 377
#define CLUSTER 378
#define COALESCE 379
#define COLLATE 380
#define COLUMN 381
#define COMMENT 382
#define COMMIT 383
#define COMMITTED 384
#define CONNECTION 385
#define CONSTRAINT 386
#define CONSTRAINTS 387
#define CONVERSION_P 388
#define CONVERT 389
#define COPY 390
#define CREATE 391
#define CREATEDB 392
#define CREATEROLE 393
#define CREATEUSER 394
#define CROSS 395
#define CSV 396
#define CURRENT_DATE 397
#define CURRENT_ROLE 398
#define CURRENT_TIME 399
#define CURRENT_TIMESTAMP 400
#define CURRENT_USER 401
#define CURSOR 402
#define CYCLE 403
#define DATABASE 404
#define DAY_P 405
#define DEALLOCATE 406
#define DEC 407
#define DECIMAL_P 408
#define DECLARE 409
#define DEFAULT 410
#define DEFAULTS 411
#define DEFERRABLE 412
#define DEFERRED 413
#define DEFINER 414
#define DELETE_P 415
#define DELIMITER 416
#define DELIMITERS 417
#define DESC 418
#define DISABLE_P 419
#define DISTINCT 420
#define DO 421
#define DOMAIN_P 422
#define DOUBLE_P 423
#define DROP 424
#define EACH 425
#define ELSE 426
#define ENABLE_P 427
#define ENCODING 428
#define ENCRYPTED 429
#define END_P 430
#define ESCAPE 431
#define EXCEPT 432
#define EXCLUSIVE 433
#define EXCLUDING 434
#define EXECUTE 435
#define EXISTS 436
#define EXPLAIN 437
#define EXTERNAL 438
#define EXTRACT 439
#define FALSE_P 440
#define FETCH 441
#define FIRST_P 442
#define FLOAT_P 443
#define FOR 444
#define FORCE 445
#define FOREIGN 446
#define FORWARD 447
#define FREEZE 448
#define FROM 449
#define FULL 450
#define FUNCTION 451
#define GET 452
#define GLOBAL 453
#define GRANT 454
#define GRANTED 455
#define GREATEST 456
#define GROUP_P 457
#define HANDLER 458
#define HAVING 459
#define HEADER 460
#define HOLD 461
#define HOUR_P 462
#define ILIKE 463
#define IMMEDIATE 464
#define IMMUTABLE 465
#define IMPLICIT_P 466
#define IN_P 467
#define INCLUDING 468
#define INCREMENT 469
#define INDEX 470
#define INHERIT 471
#define INHERITS 472
#define INITIALLY 473
#define INNER_P 474
#define INOUT 475
#define INPUT_P 476
#define INSENSITIVE 477
#define INSERT 478
#define INSTEAD 479
#define INT_P 480
#define INTEGER 481
#define INTERSECT 482
#define INTERVAL 483
#define INTO 484
#define INVOKER 485
#define IS 486
#define ISNULL 487
#define ISOLATION 488
#define JOIN 489
#define KEY 490
#define LANCOMPILER 491
#define LANGUAGE 492
#define LARGE_P 493
#define LAST_P 494
#define LEADING 495
#define LEAST 496
#define LEFT 497
#define LEVEL 498
#define LIKE 499
#define LIMIT 500
#define LISTEN 501
#define LOAD 502
#define LOCAL 503
#define LOCALTIME 504
#define LOCALTIMESTAMP 505
#define LOCATION 506
#define LOCK_P 507
#define LOGIN_P 508
#define MATCH 509
#define MAXVALUE 510
#define MINUTE_P 511
#define MINVALUE 512
#define MODE 513
#define MONTH_P 514
#define MOVE 515
#define NAMES 516
#define NATIONAL 517
#define NATURAL 518
#define NCHAR 519
#define NEW 520
#define NEXT 521
#define NO 522
#define NOCREATEDB 523
#define NOCREATEROLE 524
#define NOCREATEUSER 525
#define NOINHERIT 526
#define NOLOGIN_P 527
#define NONE 528
#define NOSUPERUSER 529
#define NOT 530
#define NOTHING 531
#define NOTIFY 532
#define NOTNULL 533
#define NOWAIT 534
#define NULL_P 535
#define NULLIF 536
#define NUMERIC 537
#define OBJECT_P 538
#define OF 539
#define OFF 540
#define OFFSET 541
#define OIDS 542
#define OLD 543
#define ON 544
#define ONLY 545
#define OPERATOR 546
#define OPTION 547
#define OR 548
#define ORDER 549
#define OUT_P 550
#define OUTER_P 551
#define OVERLAPS 552
#define OVERLAY 553
#define OWNER 554
#define PARTIAL 555
#define PASSWORD 556
#define PLACING 557
#define POSITION 558
#define PRECISION 559
#define PRESERVE 560
#define PREPARE 561
#define PREPARED 562
#define PRIMARY 563
#define PRIOR 564
#define PRIVILEGES 565
#define PROCEDURAL 566
#define PROCEDURE 567
#define QUOTE 568
#define READ 569
#define REAL 570
#define RECHECK 571
#define REFERENCES 572
#define REINDEX 573
#define RELATIVE_P 574
#define RELEASE 575
#define RENAME 576
#define REPEATABLE 577
#define REPLACE 578
#define RESET 579
#define RESTART 580
#define RESTRICT 581
#define RETURNS 582
#define REVOKE 583
#define RIGHT 584
#define ROLE 585
#define ROLLBACK 586
#define ROW 587
#define ROWS 588
#define RULE 589
#define SAVEPOINT 590
#define SCHEMA 591
#define SCROLL 592
#define SECOND_P 593
#define SECURITY 594
#define SELECT 595
#define SEQUENCE 596
#define SERIALIZABLE 597
#define SESSION 598
#define SESSION_USER 599
#define SET 600
#define SETOF 601
#define SHARE 602
#define SHOW 603
#define SIMILAR 604
#define SIMPLE 605
#define SMALLINT 606
#define SOME 607
#define STABLE 608
#define START 609
#define STATEMENT 610
#define STATISTICS 611
#define STDIN 612
#define STDOUT 613
#define STORAGE 614
#define STRICT_P 615
#define SUBSTRING 616
#define SUPERUSER_P 617
#define SYMMETRIC 618
#define SYSID 619
#define SYSTEM_P 620
#define TABLE 621
#define TABLESPACE 622
#define TEMP 623
#define TEMPLATE 624
#define TEMPORARY 625
#define THEN 626
#define TIME 627
#define TIMESTAMP 628
#define TO 629
#define TOAST 630
#define TRAILING 631
#define TRANSACTION 632
#define TREAT 633
#define TRIGGER 634
#define TRIM 635
#define TRUE_P 636
#define TRUNCATE 637
#define TRUSTED 638
#define TYPE_P 639
#define UNCOMMITTED 640
#define UNENCRYPTED 641
#define UNION 642
#define UNIQUE 643
#define UNKNOWN 644
#define UNLISTEN 645
#define UNTIL 646
#define UPDATE 647
#define USER 648
#define USING 649
#define VACUUM 650
#define VALID 651
#define VALIDATOR 652
#define VALUES 653
#define VARCHAR 654
#define VARYING 655
#define VERBOSE 656
#define VIEW 657
#define VOLATILE 658
#define WHEN 659
#define WHERE 660
#define WITH 661
#define WITHOUT 662
#define WORK 663
#define WRITE 664
#define YEAR_P 665
#define ZONE 666
#define UNIONJOIN 667
#define IDENT 668
#define SCONST 669
#define Op 670
#define CSTRING 671
#define CVARIABLE 672
#define CPP_LINE 673
#define IP 674
#define BCONST 675
#define XCONST 676
#define ICONST 677
#define PARAM 678
#define FCONST 679
#define POSTFIXOP 680
#define UMINUS 681

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 311 "preproc.y"

	double	dval;
	char	*str;
	int     ival;
	struct	when		action;
	struct	index		index;
	int		tagname;
	struct	this_type	type;
	enum	ECPGttype	type_enum;
	enum	ECPGdtype	dtype_enum;
	struct	fetch_desc	descriptor;
	struct  su_symbol	struct_union;

#line 933 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
