inherit "obj/weapon";

start() {
    set_class(7);
    set_sub_type("flail");
    set_short("A blood-red flail with long chains");
    set_long("A long, blood-red flail, often used by the slave driver. It's made\n"+
             "of metal, to guarantee the maxinum pain to the victim and the\n"+
             "maxinum satisfaction to the user.\n");
    set_stats("damage",5);
    set_stats("hit",3);
}

