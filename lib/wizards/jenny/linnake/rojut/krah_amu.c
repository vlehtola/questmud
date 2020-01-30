inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("amulet");
    set_alias("amulet");
    set_short("Krah, Amulet of happiness");
    set_long("Ancient amulet made by Krah, god of happiness.\n"
             "There are many happy looking pictures engraved\n"
             "on it and it glows nicely");
    set_ac(10);
    set_value(20000);
    set_stats("int", 2);
    set_stats("wis", 2);
    set_stats("str", 2);
    set_stats("dex", 2);
    set_stats("con", 2); 
    set_slot("amulet");

}
