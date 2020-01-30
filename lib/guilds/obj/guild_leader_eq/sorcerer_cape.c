#include <ansi.h>
inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("cape");
        set_short("The cape of god Izyldran");
        set_long("This cape is given to the one who is the greatest sorcerer\n"+
                 "living in the world. White colored cape is shining brightly\n"+
                 "and it is rumoured that this cape has been blessed by Izyldran\n"+
                 "who is the archgod of all sorcerers");
        set_weight(400);
        set_value(0);
        set_stats("int", 15);
        set_stats("wis", 10);
        set_stats("spr", 10);
        set_resists("fire", 25);
}





