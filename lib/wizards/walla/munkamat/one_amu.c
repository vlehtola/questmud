inherit "obj/armour";  
#include <ansi.h>
start() {

set_class(1);
set_slot("amulet");
set_name("amulet");
set_alias("one");
set_short("An ancient amulet called '"+CYAN_F+"One"+OFF+"'");
set_long("This amulet shines with the blinding radiance of the sun, and glitters\n"+
         "in all the colours and yet none. The amulet was forged in the fires\n" +
         "of the gods during the creation of the world, and you can feel an \n" +
         "incredible surge of power just by looking at it.");
set_value(0);
set_weight(1);
}



