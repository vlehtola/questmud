inherit "obj/armour";
#include <ansi.h>
reset(arg) {
    ::reset(arg);
    set_name("amulet");
    set_alias("amulet");
    set_short(""+BLUE_F+"Sizzling"+OFF+" platinum amulet");
    set_long("This amulet is made of platinum and seems to be\n"+
             "sizzling with some magical powers. Strong looking\n"+
             "leather string tied on both edges of the amulet\n"+
             "holds the precious looking item on it's place while\n"+
             "being in the heat of the battle.\n");

    set_ac(10);
    
    set_stats("str", 3);
    set_stats("con", 1);
    set_slot("amulet");
    set_value(6000);
}
