#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20101229

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 26 "ftpcmd.y"

#ifndef lint
static char sccsid[] = "@(#)ftpcmd.y	5.20 (Berkeley) 2/28/89";
#endif /* not lint */

#include <sys/param.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/ftp.h>

#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <pwd.h>
#include <setjmp.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>

#include <string.h>
#include <stdlib.h>

extern	struct sockaddr_in data_dest;
extern	int logged_in;
extern	struct passwd *pw;
extern	int guest;
extern	int logging;
extern	int type;
extern	int form;
extern	int debug;
extern	int timeout;
extern	int maxtimeout;
extern  int pdata;
extern	char hostname[], remotehost[];
extern	char proctitle[];
extern	char *globerr;
extern	int usedefault;
extern  int transflag;
extern  char tmpline[];
char	**glob();

off_t	restart_point;

static	int cmd_type;
static	int cmd_form;
static	int cmd_bytesz;
char	cbuf[512];
char	*fromname;

char	*index();

 /*struct tab cmdtab[], sitetab[];*/
#line 74 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define A 257
#define B 258
#define C 259
#define E 260
#define F 261
#define I 262
#define L 263
#define N 264
#define P 265
#define R 266
#define S 267
#define T 268
#define SP 269
#define CRLF 270
#define COMMA 271
#define STRING 272
#define NUMBER 273
#define USER 274
#define PASS 275
#define ACCT 276
#define REIN 277
#define QUIT 278
#define PORT 279
#define PASV 280
#define TYPE 281
#define STRU 282
#define MODE 283
#define RETR 284
#define STOR 285
#define APPE 286
#define MLFL 287
#define MAIL 288
#define MSND 289
#define MSOM 290
#define MSAM 291
#define MRSQ 292
#define MRCP 293
#define ALLO 294
#define REST 295
#define RNFR 296
#define RNTO 297
#define ABOR 298
#define DELE 299
#define CWD 300
#define LIST 301
#define NLST 302
#define SITE 303
#define STAT 304
#define HELP 305
#define NOOP 306
#define MKD 307
#define RMD 308
#define PWD 309
#define CDUP 310
#define STOU 311
#define SMNT 312
#define SYST 313
#define SIZE 314
#define MDTM 315
#define UMASK 316
#define IDLE 317
#define CHMOD 318
#define LEXERR 319
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    4,
    4,   12,    5,   13,   13,   13,    6,    6,    6,    6,
    6,    6,    6,    6,    7,    7,    7,    8,    8,    8,
   10,   14,   11,    9,
};
static const short yylen[] = {                            2,
    0,    2,    2,    4,    4,    4,    2,    4,    4,    4,
    4,    8,    5,    5,    5,    3,    5,    3,    5,    5,
    2,    5,    4,    2,    3,    5,    2,    4,    2,    5,
    5,    3,    3,    4,    6,    5,    7,    9,    4,    6,
    5,    2,    5,    5,    2,    2,    5,    4,    1,    0,
    1,    1,   11,    1,    1,    1,    1,    3,    1,    3,
    1,    1,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   74,   74,   74,    0,    0,   74,    0,    0,   74,   74,
   74,   74,    0,    0,    0,    0,   74,   74,   74,   74,
   74,    0,   74,   74,    2,    3,   46,    0,    0,   45,
    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,    0,    0,    0,    0,    0,   21,    0,
    0,   27,   29,    0,    0,    0,    0,    0,   42,    0,
    0,   49,    0,   51,    0,    0,    0,    0,    0,   61,
    0,    0,   65,   67,   66,    0,   69,   70,   68,    0,
    0,    0,    0,    0,   52,    0,    0,   72,    0,   71,
    0,    0,   25,    0,   18,    0,   16,    0,   74,    0,
   74,    0,    0,    0,    0,   32,   33,    0,    0,    0,
    4,    5,    0,    6,    0,    0,    0,   64,    8,    9,
   10,    0,    0,    0,    0,   11,   48,    0,   23,    0,
    0,    0,    0,    0,   34,    0,    0,   39,    0,    0,
   28,    0,    0,    0,    0,    0,    0,   56,   54,   55,
   58,   60,   63,   13,   14,   15,    0,   47,   22,   26,
   19,   17,    0,    0,   36,    0,    0,   20,   30,   31,
   41,   43,   44,    0,    0,   35,   73,    0,   40,    0,
    0,    0,   37,    0,    0,   12,    0,    0,   38,    0,
    0,    0,   53,
};
static const short yydgoto[] = {                          1,
   35,   36,   73,   75,   77,   82,   86,   90,   46,   99,
  188,   96,  161,  100,
};
static const short yysindex[] = {                         0,
 -221, -265, -262, -257, -234, -249, -229, -199, -174, -161,
    0,    0,    0, -160, -159,    0, -158, -157,    0,    0,
    0,    0, -155, -154, -244, -153,    0,    0,    0,    0,
    0, -152,    0,    0,    0,    0,    0, -253, -151,    0,
 -150,    0, -191, -164, -250, -149, -147, -145, -148, -143,
 -141, -146,    0, -138, -237, -226, -214, -302,    0, -137,
 -139,    0,    0, -135, -134, -133, -132, -130,    0, -129,
 -128,    0, -127,    0, -126, -156, -125, -123, -122,    0,
 -251, -121,    0,    0,    0, -120,    0,    0,    0, -119,
 -146, -146, -146, -202,    0, -118, -146,    0, -117,    0,
 -146, -146,    0, -146,    0, -136,    0, -171,    0, -165,
    0, -146, -116, -146, -146,    0,    0, -146, -146, -146,
    0,    0, -131,    0, -168, -168, -143,    0,    0,    0,
    0, -115, -114, -113, -108,    0,    0, -111,    0, -110,
 -109, -107, -106, -124,    0, -163, -105,    0, -104, -103,
    0, -101, -100,  -99,  -98,  -97,  -96,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -95,    0,    0,    0,
    0,    0,  -94,  -93,    0,  -92,  -93,    0,    0,    0,
    0,    0,    0,  -90,  -89,    0,    0,  -88,    0,  -84,
  -85,  -83,    0, -146,  -82,    0,  -81,  -79,    0,  -80,
  -76,  -75,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -71,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -70, -154,    0,
  -69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,  -91,
  -65,  -77,   -7,    0,
};
#define YYTABLESIZE 201
static const short yytable[] = {                        132,
  133,  134,  108,  128,   37,  138,   38,   87,   88,  140,
  141,   39,  142,  109,  110,  111,   89,  127,   72,   41,
  150,   95,  152,  153,   61,   62,  154,  155,  156,   47,
   48,  102,  103,   51,    2,   40,   54,   55,   56,   57,
   42,   60,  104,  105,   64,   65,   66,   67,   68,  163,
   70,   71,    3,    4,  106,  107,    5,    6,    7,    8,
    9,   10,   11,   12,   13,   78,  135,  136,   79,   43,
   80,   81,   14,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
  158,   32,   33,   34,   44,  159,   83,  144,  145,  160,
   84,   85,  197,  147,  148,  174,  175,   45,   49,   50,
   52,  190,   53,   58,  123,   59,   63,   69,  162,   91,
   74,   92,   76,   93,   94,   98,  146,   97,  149,   95,
  101,  112,  113,  114,  115,  143,  116,  117,  118,  119,
  120,  157,  121,  122,  124,  125,  126,  173,  129,  130,
  131,  137,  139,  151,  164,  165,  166,  167,  168,  169,
  170,    0,  171,  172,  177,    0,  178,  176,  179,  180,
  181,  182,  183,  185,  184,  186,    0,  189,    0,  187,
    0,  193,  191,  192,  194,  195,  196,    0,  199,    0,
  198,  200,  201,    0,  202,   74,    0,  203,   50,   57,
   62,
};
static const short yycheck[] = {                         91,
   92,   93,  305,   81,  270,   97,  269,  258,  259,  101,
  102,  269,  104,  316,  317,  318,  267,  269,  272,  269,
  112,  273,  114,  115,  269,  270,  118,  119,  120,   12,
   13,  269,  270,   16,  256,  270,   19,   20,   21,   22,
  270,   24,  269,  270,   27,   28,   29,   30,   31,  127,
   33,   34,  274,  275,  269,  270,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  257,  269,  270,  260,  269,
  262,  263,  294,  295,  296,  297,  298,  299,  300,  301,
  302,  303,  304,  305,  306,  307,  308,  309,  310,  311,
  259,  313,  314,  315,  269,  264,  261,  269,  270,  268,
  265,  266,  194,  269,  270,  269,  270,  269,  269,  269,
  269,  177,  270,  269,  271,  270,  270,  270,  126,  269,
  272,  269,  273,  269,  273,  272,  109,  269,  111,  273,
  269,  269,  272,  269,  269,  272,  270,  270,  269,  269,
  269,  273,  270,  270,  270,  269,  269,  272,  270,  270,
  270,  270,  270,  270,  270,  270,  270,  266,  270,  270,
  270,   -1,  270,  270,  269,   -1,  270,  273,  270,  270,
  270,  270,  270,  269,  271,  270,   -1,  270,   -1,  273,
   -1,  270,  273,  273,  269,  271,  270,   -1,  270,   -1,
  273,  271,  273,   -1,  271,  269,   -1,  273,  270,  270,
  270,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 319
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"A","B","C","E","F","I","L","N",
"P","R","S","T","SP","CRLF","COMMA","STRING","NUMBER","USER","PASS","ACCT",
"REIN","QUIT","PORT","PASV","TYPE","STRU","MODE","RETR","STOR","APPE","MLFL",
"MAIL","MSND","MSOM","MSAM","MRSQ","MRCP","ALLO","REST","RNFR","RNTO","ABOR",
"DELE","CWD","LIST","NLST","SITE","STAT","HELP","NOOP","MKD","RMD","PWD","CDUP",
"STOU","SMNT","SYST","SIZE","MDTM","UMASK","IDLE","CHMOD","LEXERR",
};
static const char *yyrule[] = {
"$accept : cmd_list",
"cmd_list :",
"cmd_list : cmd_list cmd",
"cmd_list : cmd_list rcmd",
"cmd : USER SP username CRLF",
"cmd : PASS SP password CRLF",
"cmd : PORT SP host_port CRLF",
"cmd : PASV CRLF",
"cmd : TYPE SP type_code CRLF",
"cmd : STRU SP struct_code CRLF",
"cmd : MODE SP mode_code CRLF",
"cmd : ALLO SP NUMBER CRLF",
"cmd : ALLO SP NUMBER SP R SP NUMBER CRLF",
"cmd : RETR check_login SP pathname CRLF",
"cmd : STOR check_login SP pathname CRLF",
"cmd : APPE check_login SP pathname CRLF",
"cmd : NLST check_login CRLF",
"cmd : NLST check_login SP STRING CRLF",
"cmd : LIST check_login CRLF",
"cmd : LIST check_login SP pathname CRLF",
"cmd : STAT check_login SP pathname CRLF",
"cmd : STAT CRLF",
"cmd : DELE check_login SP pathname CRLF",
"cmd : RNTO SP pathname CRLF",
"cmd : ABOR CRLF",
"cmd : CWD check_login CRLF",
"cmd : CWD check_login SP pathname CRLF",
"cmd : HELP CRLF",
"cmd : HELP SP STRING CRLF",
"cmd : NOOP CRLF",
"cmd : MKD check_login SP pathname CRLF",
"cmd : RMD check_login SP pathname CRLF",
"cmd : PWD check_login CRLF",
"cmd : CDUP check_login CRLF",
"cmd : SITE SP HELP CRLF",
"cmd : SITE SP HELP SP STRING CRLF",
"cmd : SITE SP UMASK check_login CRLF",
"cmd : SITE SP UMASK check_login SP octal_number CRLF",
"cmd : SITE SP CHMOD check_login SP octal_number SP pathname CRLF",
"cmd : SITE SP IDLE CRLF",
"cmd : SITE SP IDLE SP NUMBER CRLF",
"cmd : STOU check_login SP pathname CRLF",
"cmd : SYST CRLF",
"cmd : SIZE check_login SP pathname CRLF",
"cmd : MDTM check_login SP pathname CRLF",
"cmd : QUIT CRLF",
"cmd : error CRLF",
"rcmd : RNFR check_login SP pathname CRLF",
"rcmd : REST SP byte_size CRLF",
"username : STRING",
"password :",
"password : STRING",
"byte_size : NUMBER",
"host_port : NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER",
"form_code : N",
"form_code : T",
"form_code : C",
"type_code : A",
"type_code : A SP form_code",
"type_code : E",
"type_code : E SP form_code",
"type_code : I",
"type_code : L",
"type_code : L SP byte_size",
"type_code : L byte_size",
"struct_code : F",
"struct_code : R",
"struct_code : P",
"mode_code : S",
"mode_code : B",
"mode_code : C",
"pathname : pathstring",
"pathstring : STRING",
"octal_number : NUMBER",
"check_login :",

};
#endif
/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 676 "ftpcmd.y"

