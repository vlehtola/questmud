inherit "obj/armour";
 
reset(arg) {
    ::reset(arg);
    set_name("hat");
    set_alias("hat");
    set_short("Cooks hat");
    set_long("This is white cooks hat.\n",
             "It seems to be magical.\n");
    set_ac(10);
    set_value(5000);
    set_weight(50);
    set_stats("int", 5);
    set_stats("wis", 5);
    set_slot("head");
}
