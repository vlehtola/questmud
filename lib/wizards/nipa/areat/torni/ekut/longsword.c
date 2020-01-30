inherit "obj/weapon";

start() {
    set_class(7);
    set_sub_type("long sword");
    set_name("long sword");
    set_alias("sword");
    set_short("Glowing mithril longsword");
    set_long("This kind of a sword is the true status\n"+
      "symbol of all battlemages. It has a a beautiful\n"+
     "red glow on it's blade and it feels warm.\n"+
     "It is said that battlemages can enchant the blade\n"+
     "with different elements to make it more powerful\n"+ 
             "in melee combat."); 

    set_stats("spr", 4);
    set_stats("str", 1);
    set_stats("int", 1);
}