extern jmp_buf errcatch;

#define	CMD	0	/* beginning of command */
#define	ARGS	1	/* expect miscellaneous arguments */
#define	STR1	2	/* expect SP followed by STRING */
#define	STR2	3	/* expect STRING */
#define	OSTR	4	/* optional SP then STRING */
#define	ZSTR1	5	/* SP then optional STRING */
#define	ZSTR2	6	/* optional STRING after SP */
#define	SITECMD	7	/* SITE command */
#define	NSTR	8	/* Number followed by a string */

struct tab {
	char	*name;
	short	token;
	short	state;
	short	implemented;	/* 1 if command is implemented */
	char	*help;
};

struct tab cmdtab[] = {		/* In order defined in RFC 765 */
	{ "USER", USER, STR1, 1,	"<sp> username" },
	{ "PASS", PASS, ZSTR1, 1,	"<sp> password" },
	{ "ACCT", ACCT, STR1, 0,	"(specify account)" },
	{ "SMNT", SMNT, ARGS, 0,	"(structure mount)" },
	{ "REIN", REIN, ARGS, 0,	"(reinitialize server state)" },
	{ "QUIT", QUIT, ARGS, 1,	"(terminate service)", },
	{ "PORT", PORT, ARGS, 1,	"<sp> b0, b1, b2, b3, b4" },
	{ "PASV", PASV, ARGS, 1,	"(set server in passive mode)" },
	{ "TYPE", TYPE, ARGS, 1,	"<sp> [ A | E | I | L ]" },
	{ "STRU", STRU, ARGS, 1,	"(specify file structure)" },
	{ "MODE", MODE, ARGS, 1,	"(specify transfer mode)" },
	{ "RETR", RETR, STR1, 1,	"<sp> file-name" },
	{ "STOR", STOR, STR1, 1,	"<sp> file-name" },
	{ "APPE", APPE, STR1, 1,	"<sp> file-name" },
	{ "MLFL", MLFL, OSTR, 0,	"(mail file)" },
	{ "MAIL", MAIL, OSTR, 0,	"(mail to user)" },
	{ "MSND", MSND, OSTR, 0,	"(mail send to terminal)" },
	{ "MSOM", MSOM, OSTR, 0,	"(mail send to terminal or mailbox)" },
	{ "MSAM", MSAM, OSTR, 0,	"(mail send to terminal and mailbox)" },
	{ "MRSQ", MRSQ, OSTR, 0,	"(mail recipient scheme question)" },
	{ "MRCP", MRCP, STR1, 0,	"(mail recipient)" },
	{ "ALLO", ALLO, ARGS, 1,	"allocate storage (vacuously)" },
	{ "REST", REST, ARGS, 1,	"(restart command)" },
	{ "RNFR", RNFR, STR1, 1,	"<sp> file-name" },
	{ "RNTO", RNTO, STR1, 1,	"<sp> file-name" },
	{ "ABOR", ABOR, ARGS, 1,	"(abort operation)" },
	{ "DELE", DELE, STR1, 1,	"<sp> file-name" },
	{ "CWD",  CWD,  OSTR, 1,	"[ <sp> directory-name ]" },
	{ "XCWD", CWD,	OSTR, 1,	"[ <sp> directory-name ]" },
	{ "LIST", LIST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "NLST", NLST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "SITE", SITE, SITECMD, 1,	"site-cmd [ <sp> arguments ]" },
	{ "SYST", SYST, ARGS, 1,	"(get type of operating system)" },
	{ "STAT", STAT, OSTR, 1,	"[ <sp> path-name ]" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ "NOOP", NOOP, ARGS, 1,	"" },
	{ "MKD",  MKD,  STR1, 1,	"<sp> path-name" },
	{ "XMKD", MKD,  STR1, 1,	"<sp> path-name" },
	{ "RMD",  RMD,  STR1, 1,	"<sp> path-name" },
	{ "XRMD", RMD,  STR1, 1,	"<sp> path-name" },
	{ "PWD",  PWD,  ARGS, 1,	"(return current directory)" },
	{ "XPWD", PWD,  ARGS, 1,	"(return current directory)" },
	{ "CDUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "XCUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "STOU", STOU, STR1, 1,	"<sp> file-name" },
	{ "SIZE", SIZE, OSTR, 1,	"<sp> path-name" },
	{ "MDTM", MDTM, OSTR, 1,	"<sp> path-name" },
	{ NULL,   0,    0,    0,	0 }
};

