inherit "obj/armour";
 
reset(arg) {
        ::reset(arg);
        set_name("human skin with diamonds");
        set_alias("skin");
        set_short("Human skin with diamonds");
        set_long("this cloak is made of human skins and seems they have needed\n" +
                   "lot's of them. You feel sick just for looking it.\n");
        set_ac(6);
        set_weight(6);
        set_value(12000);
        set_slot("cloak");
        set_resists(4, 1);
        set_stats("int", 10);
        set_stats("wis", 10);
        set_stats("spr", 25);
 
}
 
