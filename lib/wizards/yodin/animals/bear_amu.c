#include <ansi.h>
inherit "obj/armour";

void reset(status x) {
  if(x) return;
  set_name("amulet");
  set_alias("leather amulet");
  set_short("Beautiful amulet made from wolf skin");
  set_long(""+
"Ompa kiva amuletti.\n");
  set_class(1);
  set_slot("amulet");
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
  return 1;
}

