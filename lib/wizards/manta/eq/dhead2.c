inherit "obj/armour";
 
 reset(arg) {
        ::reset(arg);
        set_name("Skull cap");
        set_alias("cap");
        set_short("A skull cap of K'zing");
        set_long("This skull cap of K'tung it is made of polished skulls\n" +
                   "taken from defeated enemies and enchanted by wizards.\n");
        set_ac(25);
        set_weight(5);
        set_value(10000);
        set_slot("head");
        set_resists(5, 1);
        set_stats("int", 10);
        set_stats("con", 10);
        set_stats("hpr", 10);
        set_stats("spr", 10);
 
}
 
