inherit "obj/armour";

start() {
    set_class(6);
        set_sub_type("arm guards");
        set_short("Arm guards of witchcraft");
        set_long("Arm guards of witchcraft.\n"+
                 "The arm guards are quite old looking and dented, but somehow\n"+
                 "arm guards looks magical");
        set_stats("str", -10);
        set_stats("con", 8);
        set_stats("wis", 12);
        set_stats("int", 12);
        set_stats("spr", 15);
        set_weight(500);
}