struct tab sitetab[] = {
	{ "UMASK", UMASK, ARGS, 1,	"[ <sp> umask ]" },
	{ "IDLE", IDLE, ARGS, 1,	"[ <sp> maximum-idle-time ]" },
	{ "CHMOD", CHMOD, NSTR, 1,	"<sp> mode <sp> file-name" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ NULL,   0,    0,    0,	0 }
};

struct tab *
lookup(p, cmd)
	register struct tab *p;
	char *cmd;
{

	for (; p->name != NULL; p++)
		if (strcmp(cmd, p->name) == 0)
			return (p);
	return (0);
}

#include <arpa/telnet.h>

/*
 * getlineX - a hacked up version of fgets to ignore TELNET escape codes.
 */
char *
getlineX(s, n, iop)
	char *s;
	register FILE *iop;
{
	register c;
	register char *cs;

	cs = s;
/* tmpline may contain saved command from urgent mode interruption */
	for (c = 0; tmpline[c] != '\0' && --n > 0; ++c) {
		*cs++ = tmpline[c];
		if (tmpline[c] == '\n') {
			*cs++ = '\0';
			if (debug)
				syslog(LOG_DEBUG, "command: %s", s);
			tmpline[0] = '\0';
			return(s);
		}
		if (c == 0)
			tmpline[0] = '\0';
	}
	while ((c = getc(iop)) != EOF) {
		c &= 0377;
		if (c == IAC) {
		    if ((c = getc(iop)) != EOF) {
			c &= 0377;
			switch (c) {
			case WILL:
			case WONT:
				c = getc(iop);
				printf("%c%c%c", IAC, DONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case DO:
			case DONT:
				c = getc(iop);
				printf("%c%c%c", IAC, WONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case IAC:
				break;
			default:
				continue;	/* ignore command */
			}
		    }
		}
		*cs++ = c;
		if (--n <= 0 || c == '\n')
			break;
	}
	if (c == EOF && cs == s)
		return (NULL);
	*cs++ = '\0';
	if (debug)
		syslog(LOG_DEBUG, "command: %s", s);
	return (s);
}

static int
toolong()
{
	time_t now;
	extern char *ctime();
	extern time_t time();

	reply(421,
	  "Timeout (%d seconds): closing control connection.", timeout);
	(void) time(&now);
	if (logging) {
		syslog(LOG_INFO,
			"User %s timed out after %d seconds at %s",
			(pw ? pw -> pw_name : "unknown"), timeout, ctime(&now));
	}
	dologout(1);
}

yylex()
{
	static int cpos, state;
	register char *cp, *cp2;
	register struct tab *p;
	int n;
	char c, *strpbrk();
	char *copy();

	for (;;) {
		switch (state) {

		case CMD:
			(void) signal(SIGALRM, toolong);
			(void) alarm((unsigned) timeout);
			if (getlineX(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
				reply(221, "You could at least say goodbye.");
				dologout(0);
			}
			(void) alarm(0);
#ifdef SETPROCTITLE
			if (strncasecmp(cbuf, "PASS", 4) != NULL)
				setproctitle("%s: %s", proctitle, cbuf);
#endif /* SETPROCTITLE */
			if ((cp = index(cbuf, '\r'))) {
				*cp++ = '\n';
				*cp = '\0';
			}
			if ((cp = strpbrk(cbuf, " \n")))
				cpos = cp - cbuf;
			if (cpos == 0)
				cpos = 4;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cbuf);
			p = lookup(cmdtab, cbuf);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					nack(p->name);
					longjmp(errcatch,0);
					/* NOTREACHED */
				}
				state = p->state;
				*(char **)&yylval = p->name;
				return (p->token);
			}
			break;

		case SITECMD:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			cp = &cbuf[cpos];
			if ((cp2 = strpbrk(cp, " \n")))
				cpos = cp2 - cbuf;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cp);
			p = lookup(sitetab, cp);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					state = CMD;
					nack(p->name);
					longjmp(errcatch,0);
					/* NOTREACHED */
				}
				state = p->state;
				*(char **)&yylval = p->name;
				return (p->token);
			}
			state = CMD;
			break;

		case OSTR:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR1:
		case ZSTR1:
		dostr1:
			if (cbuf[cpos] == ' ') {
				cpos++;
				state = state == OSTR ? STR2 : ++state;
				return (SP);
			}
			break;

		case ZSTR2:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR2:
			cp = &cbuf[cpos];
			n = strlen(cp);
			cpos += n - 1;
			/*
			 * Make sure the string is nonempty and \n terminated.
			 */
			if (n > 1 && cbuf[cpos] == '\n') {
				cbuf[cpos] = '\0';
				*(char **)&yylval = copy(cp);
				cbuf[cpos] = '\n';
				state = ARGS;
				return (STRING);
			}
			break;

		case NSTR:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval = atoi(cp);
				cbuf[cpos] = c;
				state = STR1;
				return (NUMBER);
			}
			state = STR1;
			goto dostr1;

		case ARGS:
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval = atoi(cp);
				cbuf[cpos] = c;
				return (NUMBER);
			}
			switch (cbuf[cpos++]) {

			case '\n':
				state = CMD;
				return (CRLF);

			case ' ':
				return (SP);

			case ',':
				return (COMMA);

			case 'A':
			case 'a':
				return (A);

			case 'B':
			case 'b':
				return (B);

			case 'C':
			case 'c':
				return (C);

			case 'E':
			case 'e':
				return (E);

			case 'F':
			case 'f':
				return (F);

			case 'I':
			case 'i':
				return (I);

			case 'L':
			case 'l':
				return (L);

			case 'N':
			case 'n':
				return (N);

			case 'P':
			case 'p':
				return (P);

			case 'R':
			case 'r':
				return (R);

			case 'S':
			case 's':
				return (S);

			case 'T':
			case 't':
				return (T);

			}
			break;

		default:
			fatal("Unknown state in scanner.");
		}
		yyerror((char *) 0);
		state = CMD;
		longjmp(errcatch,0);
	}
}

