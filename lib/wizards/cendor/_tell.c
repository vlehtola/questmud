/* Tell command for QuestMUD by Cendor at 080599 */

#include "/wizards/cendor/ansi.h"

#define USAGE "Usage : tell name1,name2,name3,... (msg)\n"
#define TP this_player()
#define CAP(XX) (XX=="you"?XX:capitalize(XX))
#define LITE(XX) TP->lited(XX)

string * rem_tell(string arg,string * arr);
status last_tell(string *arr);

status cmd_tell(string arg)
{
  string *names,*arr,r,msg,*names2,t1,t2,*reasons,r_list,*names3;
  mapping fails;
  object *targets,ob,*targets2;
  int x,y,z,i;
  fails=([]);
  if(TP->query_dead())
  {
    write("You fail.\n");
    return 1;
  }
  if(arg=="last")
  {
    last_tell(TP->query_last_tells());
    return 1;
  } 
  if(!arg || sizeof(explode(arg," "))<2)
  {
    write(USAGE);
    return 1;
  }
  if(explode(arg," ")[0]=="friends")
  {
    names = m_indices(TP->query_friends());
    x=sizeof(names);
    names2=({});
    while(x--)
    {
      if(find_player(names[x]))
        names2 += ({ names[x] });
    }
    names=names2;
  }
  else names = explode(explode(arg," ")[0],",");
  msg = implode(explode(arg," ")[1..]," ");
  TP->set_last_msg(msg);
  targets=({});
  names -= ({""});
  x=sizeof(names);
  while(x--)
  {
    if(!ob=find_player(names[x]))
    {
      fails += ([ names[x]:"No such player." ]);
    }
    else if(!interactive(ob))
    {
      fails += ([ names[x]:"Linkdead." ]);
    }
    else if(ob->query_ignorae(TP->query_name()))
    {
      fails += ([ names[x]:"Ignored." ]);
    }
    else targets += ({ ob });
  }
  arr=m_indices(fails);
  x=sizeof(arr);
  while(x--)
  {
    printf("Failed to tell to %s (%s)\n",capitalize(arr[x]),fails[arr[x]]);
  }
  if(sizeof(targets)>1)
    targets -= ({ TP });
  x=sizeof(targets);
  if(!x) return 1;
  names=({});
  targets2=({});
  while(x--)
  {
    if(member_array(targets[x],targets2)==-1)
    {
      targets2 += ({ targets[x] });
    }
  }
  targets=targets2;
  x=sizeof(targets);
  while(x--)
  {
    names += ({ targets[x]->query_real_name() });
  }
  x=sizeof(names);
  r="";
  while(x--)
  {
    reasons = ({});
    ob=find_player(names[x]);
    if(ob->idle()>=60)
    {
      reasons += ({ "Idle "+TP->stime(ob->idle()) });
    }
    if(ob->query_away())
    {
      reasons += ({ "Away '"+ob->query_away()+"'" });
    }
    if(ob->query_attack())
    {
      reasons += ({ "In fight" });
    }   
    if(ob->query_dead())
    {
      reasons += ({ "Dead" });
    }   
    r_list = " ("+implode(reasons,", ")+")";
    r+=(x==1?CAP(names[x])+(sizeof(reasons)?r_list:"")+
    " and ":(!x?CAP(names[x])+(sizeof(reasons)?r_list:"")
    :CAP(names[x])+(sizeof(reasons)?r_list:"")+", "));

  }
  printf("You tell %s '%s'\n",r,msg);
  x=sizeof(targets);
  while(x--)
  {
    r="";
    names2=({});
    z=sizeof(names);
    while(z--)
    {
      names2 += ({ names[z] });
    }
    y=sizeof(names2);
    while(y--)
    {
      z=sizeof(names);
      if(names2[y]==targets[x]->query_real_name())
      {
        names2[y]="you";
      }
    }
    if((i=member_array("you",names2))!=-1)
    {
      if(i)
      {
        t1=names2[0]; t2=names2[i];
        names2[0]=t2; names2[i]=t1;
      }
    }
    names3=({});
    y=sizeof(names2);
    while(y--)
    {
      names3 += ({ names2[y] });
    }
    names2=names3;
    y=sizeof(names2);
    while(y--)
    {
      r+=(y==1?CAP(names2[y])+" and ":(!y?CAP(names2[y]):CAP(names2[y])+", "));
    }
    tell_object(targets[x],sprintf("%s tells %s '%s'\n",
    CYAN_F+BOLD+TP->query_name(),r+OFF,msg));
    targets[x]->set_last_tells(rem_tell(sprintf("%s tells %s '%s'\n",
    TP->query_name(),r,msg),targets[i]->query_last_tells()));
    names2 -= ({ "you" });
    names2 += ({ TP->query_real_name() });
    targets[x]->set_last_teller(implode(names2,","));
  }
  return 1;
}

string * rem_tell(string arg, string * arr)
{
  int x;
  if(!pointerp(arr)) arr = ({});
  if(!arg) return 0;
  if(sizeof(arr)>19)
  {
    for(x=1;x<sizeof(arr);x++)
    {
      arr[x-1]=arr[x];
    }
    arr[19]=arg;
    return arr;
  }
  arr += ({ arg });
  return arr;
}

status last_tell(string *arr)
{
  int x; 
  for(x=0;x<sizeof(arr);x++)
  {
    printf("%s",arr[x]);
  }
  return 1;
}
