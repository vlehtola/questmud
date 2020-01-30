#include <ansi.h>

#define LEADER_D "/daemons/leader_d"

#define WIZ_ONLY 1
#define MORTAL_ONLY 2
#define NEWBIE_ONLY 3
#define MIDBIE_ONLY 4
#define HIGHBIE_ONLY 5
#define LEVEL_MAX_ONLY 6
#define LEVEL_MIN_ONLY 7
#define IDLE_ONLY 8
#define UN_IDLE_ONLY 9

#define HR "------------------------------------------------------------------------------\n"

static status filter_users(object ob,int mode,string arg) 
{
  int sec, lvl,level;
  int tmp1;
  if(mode == WIZ_ONLY) {
    if(ob->query_wiz()) return 1;
    else return 0;
  }

  if(mode == MORTAL_ONLY) {
    if(!ob->query_wiz()) return 1;
    else return 0;
  }

  if(mode == NEWBIE_ONLY) {
    if(ob->query_level() < 30) return 1;
    else return 0;
  }

  if(mode == MIDBIE_ONLY) {
    if(ob->query_level() >= 30 && ob->query_level() <= 80) return 1;
    else return 0;
  }

  if(mode == HIGHBIE_ONLY) {
    if(ob->query_level() > 80 && !ob->query_wiz()) return 1;
    else return 0;
  }

  if(mode == LEVEL_MAX_ONLY) {
    if(!arg) return 0;
    sscanf(arg,"%d",tmp1);
    if(ob->query_level() <= tmp1) return 1;
    else return 0;
  }

  if(mode == LEVEL_MIN_ONLY) {
    if(!arg) return 0;
    sscanf(arg,"%d",tmp1);
    if(ob->query_level() >= tmp1) return 1;
    else return 0;
  }

  if(mode == IDLE_ONLY) {
if(ob->idle() >= 300) return 1;
    else return 0;
  }

  if(mode == UN_IDLE_ONLY) {
if(ob->idle() < 300) return 1;
    else return 0;
  }

  if(ob->short(1) == 0) return 0;
  if(!environment(ob)) return 0;
  sec = (int)ob->query_wiz();
  lvl = (int)ob->query_level();
  if(sec) 
   {
    if((ob->query_invis() && sec <= this_player()->query_wiz()) || !ob->query_invis()) 
      {
       return 1;
      }
   }
  else {
    if(!ob->query_invis()) {
      return 1;
    }
  }
  return 0;
}


static status by_sec_level(object a, object b) {
  if((int)a->query_wiz() == (int)b->query_wiz()
    && (int)a->query_level() < (int)b->query_level()) return 1;
  return
  ((int)a->query_wiz() < (int)b->query_wiz()) ? 1 : 0;
}