upper(s)
	register char *s;
{
	while (*s != '\0') {
		if (islower(*s))
			*s = toupper(*s);
		s++;
	}
}

char *
copy(s)
	char *s;
{
	char *p;
	//extern char *malloc(), *strcpy();

	p = malloc((unsigned) strlen(s) + 1);
	if (p == NULL)
		fatal("Ran out of memory.");
	(void) strcpy(p, s);
	return (p);
}

help(ctab, s)
	struct tab *ctab;
	char *s;
{
	register struct tab *c;
	register int width, NCMDS;
	char *type;

	if (ctab == sitetab)
		type = "SITE ";
	else
		type = "";
	width = 0, NCMDS = 0;
	for (c = ctab; c->name != NULL; c++) {
		int len = strlen(c->name);

		if (len > width)
			width = len;
		NCMDS++;
	}
	width = (width + 8) &~ 7;
	if (s == 0) {
		register int i, j, w;
		int columns, lines;

		lreply(214, "The following %scommands are recognized %s.",
		    type, "(* =>'s unimplemented)");
		columns = 76 / width;
		if (columns == 0)
			columns = 1;
		lines = (NCMDS + columns - 1) / columns;
		for (i = 0; i < lines; i++) {
			printf("   ");
			for (j = 0; j < columns; j++) {
				c = ctab + j * lines + i;
				printf("%s%c", c->name,
					c->implemented ? ' ' : '*');
				if (c + lines >= &ctab[NCMDS])
					break;
				w = strlen(c->name) + 1;
				while (w < width) {
					putchar(' ');
					w++;
				}
			}
			printf("\r\n");
		}
		(void) fflush(stdout);
		reply(214, "Direct comments to ftp-bugs@%s.", hostname);
		return;
	}
	upper(s);
	c = lookup(ctab, s);
	if (c == (struct tab *)0) {
		reply(502, "Unknown command %s.", s);
		return;
	}
	if (c->implemented)
		reply(214, "Syntax: %s%s %s", type, c->name, c->help);
	else
		reply(214, "%s%-*s\t%s; unimplemented.", type, width,
		    c->name, c->help);
}

