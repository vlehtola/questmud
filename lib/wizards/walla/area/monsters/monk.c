inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "monk");
    call_other(this_object(), "set_alias", "monk");
    call_other(this_object(), "set_short", "Monk of the order of Leb-Kamar");
    call_other(this_object(), "set_long", "The monk gurgles some prayer for you as he sees you.\n" +
                                          "He does not look so happy. Maybe it's because Leb-Kamar is back from the\n" +
                                          "crusades.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
 armour  = clone_object("/wizards/walla/area/armour/monkkirobe");
    move_object(armour, this_object());
    init_command("wear robes");
 
 
}
