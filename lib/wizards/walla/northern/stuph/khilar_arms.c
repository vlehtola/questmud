inherit "obj/armour";
#include <ansi.h>

   start() {
   set_class(5);
   set_sub_type("arm guards");
   set_name("bracelets");
   set_alias("guards");
   set_short("Bloody Bracelets of Dwarven warfare <"+RED_F+"dripping blood"+OFF+">");
   set_long("These bloody bracelets seem to have been ripped of some poor\n"+
            "souls arms, as you can still see chunks of flesh on them. They\n"+
            "are dripping blood and feel wierd to your touch. Yet you feel like\n"+
            "these are one of the most powerful pieces of equipment that you\n"+
            "have ever come upon.");
   set_stats("str", 7);
   set_stats("con", 7);
   set_stats("hit",9);
   set_stats("dam",9);


 }

