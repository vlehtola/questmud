
#include <ansi.h>
inherit "obj/weapon";

start()  {
    set_class(7);
    set_sub_type("Shining mithril combat knuckles {2.Gup}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+sprintf("%c",27)+"[1;1;31m"+"Red"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are in martial arts.\n");
}
init() {
    ::init();
   add_action("force", "force");
}
int force (str) {
   if(str == "box") {
write("You cannot force box with your knuckles!\n");
  return 1;
   }
  return 0;
}

