inherit "obj/armour";

start() {
    set_name("Pendant");
    set_alias("pendant");
    set_short("Pendant of Eldamar");
    set_long("The sheer magical power of this ancient magical item makes your eyes burn\n"+
             "Looks like this might have been the cause that stirred the lich-lord into summoning all those nasty creatures.\n");
    set_value(21);
    set_weight(4);
    set_stats("wis", 7);
    set_stats("int", 7);
    set_stats("spr", 12);
    set_slot("amulet");
}
