// 'Environment' -command for QuestMUD by Nalle 2003
// White-problems changed. -N

#include <ansi.h>

#define TP this_player()
#define USAGE "Usage : See 'help environment'\n"

string int_to_time(int p);
string secret_channel(string str);

cmd_environment(string arg)
{
  mapping l;
  string *arr,*temp;
  int x,i;
  object ob;
  l=(mapping)TP->query_environment_colors();
  if(!mappingp(l)) l=([]);
  arr=m_indices(l);
  if(!arg)
  {
    x=sizeof(arr);
    if(!x) 
 { write("You have no enviroment colors set, default colors are used.\n"); return 1; }

    write("You have customized colours for the following entities:\n");
    for(i=0;i<x;i++)    {
        write(capitalize(arr[i])); 
    if(TP->query_terminal())
    write(" are lited in "+return_color(l[arr[i],0])+l[arr[i],0]+OFF+"\n");    
    else
    write(" are lited in "+l[arr[i],0]+"\n");    
                        }

    write("Done. Other entities have default colors.\n");
    return 1;
  }

  if(arg=="reset")
  {
  write("All environment colours reset to defaults.\n");
  l=([]);
  TP->set_environment_colors(l);
  return 1;
  }

  if(sizeof((temp=explode(arg," "))) != 2)
  {
    write(USAGE);
    return 1;
  }

  switch(temp[0])
  {
    case "aggressive_monsters":
    case "monsters":
    case "players":
    case "armours":
    case "weapons":
    case "room_short":
    case "room_long":
    {
        if(sizeof((temp=explode(arg," "))) != 2) 
        { 
	  write("You must specify a color and something to lite.\n"); 
	  return 1; 
	}

        if(!return_color(temp[1])) 
        { write("No such color '"+temp[1]+"'.\n"); return 1;    }

     {
     l+=([ lower_case(temp[0]):temp[1] ]);
     TP->set_environment_colors(l);
      if(TP->query_terminal()) 
      write("You now lite "+temp[0]+" in "+
                return_color(temp[1])+temp[1]+OFF".\n");
      else
      write("You now lite "+temp[0]+" in "+temp[1]+".\n");
     return 1;
     }
    }

    default:
    write(USAGE);
  }
  return 1;
}

/***********/

string return_color(string str) 
{
if(!str) return 0;
switch(str)     {
        case "blue": return BLUE_F;
        case "light_blue": return BOLD+BLUE_F;
        case "red": return RED_F;
        case "light_red": return BOLD+RED_F;
        case "cyan": return CYAN_F;
        case "light_cyan": return BOLD+CYAN_F;
        case "magenta": return MAGENTA_F;
        case "light_magenta": return BOLD+MAGENTA_F;
        case "bold": return BOLD;
        case "green": return GREEN_F;
        case "light_green": return BOLD+GREEN_F;
        case "yellow": return YELLOW_F;
        case "light_yellow": return BOLD+YELLOW_F;
        case "white": return WHITE_F;
        case "gray": return sprintf("%c",27)+"[1;1;30m";
        case "off": return "";
        default: return 0;
                }
return 0;
}

/***********/

string give_color(object player, string str) 
{
 mapping l;
 string *arr;
 int x,i;

if(!str || !player) return "";
if(!player->query_terminal()) return "";

l=(mapping)player->query_environment_colors();
if(!mappingp(l)) l=([]);
arr=m_indices(l);

x=sizeof(arr);
if(!x) return "";

	// I should hange this to a member_array sometime

for(i=0;i<x;i++)        {
        if(arr[i]==str) 
        { 
         return return_color(l[str,0]); 
        }
                        }
return "";

}

