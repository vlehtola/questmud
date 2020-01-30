inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(4);
    set_race("bird");
    set_name("hummingbird");
    set_alias("animal");
    set_short("A small hummingbird");
    set_long("Cute multicolored hummingbird with a tiny tiny\n"
             "beak and cute little wings. It is looking for\n"+
             "flowers and it seems to be incautious to all\n"+
             "things around it.\n");
    set_al(1);
    set_animal(1);
    set_aggressive(0);
}
