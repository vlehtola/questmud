inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("armour");
    set_alias("breastplate");
    set_short("Ethereal Breastplate");
    set_long("It is almost transparent, there is only slight flue in the colours behind it.\n");
    set_ac(60);
    set_value(21000);
    set_weight(7);
    set_stats("str", 11);
    set_stats("hpr", 11);
    set_slot("torso");
}
