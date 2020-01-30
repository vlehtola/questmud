// You don't want to know what this is. - Nalle, level 1000 elder.

#include <ansi.h>

#define CHAN "wwb"
#define DATA_FILE "/data/channeltest_data"
#define STEGANO "/wizards/nalle/daemons/steganography_d"

#define TP this_player()
#define COLOURS "/cmds/std/_lite"
#define LAST_MAX 100

string *last_messages;
static string *chan_members;

string identify_member(string str);
int send_channel(string str);
string construct_chanstr(object ob, string str, int no_colours);
int show_last(int n);
int show_who();

/*************************************************/

reset(arg) 
{
 if(arg) return;

 (object) (STEGANO);
 if(!last_messages) last_messages = ({ });
 if(!restore_object(DATA_FILE)) save_object(DATA_FILE);
}

/*************************************************/

status input(string str) // entinen wwb_cmd
{
  int i, n;
  object *ob;

  // Member list
  chan_members=({"nalle","walla","houtmi"});

  // ID check
  if(!identify_member(TP->query_name())) return 0;

  if(!this_player()->query_name())  { return 1; }

  // Last
  if(str=="last")   { show_last(20); return 1; } 

  // Variable last
  if( sscanf(str, "last %d", n) == 1 )
    {
     if(n < 0 || n > LAST_MAX) n = 20;
     show_last( n );
     return 1;
    }

  if(str=="who")   { show_who(); return 1; } 

  if(!str)   {
    write("Syntax : wwb <message, 'last' or 'who'>\n");
    return 1;
              }

 if(sizeof(last_messages)>=LAST_MAX) 
 {
   last_messages=last_messages[1..(LAST_MAX-1)];
 }


send_channel(str);

save_object(DATA_FILE);

return 1;
}


/*******/

int send_channel(string str) 
{
object ob;
int i;
string *buffy;

  // ID check (Redundant, for security)
  if(!identify_member(TP->query_name())) return 0;

  for(i=0;i<sizeof(chan_members);i++) 
   {
    ob=find_player(chan_members[i]);
    if(ob)
    if(interactive(ob)) tell_object(ob,construct_chanstr(ob, str, 0));
   }

  last_messages+=({ STEGANO->rot13      ( (string) 
        (sprintf("["+ctime()[11..15]+"] "+construct_chanstr(ob, str, 1)) ) 
                                        ) });

return 1;
}

/*******/

string construct_chanstr(object ob, string str, int no_colour) 
{
 string temp, color_temp, plr_name;
 string *pekka;

 color_temp = "";

 if(!no_colour)
   {
    color_temp=COLOURS->give_color(ob, CHAN);
    if(!strlen(color_temp)) color_temp=BOLD;
   }

 if(TP->query_wiz()) { temp="<"+CHAN+">"; }
         else
                     { temp="["+CHAN+"]"; }

 if(TP->query_terminal()) temp=color_temp+temp+OFF;

 temp+=": ";

 pekka = ({	"Pekka", "PJ", "Puusilma", "Goldfinger", "MyPussyHurts",
		"Homotmi", "Kikkanokka", "Mikkihiiri", "GeorgeW",
		"Woodeye", "Daiju!", "Dokahontas", "SmellyFinger",
		"Ymiel", "nuhanena", "deeku" });

 plr_name = TP->query_name();
// if(plr_name == "Houtmi") plr_name = pekka[ random(sizeof(pekka)) ];
 

 return plr_name+" "+temp+str+"\n";
}

/*******/


int identify_member(string str) 
{
int i;
str=lower_case(str);

// Check
for(i=0;i<sizeof(chan_members);i++) if(chan_members[i]==str) return 1;

return 0;
}

/*******/

int show_last(int n) 
{
 int i, x;

 if(!last_messages) { write("No messages here yet.\n"); return 1; }

 // For last
 if( sizeof(last_messages) < n ) n = sizeof(last_messages);

 // Shown counter
 x = 0;

        for(i= sizeof(last_messages)-n ;i<sizeof(last_messages);i++)
        {
         write(STEGANO->rot13( last_messages[i] ));
	 x++;
        }

write("Displayed "+x+" message(s).\n");

return 1;
}

/*******/

int show_who() {
int i,idletime;
string result,idlestring;

  // ID check (Redundant, for security)
  if(!identify_member(TP->query_name())) return 0;

result="Statistics of ["+CHAN+"]: ";

for(i=0;i<sizeof(chan_members);i++) 
 if(find_player(chan_members[i]))
 if(interactive(find_player(chan_members[i])))  {
   idletime=query_idle(find_player(chan_members[i]));
   idlestring="";
   if(idletime>=3600) {
        idlestring+=((idletime-(idletime%3600))/3600)+"h ";
        idletime=idletime%3600;
      }
      if(idletime>=60) {
        idlestring+=((idletime-(idletime%60))/60)+"m ";
        idletime=idletime%60;
      }
      idlestring+=idletime+"s";
   result+=capitalize(chan_members[i])+" ("+idlestring+"), ";
                                                }
tell_object(TP,result[0..(strlen(result)-3)]+"\n");
return 1;
}

/*******/
