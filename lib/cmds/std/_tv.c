// a secret channel - don't touch/see/hear this.

#include <ansi.h>

#define CHAN "tv"

#define TP this_player()
#define COLOURS "/cmds/std/_lite"
#define LAST_MAX 31

string *last_messages;
string *chan_members;

string identify_member(string str);
int send_channel(string str);
string construct_chanstr(object ob, string str);
int show_last(int n);
int show_who();

status cmd_tv(string str)
{
  int i;
  object *ob;

  // Member list

  chan_members=({"nalle","walla","houtmi","phileas","posti"});

  // ID check
  if(!identify_member(TP->query_name())) return 0;

  if(!this_player()->query_name())  { return 1; }

  if(str=="last")   { show_last(30); return 1; } 
  if(str=="who")   { show_who(); return 1; } 

  if(!str)   {
    write("Syntax : tv <message, 'last' or 'who'>\n");
    return 1;
              }

 if(sizeof(last_messages)>=LAST_MAX) 
 {
   last_messages=last_messages[1..(LAST_MAX-1)];
 }


send_channel(str);

return 1;


/*
for(i=0;i<sizeof(ob);i++) {
 if(ob[i]!=this_player() && living(ob[i]))
 ob[i]->set_say_messages(
   ,ob[i]->query_say_messages()));
                          }

  write("You say '" +str+ "'\n");
  say(this_player()->query_name() + " says '" +str+ "'\n");
 */

}


/*******/

int send_channel(string str) 
{
object ob;
int i;
string *buffy;

  for(i=0;i<sizeof(chan_members);i++) 
   {
   ob=find_player(chan_members[i]);
   if(ob)
   if(interactive(ob)) tell_object(ob,construct_chanstr(ob, str));
   }

  if(!last_messages) 
  last_messages=({ sprintf("["+ctime()[11..15]+"] "+construct_chanstr(ob, str)) });
  else
  last_messages+=({ sprintf("["+ctime()[11..15]+"] "+construct_chanstr(ob, str)) });

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
	write(last_messages[i]);
	}

write("Displayed "+i+" message(s).\n");

return 1;
}

/*******/

int show_who() {
int i,idletime;
string result,idlestring;

result="Statistics of ["+CHAN+"]: ";

for(i=0;i<sizeof(chan_members);i++) 
 if(find_player(chan_members[i]))
 if(interactive(find_player(chan_members[i]))) 	{
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

