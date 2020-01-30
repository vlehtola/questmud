// 'Lite' -command for QuestMUD by Nalle Nov 2002

#include <ansi.h>

#define TP this_player()
#define USAGE "Usage : See 'help lite'\n"
#define MAX_LITES 50

string int_to_time(int p);
int secret_channel(string str);

cmd_lite(string arg)
{
  mapping l;
  string *arr,*temp;
  int x,i;
  object ob;
  l=(mapping)TP->query_colors();
  if(!mappingp(l)) l=([]);
  arr=m_indices(l);
  if(!arg)
  {
    x=sizeof(arr);
    if(!x) 
{ write("You have no colors set, default colors are used.\n"); return 1; }

    write("You have customized colours for the following messages:\n");
    for(i=0;i<x;i++)    {
        if(arr[i]=="tell" || arr[i]=="emote") 
        { write(capitalize(arr[i])+"s"); } else 
        { write("Messages from channel "+arr[i]); }
    if(TP->query_terminal())
    write(" are lited in "+return_color(l[arr[i],0])+l[arr[i],0]+OFF+"\n");    
    else
    write(" are lited in "+l[arr[i],0]+"\n");    
                        }

    write("Done. Other messages have default colors.\n");
    return 1;
  }

  if(arg=="reset")
  {
  write("All colours reset to defaults.\n");
  l=([]);
  TP->set_colors(l);
  return 1;
  }

  if(sizeof((temp=explode(arg," "))) != 3 && 
     sizeof((temp=explode(arg," "))) != 2)
  {
    write(USAGE);
    return 1;
  }
  switch(temp[0])
  {
    case "channel":
    {
        if(sizeof((temp=explode(arg," "))) != 3) 
        { write("You must specify a color and channel.\n"); return 1; }

        if(!channel_exists(temp[1]) && !secret_channel(temp[1])) 
        { write("No such channel '"+temp[1]+"'.\n"); return 1;  }
        if(!return_color(temp[2])) 
        { write("No such color '"+temp[2]+"'.\n"); return 1;    }

      if(m_sizeof(l)>=MAX_LITES)
      {
        write("You can lite no more channels.\n");
        return 1;
      }
     {
//     l+=([ lower_case(temp[1]):0 ]);
     l+=([ lower_case(temp[1]):temp[2] ]);
     TP->set_colors(l);
      if(TP->query_terminal()) 
      write("You now lite channel '"+capitalize(temp[1])+"' in "+
                return_color(temp[2])+temp[2]+OFF".\n");
      else
      write("You now lite channel '"+capitalize(temp[1])+"' in "+temp[2]+".\n");
     return 1;
     }
    }

    case "tell":
    case "emote":
    {
        if(!return_color(temp[1])) 
        { write("No such color '"+temp[1]+"'.\n"); return 1;    }

      if(m_sizeof(l)>=MAX_LITES)
      {
        write("You can lite no more channels.\n");
        return 1;
      }
     {
     l+=([ lower_case(temp[0]):temp[1] ]);
     TP->set_colors(l);
      if(TP->query_terminal()) 
      write("You now lite "+temp[0]+"s in "+
        return_color(temp[1])+temp[1]+OFF".\n");
      else
      write("You now lite "+temp[0]+"s in "+temp[1]+".\n");
     return 1;
     }
    }


    case "default":
    {
      if(member_array(temp[1],arr)==-1)
      {
 write("Messages of type '"+temp[1]+"' are not in custom colours at the moment.\n");
 return 1;
      }
      else
      {
 l=m_delete(l,temp[1]);
 TP->set_colors(l);
 write("Messages of type '"+capitalize(temp[1])+"' are no longer lit in custom colours.\n");
 return 1;
      }
    }
    default:
    write(USAGE);
  }
  return 1;
}

/************/

// Ugly kludge, what was i thinking of!? We should move this to ChD. -N '04

channel_exists(string str) 
{
 int i;
 string *channels;
 channels=({"log","wiz","fiz","arch","adm","fin","swe","mud",
            "sales","wanted","inform","wanted","alert","code",
            "chat","ghost","newbie", "copy"});

  for(i=0;i<sizeof(channels);i++) 
     {
      if(str==channels[i]) return 1;
     }

 return 0;
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

l=(mapping)player->query_colors();
if(!mappingp(l)) l=([]);
arr=m_indices(l);

x=sizeof(arr);
if(!x) return "";

for(i=0;i<x;i++)        {
        if(arr[i]==str) 
        { 
        return return_color(l[str,0]); 
        }
                        }
return "";

}

/***********/

int secret_channel(string str) {

  switch(str) 
  {
    case "wwb"	: 
    case "ug"	: 
    case "pr0n"	: 
    case "url"	: return 1;
    default   	: return 0;
  }

return 0;

}

