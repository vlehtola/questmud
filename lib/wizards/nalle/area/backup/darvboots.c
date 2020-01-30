inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Boots");
    set_alias("boots");
    set_short("Boots of the Infinate Plains");
    set_long("A pair of sturdy, sand yellow boots, from the realm\n" +
                    "of the Infinate Plains.\n");
    set_ac(22);
    set_value(1200);
    set_weight(3);
    set_stats("str", 4);
    set_stats("con", 4);
    set_stats("hpr", 4);
    set_slot("feet");
}

