#define PORT 3005 /* MUD FTP Port Number */
#undef STRUCTURED /* Define this if you use /players/l/lioncub.o structure*/
#define MUD_PATH "/home/quest/mud/lib" /* Final Home Path */
#define LIBDIR "/home/quest/mud/lib" /* Path of the mudlib */
#define FTPD_LOG "/home/quest/mud/lib/log/FTPD" /* Where Do I Log TheStuff Sir */
#undef ALLOW_GUEST /* Do we allow guest logins to take a look at the"PUBLIC"*/
#define MUD_NAME "QuestMud" /* For The Login Screens */
#define ARCH_FTP_LOGGED /* Define this if ARCH ftp is to be logged */
#define ARCH_LEVEL 3 /* The level at which Arch-hood Starts */
#define WIZ_LEVEL 1 /* The level at which Wiz-hood Starts */
#define GOD_LEVEL 4 /* The level at which God-hood Starts (quest demigod) */
#define MINIMUM_LEVEL 1 /* The lowest level allowed MUDFTP access */
#undef ALL_PLAYERS /* Define this is ANY player is allowed access to theftp. */
#define ftp_ver "LcMudFtp1.0a-QuestMud"


struct mudpw {
	char pw_name[14];
	char pw_passwd[26];
	int pw_level;
	char pw_dir[256];
};


