inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Leggings");
    set_alias("leggings");
    set_short("Rainbow coloured leggings");
    set_long("Coulourful leggings, which make your fingertips\n" +
                    "tingle as you handle them.\n");
    set_ac(15);
    set_value(2100);
    set_weight(30);
    set_stats("wis", 2);
    set_stats("int", 2);
    set_stats("spr", 10);
    set_slot("legs");
}