sizecmd(filename)
char *filename;
{
	switch (type) {
	case TYPE_L:
	case TYPE_I: {
		struct stat stbuf;
		if (stat(filename, &stbuf) < 0 ||
		    (stbuf.st_mode&S_IFMT) != S_IFREG)
			reply(550, "%s: not a plain file.", filename);
		else
			reply(213, "%lu", stbuf.st_size);
		break;}
	case TYPE_A: {
		FILE *fin;
		register int c, count;
		struct stat stbuf;
		fin = fopen(filename, "r");
		if (fin == NULL) {
			perror_reply(550, filename);
			return;
		}
		if (fstat(fileno(fin), &stbuf) < 0 ||
		    (stbuf.st_mode&S_IFMT) != S_IFREG) {
			reply(550, "%s: not a plain file.", filename);
			(void) fclose(fin);
			return;
		}

		count = 0;
		while((c=getc(fin)) != EOF) {
			if (c == '\n')	/* will get expanded to \r\n */
				count++;
			count++;
		}
		(void) fclose(fin);

		reply(213, "%ld", count);
		break;}
	default:
		reply(504, "SIZE not implemented for Type %c.", "?AEIL"[type]);
	}
}
#line 972 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 106 "ftpcmd.y"
	{
			fromname = (char *) 0;
			restart_point = (off_t) 0;
		}
