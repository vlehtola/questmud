inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("hat");
    set_alias("gnomehat");
    set_short("The hat of the Gnome");
    set_long("This hat was given to a gnome by Darvox to increase it's intelligence\n");
    set_ac(5);
    set_value(1212);
    set_weight(2);
    set_stats("str", -1);
    set_stats("int", 7);
    set_slot("head");
}
