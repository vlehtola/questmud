inherit "obj/armour";

start() {
set_class(1);
    set_slot("head");
    set_name("hood");
    set_short("The dark hood of Thousand Flames");
    set_long("This hood belongs to the executioner of the Castle Asgroth. Old bloodstains\n"+
             "are covering the hood. There are flames sewed on it. It can be used as a\n"+
             "protection against flames. It's a normal-sized hood. It's made of some strange\n"+
             "material which you can't recognize");
    set_stats("con", 5);
    set_stats("str", 1);
    set_stats("dex", 1);
    set_resists("fire", 5);
   value = 2000;
    set_weight(100);
}


