#include <ansi.h>
inherit "obj/armour";

void reset(status x) {
  if(x) return;
  set_name("amulet");
  set_alias("dragon amulet");
  set_short("Beautiful amulet made from Dragon's teeth");
  set_long(""+
"This amulet is beautiful indeed. It's chain is made of the purest\n"+
"gold and it glimmers as the light hits it. Gem in amulet isn't\n"+
"really a gem, but a dragon fang. Fang isn't too beautiful. It's\n"+
"a bit yellowish and rather dull also. The amulet looks ancient.\n");
  set_class(1);
  set_slot("dragonists");
}

void init() {
  add_action("cmd_drago","drago");
  add_action("cmd_summon","summon");
}

status cmd_drago(string str) {
  int i;
  object *us;
  if(!str) { write("Usage: drago (msg)\n"); return 1; }
  us = users();
  if(str == "last") { write(tail("/log/DragoChan.log")+"\n"); return 1; }
  str = this_player()->query_name()+" "+BOLD+"<drago>"+OFF+": "+str+"\n";
  for(i=0;i<sizeof(us);i++)
     if(present("dragon amulet",us[i]))
       tell_object(us[i],str);
  write_file("/log/DragoChan.log","["+ctime()[11..15]+"] "+str);
  return 1;
}


string query_auto_load() { return "/wizards/garath/dragonists/drago_amu.c:"; }
