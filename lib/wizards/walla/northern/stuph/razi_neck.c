inherit "obj/armour";
#include <ansi.h>
 
start() {
set_class(9);
  set_slot("neck");
    set_name("necklace");
    set_alias("chain");
    set_short("Golden chain <"+YELLOW_F+"sparkling"+OFF+">");
    set_long("This is the golden chain of Razindukhta. The links are made\n" +
             "out of solid gold. The chain seems to be of dwarven make,\n" +
             "since the craftmanship is so exquisite.");
    set_value(5000);
    set_stats("con",7);
    set_stats("str",5);
    set_weight(30);

}

