inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(7);
    set_race("crow");
    set_name("crow");
    set_alias("animal");
    set_short("Black crow is shrieking here");
    set_long("Black crow is shrieking here with an awful voice.\n"
             "It seems to be completely black and it is searching\n"+
             "for dead animals to eat. It is disgusting.\n");
             
    set_al(-1);
    set_animal(1);
    set_aggressive(0);
}
