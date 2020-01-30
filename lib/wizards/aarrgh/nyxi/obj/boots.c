inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("boots");
    set_alias("boots");
    set_short("A crimson boots of the dark sorcery");
    set_long("These boots are made of crimson colored leather. Magical enchantment can be\n"
             "felt as dark aura surrounds them. The legends rumour that Nyx the mother of\n"
             "chaos summoned one of the grand devils of dark realms and slayed it to create\n"
             "these boots from the devils skin");
    set_ac(5);
    set_value(5000);
    set_stats("int", 16);
    set_stats("wis", 3);
    set_stats("con", -5); 
    set_stats("str", -4);
    set_stats("spr", 17);
    set_slot("feet");

}
