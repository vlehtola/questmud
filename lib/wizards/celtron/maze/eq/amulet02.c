inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("amulet");
    set_alias("amulet");
    set_short("A black amulet with bright red runes");
    set_long("An odd looking amulet. There seems to be some red runes carved on it and\n"+
             "the amulet seems to be emitting a magical aura which surrounds it calmly");
    set_ac(5);
    set_value(10000);
    set_stats("int", 2);
    set_stats("wis", 2);
    set_stats("str", -3);
    set_stats("con", -2); 
    set_stats("spr", 5);
    set_slot("amulet");

}
