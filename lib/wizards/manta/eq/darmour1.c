inherit "obj/armour";

 reset(arg) {
        ::reset(arg);
        set_name("fire armour");
        set_alias("armour");
        set_short("A fire armour");
        set_long("this armour is given to all recruits after their training.\n");
        set_ac(20);
        set_weight(10);
        set_value(1000);
        set_slot("torso");
        set_resists(3, 1);
        set_stats("str", 5);
        set_stats("wis", -4);

}

