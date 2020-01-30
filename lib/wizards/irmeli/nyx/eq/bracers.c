inherit "obj/armour";

start() {
    set_class(5);
    set_sub_type("bracers");
    set_short("The Bracers of Eternal fire");
    set_long("The Bracers are burning with eternal fire, but it seems that the\n"+
             "bracers doesn't take any damage from the flames. It's unharmed\n"+
             "and shines like ice, reflecting light brightly everywhere\n"+
             "around it.\n");
    set_stats("wis", 10);
    set_stats("int", 10);
    set_stats("spr", 20);
}
