inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("rags");
    set_short("A lump of rags");
    set_long("Foul smelling rags. You might be able to wear them.\n");
    set_ac(10);
    set_value(10);
    set_weight(6);
    set_stats("con", 1);
    set_stats("hpr", 1);
    set_slot("torso");
}

