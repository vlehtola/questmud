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

static status filter_users(object ob,int mode,string arg) {
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
    if(query_idle(ob) >= 300) return 1;
    else return 0;
  }

  if(mode == UN_IDLE_ONLY) {
    if(query_idle(ob) < 300) return 1;
    else return 0;
  }

  if(ob->query_name() == "Gheldor") return 0;
  if(ob->short(1) == 0) return 0;
  if(!environment(ob)) return 0;
  sec = (int)ob->query_wiz();
  lvl = (int)ob->query_level();
  if(sec) {
    if((ob->query_invis() && sec <= this_player()->query_level()) || !ob->query_invis()) {
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


cmd_nwho(string str) {
  object ob;
  object *user;
  object pager;
  string st1, st2;
  string result;
  string resulti;
  string *options;
  string tmp1,tmp2;
  int a, size, i, numba;

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
  if(options) {
    if(member_array("short",options) != -1) {
      result = "";
      numba = 0;
      resulti = "QuestMud - http://quest.laeppae.com - telnet://quest.laeppae.com:3000 \n";
      for(a=0;a<size;a++) {
         if(user[a]->query_wiz() == 5)
           result += "<  God  >";
         else if(user[a]->query_wiz() == 4)
           result += "<ArchWiz>";
         else if(user[a]->query_wiz() == 3)
           result += "< Elder >";
         else if(user[a]->query_guest())
           result += "[ Guest ]";
         else if(user[a]->query_level() == 0)
           result += "[ Reinc ]";
         else if(user[a]->query_wiz())
           result += sprintf("<  %3d  >",user[a]->query_level());
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
      }
      resulti += "\n"+size +" player(s) shown. \n";
      write(resulti);
      return 1;
    }
  }
  result = "";
  resulti = " Level   |  Name\n";
  resulti += "----------------------------------------------\n";
  for(a = 0;a < size;a++) {
   if(user[a]->query_wiz() == 5)
   result += "<  God  >";
   else if(user[a]->query_wiz() == 4)
   result += "<ArchWiz>";
   else if(user[a]->query_wiz() == 3)
   result += "< Elder >";
   else if(user[a]->query_guest())     
   result += "[ Guest ]"; 
   else if(user[a]->query_level() == 0)
   result += "[ Reinc ]";
   else if(user[a]->query_wiz())
   result += sprintf("<  %3d  >",user[a]->query_level());
   else if(LEADER_D->test_leader(user[a]->query_name(),user[a]->query_race()) && user[a]->query_race())
     result += sprintf(give_bcolor("{",user[a])+"  %3d  "+give_bcolor("}",user[a]),user[a]->query_level());
   else
     result += sprintf(give_bcolor("[",user[a])+"  %3d  "+give_bcolor("]",user[a]),user[a]->query_level());
   result += " "+user[a]->short(1);
 resulti += result;
 resulti += "\n";
   result = "";
}
 resulti += size+" player(s) shown. \n";
  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(resulti);

 return 1;
}

give_bcolor(string str, object ob) {
if(!this_player()->query_terminal()) return str;
if(ob->query_rebirth()) return BLUE_F+str+OFF;
if(ob->query_ghost()) return sprintf("%c",27)+"[1;1;30m"+str+OFF;
return str;
}
