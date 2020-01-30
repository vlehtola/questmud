inherit "obj/armour";

start() {
        set_class(10);
        set_sub_type("bracers");
        set_slot("arms");
        set_name("bracers");
        set_short("Ancient dragonskin bracers");
        set_long("These bracers had been lost since you found them and they seem to\n"+
                 "have somekind of enchantments, good or bad it can't be said.\n"+
                 "It is certain that these bracers were made from one of greatest's\n"+
                 "dragons skin so these should be AWESOME quality if nothing else\n");
        set_value(0);
        set_stats("str", 10);
        set_stats("con", 10);
        set_stats("dex", 10);
        set_stats("int", -5);
        set_stats("wis", -5);
        set_stats("hpr", 10);
        set_resists("fire", 40);

}