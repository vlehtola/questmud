inherit "obj/armour";

start() {
        set_slot("cloak");
        set_name("cloak");
        set_short("A cloak made of strange substance");
        set_long("This cloak is made of somekind of substance, the surface of cloak is\n"+
                 "amazing. The substance seems to shifting and changing all the time.\n");
        set_value(1000);
        set_weight(600);
        set_stats("str", 7);
        set_stats("con", 5);
        set_stats("dex", 5);
        set_stats("wis", -8);
        set_stats("int", -6);
        set_stats("spreg", -15);
}
