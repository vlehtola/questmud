/* Tell command for QuestMUD by Cendor at 080599 */
/* Small changes for the new ignore by Nalle May 2002 */

#include <ansi.h>

#define USAGE "Usage : tell name1,name2,name3,... (msg)\n"
#define TP this_player()
#define CAP(XX) (XX=="you"?XX:capitalize(XX))
#define LITE(XX) TP->lited(XX)
#define COLOURS "/cmds/std/_lite"

string * rem_tell(string arg,string * arr);
status last_tell(string *arr);
int check_ignored(string str);
int check_levelignore(string str);

status cmd_tell(string arg)
{
  string *names,*arr,r,msg,*names2,t1,t2,*reasons,r_list,*names3;
  string color_temp;
  mapping fails;
  object *targets,ob,*targets2;
  int x,y,z,i;
  fails=([]);
  color_temp="";
  r="";

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

  if(explode(arg," ")[0]=="status")
  {
   msg = implode(explode(arg," ")[1..]," ");
   (object) ("/cmds/std/_status");
   "/cmds/std/_status"->cmd_status(msg);
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
    names[x]=lower_case(names[x]);
    if(!ob=find_player(names[x]))
    {
      fails += ([ names[x]:"No such player." ]);
    }
    else if(!interactive(ob) || ob->query_invisible())
    {
      fails += ([ names[x]:"Linkdead." ]);
    }
    else if(check_ignored(names[x]))
    {
      fails += ([ names[x]:"Ignored." ]);
    }
    else if(check_levelignore(names[x]))
    {
    fails +=   ([ names[x]:"Ignored. (Level ignore at "+
                  to_string(check_levelignore(names[x]))+")"]);
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
    if(ob->idle()>=5*60)
    {
      reasons += ({ "Idle "+TP->stime(ob->idle()) });
    }
    if(ob->query_away())
    {
      reasons += ({ "Away '"+ob->query_away()+"'" });
    }

    if( !ob->query_away() && ob->query_status() )
    {
      reasons += ({ "'"+ob->query_status()+"'" });
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
    
    color_temp=COLOURS->give_color(targets[x], "tell");
    if(!strlen(color_temp)) color_temp=BOLD+CYAN_F;

    tell_object(targets[x], color_temp+TP->query_name()+" tells "+
        r+OFF+" '"+msg+"'\n");
/*
    tell_object(targets[x],sprintf("%s tells %s '%s'\n",
        targets[x]+TP->query_name(),r+OFF,msg));
 */

    targets[x]->set_last_tells(rem_tell(sprintf("["+ctime()[11..15]+"] %s tells %s '%s'\n",
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


// Check if the target ignores this player (only specific ignores)
// return 0 on not ignored and 1 if this player is ignored
/****/

check_ignored(str) {
object ob;
string ignore_list;
int i;

ob=find_player(str);

ignore_list=ob->query_ignored();


if (!pointerp(ignore_list)) {  return 0; }

// Check ignore
for(i=0;i<=20;i++) {
if(ignore_list[i] && i) {
if(capitalize(ignore_list[i])==this_player()->query_name()) return 1;               
                        }                    
                   }

return 0;
}


// Check if target ignores us with levelignore. 
// (returns level under which is ignored, 0 == off)
/****/

check_levelignore(str) {
object ob;
string ignore_list;
string *arr;
mapping friends_list;
int i,x;

ob=find_player(str);

ignore_list=ob->query_ignored();
friends_list=(mapping)ob->query_friends();
if(!mappingp(friends_list)) friends_list=([]);
arr=m_indices(friends_list);
x=sizeof(arr);

if (!pointerp(ignore_list)) {  return 0; }

// Check level ignore (first if on friends list)
while(x--) { 
 if(arr[x]==this_player()->query_real_name()) return 0; 
                           } 
if(this_player()->query_wiz() && !ob->query_wiz()) return 0;
if(ignore_list[0]>this_player()->query_level()) return ignore_list[0];
                                  
return 0;
}
