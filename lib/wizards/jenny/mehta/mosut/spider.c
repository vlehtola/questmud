inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(6+random(7));
    set_race("spider");
    set_name("spider");
    set_alias("animal");
    set_short("A small woolly spider");
    set_long("A small woolly spider is hanging from the ceiling. It\n"
             "is weaving a cobweb, but the net looks very fragile.\n"+
             "The arachnid doesn't look very dangerous, but it might\n"+
             "be poisonous.\n");
             
    set_al(-3); 
    set_animal(1);
    set_aggressive(1);
}
