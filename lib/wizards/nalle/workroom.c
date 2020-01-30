// kopsattu Garathilta! :) v�h� optimoitu viel tosin

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(arg) return;

  short_desc = "Nalle's workroom";
  long_desc = ""; 
  property = ({ "no_summon", });
  set_light(10);
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("west","wizards/nalle/workroom2");
  add_exit("jerusalem","wizards/nalle/jerusalem/wgate");
  add_exit("post","world/city/post");
  add_exit("ban","/room/banroom");
}

status is_wizard(object ob) {
if(ob->query_wiz()) return 1;
  return 0;
}

status sort_by_name(object o1, object o2) {
  int s1,s2;
  s1=(int)o1->query_level();
  s2=(int)o2->query_level();
  return s1<s2;
}

long() {
  object *ob;
  int i;
  int idletime;
  string idlestring;
  ob=users();
  ob=filter_array(ob, "is_wizard");
  ob=sort_array(ob, "sort_by_name");
    write("Nalle's workroom.\n");
    write("Wizards currently logged on:\n");
    for(i=sizeof(ob);i--; ) {
      idlestring="";
      idletime=query_idle(ob[i]);
      if(idletime<300) idlestring=YELLOW_F;
      if(idletime<30)  idlestring=GREEN_F;
      if(idletime>=86400) {
        idlestring+=((idletime-(idletime%86400))/86400)+"d ";
        idletime=idletime%86400;
      }
      if(idletime>=3600) {
        idlestring+=((idletime-(idletime%3600))/3600)+"h ";
        idletime=idletime%3600;
      }
      if(idletime>=60) {
        idlestring+=((idletime-(idletime%60))/60)+"m ";
        idletime=idletime%60;
      }
      idlestring+=idletime+"s ";
      
      write(sprintf("   <%6|d>  %10-s   (idle: %s"+OFF+") ",
  ob[i]->query_level(),
  capitalize(ob[i]->query_real_name()), idlestring)+"\n");
    }
 
write("Current time is: "+BOLD+ctime(time())[11..15]+OFF+"\n");
    ::long();
}

