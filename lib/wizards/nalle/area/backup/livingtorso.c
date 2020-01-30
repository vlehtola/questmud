inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("torso");
    set_short("The living torso");
    set_long("Foul smelling rags. You might be able to wear them.\n");
    set_ac(50);
    set_value(21210);
    set_weight(5);
    set_stats("con", 10);
    set_stats("hpr", 10);
    set_slot("torso");
}

