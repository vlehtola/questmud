/* Friends command for Questmud by Cendor at 070599 */
/* Added stuff by Nalle 250503                      */

#include <ansi.h>

#define TP this_player()
#define LEADERD "/daemons/leader_d"
#define USAGE "Usage : friends [ list | add (arg) | remove (arg) ]\n"
#define MAX_FRIENDS 50

#define HR "------------------------------------------------------------------------------\n"

string int_to_time(int p);

cmd_friends(string arg)
{
  mapping f;
  string *arr,brl,brr,*temp;
  int x,fo;
  int since, amount;

  object *usr,ob;
  usr=users();
  f=(mapping)TP->query_friends();
  if(!mappingp(f)) f=([]);
  arr=m_indices(f);

  amount = 0;

  if(!arg)
  {
    x=sizeof(usr);

    write( bold_color( sprintf("%-6s %-10s %-11s %-11s    %-11s\n",
           		       "Level","Name","Idletime","Online","Status") 
	             ) + HR );

    while(x--)
    {
       if(!environment(usr[x])) continue;
       if(member_array(usr[x]->query_real_name(),arr)==-1) continue;
       if(usr[x]->query_invisible()) continue;

       since = time() - usr[x]->query_enter_time();
       amount++;

       brl=(usr[x]->query_wiz()?"<":LEADERD->test_leader(usr[x]->query_name(),usr[x]->query_race())?"{":"[");

       brr=sprintf("%c",brl[0]+2);

       // Taken out because of ansi
       write(give_bcolor(brl, usr[x])+ sprintf("%4d", usr[x]->query_level()) + give_bcolor(brr, usr[x]));

       printf(" %-10s %-11s %-11s    %-10s\n",
                capitalize(usr[x]->query_real_name()),
                int_to_time(usr[x]->idle()),
                int_to_time(since),
                player_status(usr[x]));
    }

    if(!amount)
    {
      write("No friends logged in.\n");
    }
     else
    {
      printf( "%79s", amount + " friends online.\n");
    }

    return 1;
  }
  else if(arg=="list")
  {
    x=sizeof(arr);
    if(!x)
    {
      write("You have no one on your friends list.\n");
      return 1;
    }
    printf("Your friends:\n%15'-'s\n","");
    while(x--)
    {
      ob=find_player(arr[x]);
      printf("%s%-10s\n",((ob && interactive(ob) && !ob->query_invisible())
        ?"*":" "),capitalize(arr[x]));
    }
    return 1;
  }
  else if(sizeof((temp=explode(arg," "))) != 2)
  {
    write(USAGE);
    return 1;
  }
  switch(temp[0])
  {
    case "add":
    {
      if(file_size("/players/"+temp[1]+".o")==-1)
      {
        write("No such character.\n");
        return 1;
      }
      if( lower_case(temp[1]) == "celtron" )
      {
        write("You cannot do that.\n");
        return 1;
      }        

      if(m_sizeof(f)>=MAX_FRIENDS)
      {
        write("Your friends list is full.\n");
        return 1;
      }
      if(member_array(temp[1],arr)!=-1)
      {
        write("But "+temp[1]+" is already in your friends list.\n");
        return 1;
      }
      else
      {
        f+=([ lower_case(temp[1]):0 ]);
        TP->set_friends(f);
        write("Added "+capitalize(temp[1])+" to your friends list.\n");
        return 1;
      }
    }
    case "remove":
    {
      if(member_array(temp[1],arr)==-1)
      {
        write("But "+temp[1]+" is not on your friends list.\n");
        return 1;
      }
      else
      {
        f=m_delete(f,temp[1]);
        TP->set_friends(f);
        write("Removed "+capitalize(temp[1])+" from your friends list.\n");
        return 1;
      }
    }
    default:
    write(USAGE);
  }
  return 1;
}

string int_to_time(int p) 
{
  string str;  
    str = "";
  if(p/86400) 
  {
    str+=(p/86400) +"d ";
    p=p-(p/86400)*86400;
  }
  if(p/3600) 
  {
    str+=(p/3600) +"h ";
    p=p-(p/3600)*3600;
  }
  if(p/60) 
  {
    str+=(p/60)+"m ";
    p=p-(p/60)*60;
  }
  str+=p+"s";
  return str;
}

/************/

string player_status(object ob)
{
 string result;
 result="";

if(ob->query_away()) result="Away '"+ob->query_away()+"' ";
        else
if(ob->query_status()) result="'"+ob->query_status()+"' ";

if(ob->query_ghost()) result+="(Dead)";

return result;
}

/************/
// Just give bold

bold_color(string str)
{
 if(this_player()->query_terminal())
  return BOLD+str+OFF;
 else
  return str;
}

/************/
// The different colours for brackets if ansic term
give_bcolor(string str, object ob)
{
 if(!this_player()->query_terminal()) return str;

 if(ob->query_ghost()) return MAGENTA_F+str+OFF;

 if(ob->query_tester()) return YELLOW_F+str+OFF;

 if(query_idle(ob) >= 300) return sprintf("%c",27)+"[1;1;30m"+str+OFF;

 if(ob->query_wiz()) return str;

 if(ob->query_rebirth() == 1) return CYAN_F+str+OFF;

 if(ob->query_rebirth() == 2) return BOLD+CYAN_F+str+OFF;

 if(ob->query_rebirth() == 3) return RED_F+str+OFF;

 return str;
}