cmd_who(string str) {
  object ob;
  object *user;
  object pager;
  string st1, st2;
  string result;
  string resulti;
  string *options;
  string tmp1,tmp2;
  int a, size, i, numba, players;
  int avg_level, avg_mort_level, mortals, avg_idle;

  user = users();
  if(str) options = explode(str," ");

  if(options) {
    if(member_array("wiz",options) != -1)
      user = filter_array(user,"filter_users",this_object(),WIZ_ONLY);
    else if(member_array("mortal",options) != -1)
      user = filter_array(user,"filter_users",this_object(),MORTAL_ONLY);
    else if(member_array("newbie",options) != -1)
      user = filter_array(user,"filter_users",this_object(),NEWBIE_ONLY);
    else if(member_array("midbie",options) != -1)
      user = filter_array(user,"filter_users",this_object(),MIDBIE_ONLY);
    else if(member_array("highbie",options) != -1)
      user = filter_array(user,"filter_users",this_object(),HIGHBIE_ONLY);
    else if(member_array("max",options) != -1 && sizeof(options) > 1)
      user = filter_array(user,"filter_users",this_object(),LEVEL_MAX_ONLY,options[(member_array("max",options)+1)]);
    else if(member_array("min",options) != -1 && sizeof(options) > 1)
      user = filter_array(user,"filter_users",this_object(),LEVEL_MIN_ONLY,options[(member_array("min",options)+1)]);
    else if(member_array("idle",options) != -1)
      user = filter_array(user,"filter_users",this_object(),IDLE_ONLY);
    else if(member_array("unidle",options) != -1)
      user = filter_array(user,"filter_users",this_object(),UN_IDLE_ONLY);
  }

  user = filter_array(user,"filter_users",this_object());
  user = sort_array(user, "by_sec_level", this_object());
  size = sizeof(user);
  players = 0;
  mortals = 0;
  avg_level = 0;
  avg_mort_level = 0;
  avg_idle = 0;

  // Mr. C goes 1st. :) -N
  if(find_player("celtron"))
   {
    int z;
    object tmp;
    z = member_array(find_player("celtron"), user);
    if  ( z != -1 && z != 0)
	{
	 tmp = user[0];
	 user[0] = user[z];
	 user[z] = tmp;
	}
   }
  
  if(options) {
    if(member_array("short",options) != -1) {
      result = "";
      numba = 0;
      resulti = "QuestMud - http://quest.laeppae.com - telnet://quest.laeppae.com:3000 \n";

 for(a=0;a<size;a++) 
 {
  if(!user[a]->query_invisible())
  { // Invis IF
   
   players++;
   if(user[a]->query_wiz() == 5)
   result += give_bcolor("<",user[a])+" Elder "+give_bcolor(">",user[a]);
   else if(user[a]->query_wiz() == 4)
   result += give_bcolor("<",user[a])+"ArchWiz"+give_bcolor(">",user[a]);
   else if(user[a]->query_wiz() == 3)
   result += give_bcolor("<",user[a])+" Adept "+give_bcolor(">",user[a]);
   else if(user[a]->query_guest())     
           result += "[ Guest ]";
         else if(user[a]->query_level() == 0)
     result += sprintf(give_bcolor("[",user[a])+" Reinc "+give_bcolor("]",user[a]));
         else if(user[a]->query_wiz())
     result += sprintf(give_bcolor("<",user[a])+"  %3d  "+give_bcolor(">",user[a]),user[a]->query_level());
         else if(LEADER_D->test_leader(user[a]->query_name(),user[a]->query_race()) && user[a]->query_race())
     result += sprintf(give_bcolor("{",user[a])+"  %3d  "+give_bcolor("}",user[a]),user[a]->query_level());
   else
     result += sprintf(give_bcolor("[",user[a])+"  %3d  "+give_bcolor("]",user[a]),user[a]->query_level());
          result += sprintf(" %-10s",capitalize(user[a]->query_real_name()));
         resulti += result;
         numba++;
         if(a != size && numba >= 4) { resulti += "\n"; numba = 0; }
         else if(a != size && numba < 4) resulti += "";
         else resulti += "\n";
         result = "";
  } // Invis IF
 } // FOR loop

      resulti += "\n"+players +" player(s) shown. \n";
      write(resulti);
      return 1;
    }
  }
  result = "";
  resulti = " "+bold_color("Level")+"   |  "+bold_color("Name")+"\t\t\t     "+bold_color("QuestMud")+" - quest.laeppae.com 3000\n";
  resulti += HR;
  players = 0;

  for(a = 0;a < size;a++) 
  { // FOR loop

 if(!user[a]->query_invisible())
 { // Invis IF

   players++;

   // Some extra stats. --N Apr '04

   avg_level += user[a]->query_level();

   avg_idle  += query_idle( user[a] );

   if(!user[a]->query_wiz())
     {
      avg_mort_level += user[a]->query_level();
      mortals++;
     }

   if(user[a]->query_wiz() == 5)
   result += give_bcolor("<",user[a])+" Elder "+give_bcolor(">",user[a]);
   else if(user[a]->query_wiz() == 4)
   result += give_bcolor("<",user[a])+"ArchWiz"+give_bcolor(">",user[a]);
   else if(user[a]->query_wiz() == 3)
   result += give_bcolor("<",user[a])+" Adept "+give_bcolor(">",user[a]);
   else if(user[a]->query_guest())     
   result += "[ Guest ]"; 
   else if(user[a]->query_level() == 0)
     result += sprintf(give_bcolor("[",user[a])+" Reinc "+give_bcolor("]",user[a]));
   else if(user[a]->query_wiz())
     result += sprintf(give_bcolor("<",user[a])+"  %3d  "+give_bcolor(">",user[a]),user[a]->query_level());
   else if(LEADER_D->test_leader(user[a]->query_name(),user[a]->query_race()) && user[a]->query_race())
     result += sprintf(give_bcolor("{",user[a])+"  %3d  "+give_bcolor("}",user[a]),user[a]->query_level());
   else
     result += sprintf(give_bcolor("[",user[a])+"  %3d  "+give_bcolor("]",user[a]),user[a]->query_level());

   // Invis-brackets
   if(user[a]->query_invisibility_level() && this_player()->query_wiz())
      result += " "+user[a]->short(1)+" "+invis_color("(I"+user[a]->query_invisibility_level()+")");
       else
      result += " "+user[a]->short(1);

 resulti += result;
 resulti += "\n";
   result = "";
 }
   } // endof FOR loop

 resulti += bold_color( ""+ players ) +" players, "+ bold_color( ""+ mortals ) + " mortals.";

 if(players)
  resulti += " Average mortal level "+ bold_color( ""+ (avg_mort_level/mortals) )+", average idletime "+
	     bold_color(  int_to_time(avg_idle/players) )+".\n";

  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(resulti);

 return 1;
}

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

// Just give yellow
invis_color(string str)
{
 if(this_player()->query_terminal()) 
  return YELLOW_F+str+OFF;
 else 
  return str;
}

// Just give bold
bold_color(string str)
{
 if(this_player()->query_terminal()) 
  return BOLD+str+OFF;
 else 
  return str;
}

//

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

