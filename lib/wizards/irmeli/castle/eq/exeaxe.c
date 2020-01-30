inherit "obj/weapon";

start() {
    set_class(6);
    set_sub_type("great axe");
    set_alias("axe");
    set_short("Great axe called 'Head Cutter'");
    set_long("Many men has been killed by this axe. Its handle is made of wood.\n"+
             "The bit of the axe is huge, sharp and full of old bloodstains.\n"+
             "A black text have been carved in the handle but you can't read\n"+
             "it because it's worn. You can imagine yourself as a killer\n"+
             "with this axe possessed.\n");
    set_stats("damage",2);
    set_stats("hit",1);
    set_stats("con",3);
}

