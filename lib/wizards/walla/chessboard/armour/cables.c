inherit "obj/armour"; 
 
reset(arg) {
    ::reset(arg);
    set_name("cables");
    set_alias("cables");
    set_short("Deep Blue's(tm) cables");
    set_long("These are the cables of Deep Blue(tm). As you look at the bunch, you notice\n" +
                      "that it could be used as a cloak.\n");
    set_material(3);
    set_ac(21);
    set_value(10000);
    set_weight(2);
    set_stats("int", 3);
    set_stats("hpr",5);
    set_slot("cloak");
 
}
