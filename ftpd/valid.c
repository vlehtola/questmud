/*

* Filename: valid.c
* Modification from original: Total New File
* Comments: This file is responsible for all mud security routing

 */

#include <sys/param.h>
#include "security.h"
#include <stdio.h>
#include <string.h>

extern int valid_admin();
extern struct mudpw *pw;
extern int guest;        /* anonymous guest or not */

int anonymous(s)
char *s;
{
#ifdef ALLOW_GUEST
    return (!strcmp(s,"ftp") || !strcmp(s,"anonymous") || !strcmp(s,"guest"));
#else
    return 0;
#endif
}

int access_allowed(pw)
struct mudpw *pw;
{
#ifdef ALL_PLAYERS
	return 1;
#else
    if (pw->pw_level < MINIMUM_LEVEL)
		return 0;
	return 1;
#endif
}

/* get all of user's home directory except for the username */

char *get_prefix(pw,s)
struct mudpw *pw;
char *s;
{
	sprintf(s,"%s/wizards", LIBDIR);
	return s;
}

/* get user's home directory */

char *get_home(pw,s)
struct mudpw *pw;
char *s;
{
	static char tstr[MAXPATHLEN+1];

	sprintf(s,"%s/%s",get_prefix(pw,tstr),pw->pw_name);
	return s;
}

/* return the filename for saved player object (the *.o file) */

char *get_player_fname(pw,s)
struct mudpw *pw;
char *s;
{
	sprintf(s,"%s/players/%s.o", LIBDIR, pw->pw_name);
	return s;
}

/*
   valid_write():

   this particular function is very dependent upon the directory structure
   of your mudlib.  Be very careful that this function is doing what you
   expect it to (restricting the appropriate directories etc - including
   the mail directory and other supposedly secure directories).

*/

int valid_write(path)
 char *path;
{
	register int len;
	char a[MAXPATHLEN + 1];
	char b[MAXPATHLEN + 1];
	char tmp[200];
//	extern int errno;
//	errno = 13;

	if ((pw->pw_level >= GOD_LEVEL)) {
	  if ((strstr(path,"/cmds"))) return 1;
	  if ((strstr(path,"/room"))) return 1;
	  if ((strstr(path,"/daemons"))) return 1;
	  if ((strstr(path,"/obj"))) return 1;
	  if ((strstr(path,"/castle"))) return 1;
        }

	if ((pw->pw_level >= ARCH_LEVEL)) {
  	  if ((strstr(path,"/wizards"))) return 1;
	  if ((strstr(path,"/doc"))) return 1;
	  if ((strstr(path,"/world/out"))) return 0;
	  if ((strstr(path,"/world"))) return 1;
	  if ((strstr(path,"/guilds"))) return 1;

	}

	len = strlen(LIBDIR);
	if (strncmp(path, LIBDIR, len))
		return 0;

	path += len;

        sprintf(tmp, "/wizards/%s", pw->pw_name);

	if (!strncmp(path, tmp, 9+strlen(pw->pw_name)))
		return 1;
        else
		return 0;
}

int valid_directory_write(path)
 char *path;
{
	register int len;
	char a[MAXPATHLEN + 1];
	char b[MAXPATHLEN + 1];
	char tmp[200];
//	extern int errno;
//	errno = 13;

	len = strlen(LIBDIR);
	path += len;

        sprintf(tmp, "/wizards/%s", pw->pw_name);

	if (!strncmp(path, tmp, 9+strlen(pw->pw_name)))
		return 1;
        else
		return 0;
}

/*
   valid_read():

   this particular function is very dependent upon the directory structure
   of your mudlib.  Be very careful that this function is doing what you
   expect it to (restricting the appropriate directories etc - including
   the mail directory and other supposedly secure directories).
*/

int valid_read(path)
char *path;
{
	register int len;
	char a[MAXPATHLEN + 1];
	char b[MAXPATHLEN + 1];
	char tmp[200];
//	extern int errno;

//	errno = 13;
	if (valid_write(path)) return 1;

	len = strlen(LIBDIR);
	if (strncmp(path, LIBDIR, len))
		return 0;
	path += len;

        sprintf(tmp, "/wizards/%s", pw->pw_name);
	if (!strncmp(path, tmp, 9+strlen(pw->pw_name)))
		return 1;
        else
		return 0;
}
