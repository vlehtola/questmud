// a secret channel - don't touch/see/hear this.

#include <ansi.h>

#define CHAN "wwb"
//#define DATA_FILE "/wizards/nalle/daemons/data/wwb_last"
#define DATA_FILE "/data/wwb_last"

#define TP this_player()
#define COLOURS "/cmds/std/_lite"
#define LAST_MAX 31

string *last_messages;
static string *chan_members;

string identify_member(string str);
int send_channel(string str);
string construct_chanstr(object ob, string str);
int show_last(int n);
int show_who();
string rot13(string str);

/*************************************************/

reset(arg) 
{
 if(arg) return;

 if(!last_messages) last_messages = ({ });
 if(!restore_object(DATA_FILE)) save_object(DATA_FILE);
}

/*************************************************/

status input(string str) // entinen wwb_cmd
{
  int i;
  object *ob;

  // Member list
  chan_members=({"nalle","walla","houtmi","phileas"});

  // ID check
  if(!identify_member(TP->query_name())) return 0;

  if(!this_player()->query_name())  { return 1; }

  if(str=="last")   { show_last(30); return 1; } 
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
   if(interactive(ob)) tell_object(ob,construct_chanstr(ob, str));
   }

  last_messages+=({ rot13       ( (string) 
        (sprintf("["+ctime()[11..15]+"] "+construct_chanstr(ob, str)) ) 
                                ) });

return 1;
}

/*******/

string construct_chanstr(object ob, string str) {
string temp, color_temp;

color_temp=COLOURS->give_color(ob, CHAN);
if(!strlen(color_temp)) color_temp=BOLD;

if(TP->query_wiz()) { temp="<"+CHAN+">"; }
        else
                    { temp="["+CHAN+"]"; }

if(TP->query_terminal()) temp=color_temp+temp+OFF;

temp+=": ";

return TP->query_name()+" "+temp+str+"\n";

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
int i;

if(!last_messages) { write("No messages here yet.\n"); return 1; }


        for(i=0;i<sizeof(last_messages);i++)
        {
        write(rot13( last_messages[i] ));
        }

write("Displayed "+i+" message(s).\n");

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

string rot13char(string tmp) {
tmp=tmp[0..0];
tmp=lower_case(tmp);

switch(tmp) 
        {
        case "a" : return "n";
        case "b" : return "o";
        case "c" : return "p";
        case "d" : return "q";
        case "e" : return "r";
        case "f" : return "t";
        case "g" : return "u";
        case "h" : return "v";
        case "i" : return "w";
        case "j" : return "x";
        case "k" : return "y";
        case "l" : return "z";
        case "m" : return "a";
        case "n" : return "b";
        case "o" : return "c";
        case "p" : return "d";
        case "q" : return "e";
        case "r" : return "f";
        case "s" : return "g";
        case "t" : return "h";
        case "u" : return "i";
        case "v" : return "j";
        case "w" : return "k";
        case "x" : return "l";
        case "y" : return "m";

        // extrat
        case "[" : return "#";
        case "#" : return "[";
        case "]" : return "�";
        case "�" : return "]";
        case ":" : return "%";
        case "%" : return ":";
        case "<" : return "&";
        case "&" : return "<";
        case ">" : return "�";
        case "�" : return ">";

        default : return tmp;
        }
}

/*************************************************/

string rot13(string str)
{
string result;
int i;

  result="";
  for(i=0;i<strlen(str);i++)    {
  result+=rot13char(str[i..i]);
                                }
return result;
}

/*************************************************/

