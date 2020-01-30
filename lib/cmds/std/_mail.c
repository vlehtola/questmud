/* New mailsystem for questmud by Nalle 05/2004 */

#include <ansi.h>

#define SAVEDIR		"/data/mail/"

#define MAIL_OBJ	"/cmds/std/obj/mail_obj"
#define TP 		this_player()
#define CTIME_LENGTH 	24
#define HR		bold_color(" -----------------------------------------------------------------------------")
#define PHR		" -----------------------------------------------------------------------------"

// Globals

mapping mail;

// Protos

mapping query_mail(string playername);
void 	print_headers(string playername);
int 	player_exists(string playername);
string 	read_mail(int number);
void 	delete_mail(int number);
string  bold_color(string str);
void 	send_mail(string target, string subject, string message);
mixed 	max_from_array(int *arr);
void 	save_mail(string playername);
void	read_unread();
int	has_new_mail(string playername);

/*************************************************************************/
 
cmd_mail(string str) 
{
 int number;
 string target;
 object mailob;

  if(!this_player()->check_condis())  { return 1; }

  if(!str || str == "headers") 
    {
     print_headers( TP->query_real_name() );
     return 1;
    }

  str = lower_case(str);

  if( str == "read" )
    {
     read_unread();
     return 1;
    }

  if( sscanf(str, "read %d", number ) == 1 ) 
    { 
     write( read_mail(number) );
     return 1;  
    }

  if(TP->query_level() < 15) 
    {
     write("Unfortunately you are of too low level to send mail.\n");
     return 1;
    }

  if( sscanf(str, "delete %d", number ) == 1 ) 
    { 
     delete_mail(number);
     return 1;  
    }

  if( sscanf(str, "send %s", target ) == 1 ) 
    {
     if(!player_exists(target))
       {
        write("There is no player called '"+capitalize(target)+"'.\n");
	return 1;
       }

     mailob = clone_object( MAIL_OBJ );
     mailob->mail_to(target);
     return 1;
    }

  write( "Syntax: 'mail send <player>', 'mail read <#>', 'mail delete <#>', 'mail'\n");

  return 1;
}

/*************************************************************************/

