inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Ring");
    set_alias("ring");
    set_short("A bluish ring");
    set_long("It is a blue ring. It is very smooth and has a\n" +
                    "beautiful shape. It could be of divine make.\n");
    set_ac(5);
    set_value(2100);
    set_weight(1);
    set_stats("int", -2);
    set_stats("str", 2);
    set_stats("hpr", 1);
    set_slot("finger");
}
