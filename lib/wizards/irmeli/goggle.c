inherit "obj/armour"; 
 
start() {
set_class(7);
    set_slot("head");
    set_name("goggles");
    set_short("Alchemist's goggles");
    set_long("As you look through these goggles, all you see is red, because the glasses\n"+
             "are red. A leather string is attached to the goggles, it's purpoise is to\n"+
             "hold tight the goggles on wearer's head");
    set_stats("str", 10);
    set_stats("con", 5);
    set_stats("dex", 2);
    set_value(6000);
    set_weight(200);
}