string read_mail(int number)
{
 mapping mailmap;
 string  *arr;
 string buf_a, buf_b;
 string result;

 mailmap = query_mail( TP->query_real_name() );

 arr	 = m_indices(mailmap);
 arr = sort_array( arr, #'> );

 result = "";

 if( member_array(number, arr) == -1 )
   {
    return "You do not have a message numbered '"+number+"', check the headers.\n";
   }

 result += PHR + "\n";

 // Line 1
 result += " Message : "+ bold_color( "#"+ number ) +" \t\tFrom : "+ bold_color( capitalize(mailmap[ number, 0 ]) ) +
	" \t\tDate : "+ bold_color( ctime(mailmap[ number, 1 ])[4 .. CTIME_LENGTH] ) +"\n";
 // Line 2
 result += " Subject" + " : '" + bold_color(mailmap[ number, 2 ]) +"'\n";

 // Line 3
 result += "\n";

  buf_a = mailmap[ number, 3 ];

  while( strlen(buf_a) )
       {
        sscanf(buf_a,"%s\n%s", buf_b, buf_a);
        result += "> "+buf_b+"\n";
       }

 //result += PHR + "\n";
 result += "\n";

 // Mark read
 if(mailmap[ number, 4 ])
   {
    mailmap[ number, 4 ] = 0;
    save_mail( TP->query_real_name() );
   }

 return result;
}
/*************************************************************************/

void delete_mail(int number)
{
 string *arr;

 // Kiaa!
 arr = sort_array( m_indices( query_mail( TP->query_real_name() ) ), #'> );

 if( member_array(number, arr) == -1 )
   {
    write("You do not have a message numbered '"+number+"', check the headers.\n");
    return;
   }

 mail -= ([ number ]);

 write("Removed mail number '"+ bold_color( to_string(number) ) +"'.\n");

 save_mail( TP->query_real_name() );
}

/*************************************************************************/

void read_unread()
{
 string *arr;
 object pager;
 string result;
 int i;

 pager = clone_object("/daemons/pager");
 pager->move(this_player());

 // Kiaa!
 arr = sort_array( m_indices( query_mail( TP->query_real_name() ) ), #'> );

 result = "Checking unread mails ...\n";

 for( i = 0; i < sizeof(arr); i++ )
    {
     if (mail[ arr[i], 4 ]) result += read_mail( to_int( arr[i]  ));
    }
 
 pager->page(result);
}


/*************************************************************************/

void print_headers(string playername)
{
 string  output_buf, tmp;
 string  *tarr;
 mapping mailmap;
 int 	 i, unread;

 if(!playername && TP) playername = TP->query_real_name();

 if(!playername) { write("Error.\n"); return; }

 mailmap = query_mail(playername);

 tarr = m_indices( mailmap );

 tarr = sort_array( tarr, #'> );

 if(TP->query_terminal())
   write( sprintf(" %s%3s %-12s %-40s %-20s%s\n", BOLD, "#", "Sender", "Subject", "Date", OFF) );
  else
   write( sprintf(" %3s %-12s %-40s %-20s\n", "#", "Sender", "Subject", "Date") );

 write( PHR + "\n" );

 for(i = 0; i < sizeof(tarr); i++)
    {
     output_buf = " ";

     // Check subject isnt too big
     tmp = mailmap[ tarr[i], 2 ];
     if(strlen(tmp) > 36) tmp = tmp[0 .. 35] + "...";

     // Unread checks
     if (mailmap[ tarr[i], 4 ])
	{
	 if(TP->query_terminal())
	    output_buf = GREEN_F + "N" + OFF;
	     else
	    output_buf = "N";
	}

     output_buf += sprintf("%|3d %-12s %-40s %-20s\n", 
			to_int(tarr[i]), 
			capitalize(mailmap[ tarr[i], 0 ]),
			tmp,
     			ctime(mailmap[ tarr[i], 1 ])[4 .. CTIME_LENGTH]);

     write( output_buf );

    }

 write(" A total of "+ bold_color( to_string(i) )+" messages displayed.\n");
}

/*************************************************************************/


mapping query_mail(string playername)
{
 mail = ([]);

 if(!restore_object(SAVEDIR + playername)) save_object(SAVEDIR + playername);

 return mail;
}


/*************************************************************************/

void save_mail(string playername)
{
 if(!player_exists(playername)) return;
 
 save_object( SAVEDIR + playername );
}

/*************************************************************************/

void send_mail(string target, string subject, string message)
{
 int id;

 query_mail(target);

 id = max_from_array( m_indices( mail ) ) + 1;

 mail += ([ id : this_player()->query_real_name() ;
		 time();
		 subject;
		 message;
		 1
	  ]);

 save_mail(target);
 write("Message sent.\n");

 if(find_player(target))
   {
    tell_object( find_player(target), "New mail from "+
		 bold_color(capitalize(this_player()->query_real_name()))+
		 ", regarding '"+bold_color(subject)+"'.\n");
   }
}

/*************************************************************************/
// Check if player exists

int player_exists(string playername)
{
 if( strstr( playername, "..", 0 ) > -1 ) 
	return 0;

 if( file_size( "/players/"+ playername +".o") > -1 ) 
	return 1;

 return 0;
}

/*************************************************************************/
// Just give bold

string bold_color(string str)
{
 if(this_player()->query_terminal())
  return BOLD+str+OFF;
 else
  return str;
}

/*************************************************************************/
// A maximum finding fun. Couldn't find one in the lib. -N

mixed max_from_array(int *arr)
{
 int i;
 mixed cmax;

 if(!sizeof(arr))     return -1;
 if(sizeof(arr) == 1) return arr[0];

 cmax = arr[0];

 for(i = 1; i < sizeof(arr); i++ )
    {
     if( cmax < arr[i] ) cmax = arr[i];
    }

 return cmax;
}

/*************************************************************************/
// Returns truth value of having new mail. Optimize if added to prompt fe.

int has_new_mail(string playername)
{
 int i;
 string *arr;

 if(!playername)
   {
    if (TP) playername = TP->query_real_name();
	else
	    return 0;
   }

 arr = sort_array( m_indices( query_mail( TP->query_real_name() ) ), #'> );

 for( i = 0; i < sizeof(arr); i++ )
    {
     if (mail[ arr[i], 4 ]) return 1;
    }

 return 0;
}

/*************************************************************************/

