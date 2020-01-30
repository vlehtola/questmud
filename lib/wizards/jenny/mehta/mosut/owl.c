inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(2+random(5));
    set_race("owl");
    set_name("owl");
    set_alias("animal");
    set_short("A wise looking owl is flying by");
    set_long("Very wise looking owl is flying near trees. It seems\n"
             "to be searching some mouses for food. It has big wings\n"+
             "and very sharp looking nails, it might be dangerous to\n"+
             "disturb it.\n");
             
    set_al(-1);
    set_animal(1);
    set_aggressive(0);
}
