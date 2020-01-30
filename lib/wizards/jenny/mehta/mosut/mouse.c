inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(2+random(2));
    set_race("mouse");
    set_name("mouse");
    set_alias("animal");
    set_short("A common forest mouse");
    set_long("A normal and very common looking forest mouse which\n"
             "seems to be avoiding crows and owls by running very\n"+
             "fast from bush to bush. It is coloured grey and it's\n"+
             "squeaking constantly.\n");
             
    set_al(-1);
    set_animal(1);
    set_aggressive(0);
}
