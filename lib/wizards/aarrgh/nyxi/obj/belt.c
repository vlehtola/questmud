inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("belt");
    set_alias("belt");
    set_short("A dusty belt made of bones");
    set_long("This plated belt is covered with dust. The buckle holds a polished human skull in it and\n"
             "there is a certain magical energy flowing in the belt. The wearer of this belt is known to\n"
             "gain some special abilities through it. This belt is more heavier than normal belts.");
    set_ac(5);
    set_value(5000);
    set_weight(150);
    set_stats("int", 3);
    set_stats("wis", 4);
    set_stats("con", 3);
    set_stats("spr", 10);
    set_slot("belt");

}
