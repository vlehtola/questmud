/* Friends command for Questmud by Cendor at 070599 */

#define TP this_player()
#define LEADERD "/daemons/leader_d"
#define USAGE "Usage : friends [ list | add (arg) | remove (arg) ]\n"
#define MAX_FRIENDS 50

string int_to_time(int p);

cmd_friends(string arg)
{
  mapping f;
  string *arr,brl,brr,*temp;
  int x,fo;
  object *usr,ob;
  usr=users();
  f=(mapping)TP->query_friends();
  if(!mappingp(f)) f=([]);
  arr=m_indices(f);
  if(!arg)
  {
    x=sizeof(usr);
    printf("%6s  %-10s %-10s\n%40'-'s\n","Level","Name","Idletime","");
    while(x--)
    {
       if(!environment(usr[x])) continue;
       if(member_array(usr[x]->query_real_name(),arr)==-1) continue;
       brl=(usr[x]->query_wiz()?"<":LEADERD->test_leader(usr[x]->query_name(),usr[x]->query_race())?"{":"[");
       brr=sprintf("%c",brl[0]+2);
       printf("%s%4d%s  %-10s %-10s\n",brl,usr[x]->query_level(),brr,usr[x]->query_name(),int_to_time(usr[x]->idle()));
       fo=1;
    }
    if(!fo)
    {
      write("No friends logged in.\n");
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
      printf("%s%-10s\n",((ob && interactive(ob))?"*":" "),capitalize(arr[x]));
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
      if(lower_case(temp[1])=="celtron")
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

