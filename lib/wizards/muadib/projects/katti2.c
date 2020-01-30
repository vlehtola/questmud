inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(10000);
    set_name("cat");
    set_alias("cat");
    set_short("A tiny cat called Errtu");
    set_long("This being was once a great dog daemon, \n" +
             "well until he ran across the great human \n" +
             "wizard called Muadib. The daemon made the \n" +
             "mistake to piss the wizard off and Muadib \n" +
             "changed the proud and majastetic beast in \n" +
             "to his household pet\n");
    set_al(10);
    set_aggressive(0);
    set_animal(1);
}