break;
case 4:
#line 114 "ftpcmd.y"
	{
			user((char *) yystack.l_mark[-1]);
			free((char *) yystack.l_mark[-1]);
		}
break;
case 5:
#line 119 "ftpcmd.y"
	{
			pass((char *) yystack.l_mark[-1]);
			free((char *) yystack.l_mark[-1]);
		}
break;
case 6:
#line 124 "ftpcmd.y"
	{
			usedefault = 0;
			if (pdata >= 0) {
				(void) close(pdata);
				pdata = -1;
			}
			reply(200, "PORT command successful.");
		}
break;
case 7:
#line 133 "ftpcmd.y"
	{
			passive();
		}
break;
case 8:
#line 137 "ftpcmd.y"
	{
			switch (cmd_type) {

			case TYPE_A:
				if (cmd_form == FORM_N) {
					reply(200, "Type set to A.");
					type = cmd_type;
					form = cmd_form;
				} else
					reply(504, "Form must be N.");
				break;

			case TYPE_E:
				reply(504, "Type E not implemented.");
				break;

			case TYPE_I:
				reply(200, "Type set to I.");
				type = cmd_type;
				break;

			case TYPE_L:
#if NBBY == 8
				if (cmd_bytesz == 8) {
					reply(200,
					    "Type set to L (byte size 8).");
					type = cmd_type;
				} else
					reply(504, "Byte size must be 8.");
#else /* NBBY == 8 */
				UNIMPLEMENTED for NBBY != 8
#endif /* NBBY == 8 */
			}
		}
break;
case 9:
#line 172 "ftpcmd.y"
	{
			switch (yystack.l_mark[-1]) {

			case STRU_F:
				reply(200, "STRU F ok.");
				break;

			default:
				reply(504, "Unimplemented STRU type.");
			}
		}
break;
case 10:
#line 184 "ftpcmd.y"
	{
			switch (yystack.l_mark[-1]) {

			case MODE_S:
				reply(200, "MODE S ok.");
				break;

			default:
				reply(502, "Unimplemented MODE type.");
			}
		}
break;
case 11:
#line 196 "ftpcmd.y"
	{
			reply(202, "ALLO command ignored.");
		}
break;
case 12:
#line 200 "ftpcmd.y"
	{
			reply(202, "ALLO command ignored.");
		}
