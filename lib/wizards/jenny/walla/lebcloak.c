inherit "obj/armour";

start() {
set_class(6);
  set_slot("cloak");
    set_name("cape");
    set_alias("cloak");
    set_short("A velvet cloak with a golden eagle");
    set_long("You see a burgundy coloured velvet cloak, with a golden eagle \n"+
             "before you. The cloak seems to be quite heavy, and is a bit \n"+
             "oversized for you. Still, feel a strange feeling as you put it on.");
    set_value(5000);
    set_stats("dex",3);
    set_stats("int",2);
    set_stats("wis",3);
    set_stats("con",5);
    set_stats("spr",10);
    set_weight(8);

}

