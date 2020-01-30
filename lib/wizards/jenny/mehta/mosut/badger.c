inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(9);
    set_race("badger");
    set_name("badger");
    set_alias("animal");
    set_short("Mean looking badger");
    set_long("Mean looking badger which seems to be roaring at\n"
             "everyone and everything near it. It seems to be\n"+
             "devouring a small hummingbird. It is coloured\n"+
             "black and white. It looks dangerous.\n");
    set_al(1);
    set_animal(1);
    set_aggressive(0);
}