break;
case 13:
#line 204 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char*)yystack.l_mark[-1] != NULL)
				retrieve((char *) 0, (char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 14:
#line 211 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				store((char *) yystack.l_mark[-1], "w", 0);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 15:
#line 218 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				store((char *) yystack.l_mark[-1], "a", 0);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 16:
#line 225 "ftpcmd.y"
	{
			if (yystack.l_mark[-1])
				send_file_list(".");
		}
break;
case 17:
#line 230 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL) 
				send_file_list((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 18:
#line 237 "ftpcmd.y"
	{
			if (yystack.l_mark[-1])
				retrieve("/bin/ls -lgA", "");
		}
break;
case 19:
#line 242 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				retrieve("/bin/ls -lgA %s", parse_path((char *) yystack.l_mark[-1]));
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 20:
#line 249 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				statfilecmd((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 21:
#line 256 "ftpcmd.y"
	{
			statcmd();
		}
break;
case 22:
#line 260 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				delete((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 23:
#line 267 "ftpcmd.y"
	{
			if (fromname) {
				renamecmd(fromname, (char *) yystack.l_mark[-1]);
				free(fromname);
				fromname = (char *) 0;
			} else {
				reply(503, "Bad sequence of commands.");
			}
			free((char *) yystack.l_mark[-1]);
		}
break;
case 24:
#line 278 "ftpcmd.y"
	{
			reply(225, "ABOR command successful.");
		}
break;
case 25:
#line 282 "ftpcmd.y"
	{
			if (yystack.l_mark[-1])
				cwd(pw->pw_dir);
		}
break;
case 26:
#line 287 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				cwd((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 27:
#line 294 "ftpcmd.y"
	{
			help(cmdtab, (char *) 0);
		}
break;
case 28:
#line 298 "ftpcmd.y"
	{
			register char *cp = (char *)yystack.l_mark[-1];

			if (strncasecmp(cp, "SITE", 4) == 0) {
				cp = (char *)yystack.l_mark[-1] + 4;
				if (*cp == ' ')
					cp++;
				if (*cp)
					help(sitetab, cp);
				else
					help(sitetab, (char *) 0);
			} else
				help(cmdtab, (char *) yystack.l_mark[-1]);
		}
break;
case 29:
#line 313 "ftpcmd.y"
	{
			reply(200, "NOOP command successful.");
		}
break;
case 30:
#line 317 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				makedir((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 31:
#line 324 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				removedir((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 32:
#line 331 "ftpcmd.y"
	{
			if (yystack.l_mark[-1])
				pwd();
		}
break;
case 33:
#line 336 "ftpcmd.y"
	{
			if (yystack.l_mark[-1])
				cwd("..");
		}
break;
case 34:
#line 341 "ftpcmd.y"
	{
			help(sitetab, (char *) 0);
		}
break;
case 35:
#line 345 "ftpcmd.y"
	{
			help(sitetab, (char *) yystack.l_mark[-1]);
		}
break;
case 36:
#line 349 "ftpcmd.y"
	{
			int oldmask;

			if (yystack.l_mark[-1]) {
				oldmask = umask(0);
				(void) umask(oldmask);
				reply(200, "Current UMASK is %03o", oldmask);
			}
		}
break;
case 37:
#line 359 "ftpcmd.y"
	{
			int oldmask;

			if (yystack.l_mark[-3]) {
				if ((yystack.l_mark[-1] == -1) || (yystack.l_mark[-1] > 0777)) {
					reply(501, "Bad UMASK value");
				} else {
					oldmask = umask(yystack.l_mark[-1]);
					reply(200,
					    "UMASK set to %03o (was %03o)",
					    yystack.l_mark[-1], oldmask);
				}
			}
		}
break;
case 38:
#line 374 "ftpcmd.y"
	{
			if ((char *)yystack.l_mark[-5] && ((char *)yystack.l_mark[-1] != NULL)) {
				if (yystack.l_mark[-3] > 0777)
					reply(501,
				"CHMOD: Mode value must be between 0 and 0777");
				else if (chmod((char *) yystack.l_mark[-1], yystack.l_mark[-3]) < 0)
					perror_reply(550, (char *) yystack.l_mark[-1]);
				else
					reply(200, "CHMOD command successful.");
			}
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 39:
#line 388 "ftpcmd.y"
	{
			reply(200,
			    "Current IDLE time limit is %d seconds; max %d",
				timeout, maxtimeout);
		}
break;
case 40:
#line 394 "ftpcmd.y"
	{
			if (yystack.l_mark[-1] < 30 || yystack.l_mark[-1] > maxtimeout) {
				reply(501,
			"Maximum IDLE time must be between 30 and %d seconds",
				    maxtimeout);
			} else {
				timeout = yystack.l_mark[-1];
				(void) alarm((unsigned) timeout);
				reply(200,
				    "Maximum IDLE time set to %d seconds",
				    timeout);
			}
		}
break;
case 41:
#line 408 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				store((char *) yystack.l_mark[-1], "w", 1);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 42:
#line 415 "ftpcmd.y"
	{
#ifdef unix
#ifdef BSD
			reply(215, "UNIX Type: L%d Version: BSD-%d",
				NBBY, BSD);
#else /* BSD */
			reply(215, "UNIX Type: L%d", NBBY);
#endif /* BSD */
#else /* unix */
			reply(215, "UNKNOWN Type: L%d", NBBY);
#endif /* unix */
		}
break;
case 43:
#line 436 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL)
				sizecmd((char *) yystack.l_mark[-1]);
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 44:
#line 453 "ftpcmd.y"
	{
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1] != NULL) {
				struct stat stbuf;
				if (stat((char *) yystack.l_mark[-1], &stbuf) < 0)
					perror_reply(550, "%s", (char *) yystack.l_mark[-1]);
				else if ((stbuf.st_mode&S_IFMT) != S_IFREG) {
					reply(550, "%s: not a plain file.",
						(char *) yystack.l_mark[-1]);
				} else {
					register struct tm *t;
					struct tm *gmtime();
					t = gmtime(&stbuf.st_mtime);
					reply(213,
					    "19%02d%02d%02d%02d%02d%02d",
					    t->tm_year, t->tm_mon+1, t->tm_mday,
					    t->tm_hour, t->tm_min, t->tm_sec);
				}
			}
			if ((char *)yystack.l_mark[-1] != NULL)
				free((char *) yystack.l_mark[-1]);
		}
break;
case 45:
#line 475 "ftpcmd.y"
	{
			reply(221, "Goodbye.");
			dologout(0);
		}
break;
case 46:
#line 480 "ftpcmd.y"
	{
			yyerrok;
		}
break;
case 47:
#line 485 "ftpcmd.y"
	{
			char *renamefrom();

			restart_point = (off_t) 0;
			if (yystack.l_mark[-3] && (char *)yystack.l_mark[-1]) {
				fromname = renamefrom((char *) yystack.l_mark[-1]);
				if (fromname == (char *) 0 && yystack.l_mark[-1]) {
					free((char *) yystack.l_mark[-1]);
				}
			}
		}
break;
case 48:
#line 497 "ftpcmd.y"
	{
			long atol();

			fromname = (char *) 0;
			restart_point = yystack.l_mark[-1];
			reply(350, "Restarting at %ld. %s", restart_point,
			    "Send STORE or RETRIEVE to initiate transfer.");
		}
break;
case 50:
#line 511 "ftpcmd.y"
	{
			*(char **)&(yyval) = "";
		}
break;
case 53:
#line 522 "ftpcmd.y"
	{
			register char *a, *p;

			a = (char *)&data_dest.sin_addr;
			a[0] = yystack.l_mark[-10]; a[1] = yystack.l_mark[-8]; a[2] = yystack.l_mark[-6]; a[3] = yystack.l_mark[-4];
			p = (char *)&data_dest.sin_port;
			p[0] = yystack.l_mark[-2]; p[1] = yystack.l_mark[0];
			data_dest.sin_family = AF_INET;
		}
break;
case 54:
#line 534 "ftpcmd.y"
	{
		yyval = FORM_N;
	}
break;
case 55:
#line 538 "ftpcmd.y"
	{
		yyval = FORM_T;
	}
break;
case 56:
#line 542 "ftpcmd.y"
	{
		yyval = FORM_C;
	}
break;
case 57:
#line 548 "ftpcmd.y"
	{
		cmd_type = TYPE_A;
		cmd_form = FORM_N;
	}
break;
case 58:
#line 553 "ftpcmd.y"
	{
		cmd_type = TYPE_A;
		cmd_form = yystack.l_mark[0];
	}
break;
case 59:
#line 558 "ftpcmd.y"
	{
		cmd_type = TYPE_E;
		cmd_form = FORM_N;
	}
break;
case 60:
#line 563 "ftpcmd.y"
	{
		cmd_type = TYPE_E;
		cmd_form = yystack.l_mark[0];
	}
break;
case 61:
#line 568 "ftpcmd.y"
	{
		cmd_type = TYPE_I;
	}
break;
case 62:
#line 572 "ftpcmd.y"
	{
		cmd_type = TYPE_L;
		cmd_bytesz = NBBY;
	}
break;
case 63:
#line 577 "ftpcmd.y"
	{
		cmd_type = TYPE_L;
		cmd_bytesz = yystack.l_mark[0];
	}
break;
case 64:
#line 583 "ftpcmd.y"
	{
		cmd_type = TYPE_L;
		cmd_bytesz = yystack.l_mark[0];
	}
break;
case 65:
#line 590 "ftpcmd.y"
	{
		yyval = STRU_F;
	}
break;
case 66:
#line 594 "ftpcmd.y"
	{
		yyval = STRU_R;
	}
break;
case 67:
#line 598 "ftpcmd.y"
	{
		yyval = STRU_P;
	}
break;
case 68:
#line 604 "ftpcmd.y"
	{
		yyval = MODE_S;
	}
break;
case 69:
#line 608 "ftpcmd.y"
	{
		yyval = MODE_B;
	}
break;
case 70:
#line 612 "ftpcmd.y"
	{
		yyval = MODE_C;
	}
break;
case 71:
#line 618 "ftpcmd.y"
	{
		/*
		 * Problem: this production is used for all pathname
		 * processing, but only gives a 550 error reply.
		 * This is a valid reply in some cases but not in others.
		 */
		if (logged_in && yystack.l_mark[0] && strncmp((char *) yystack.l_mark[0], "~", 1) == 0) {
			*(char **)&(yyval) = *glob((char *) yystack.l_mark[0]);
			if (globerr != NULL) {
				reply(550, globerr);
				yyval = '\0';
			}
			free((char *) yystack.l_mark[0]);
		} else
			yyval = yystack.l_mark[0];
	}
break;
case 73:
#line 640 "ftpcmd.y"
	{
		register int ret, dec, multby, digit;

		/*
		 * Convert a number that was read as decimal number
		 * to what it would be if it had been read as octal.
		 */
		dec = yystack.l_mark[0];
		multby = 1;
		ret = 0;
		while (dec) {
			digit = dec%10;
			if (digit > 7) {
				ret = -1;
				break;
			}
			ret += digit * multby;
			multby *= 8;
			dec /= 10;
		}
		yyval = ret;
	}
break;
case 74:
#line 665 "ftpcmd.y"
	{
		if (logged_in)
			yyval = 1;
		else {
			reply(530, "Please login with USER and PASS.");
			yyval = 0;
		}
	}
break;
#line 1830 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
