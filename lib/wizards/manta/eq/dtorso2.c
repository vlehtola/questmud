inherit "obj/armour";
 
reset(arg) {
        ::reset(arg);
        set_name("robes");
        set_alias("robe");
        set_short("Robes of Hell");
        set_long("This robe is made of tormented souls gathered from hell\n" +
                   "it's bright red and you think you saw faces in it.\n");
        set_ac(80);
        set_weight(8);
        set_value(50000);
        set_slot("torso");
        set_stats("int", 10);
        set_stats("wis", 20);
        set_stats("con", 5);
        set_stats("str", -10);
        set_stats("dex", -10);
        set_stats("spr", 40);
 
}
 
