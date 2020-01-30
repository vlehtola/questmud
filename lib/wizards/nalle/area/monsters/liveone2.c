inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_animal();
    call_other(this_object(), "set_level", 32);
    call_other(this_object(), "set_name", "Liveone");
    call_other(this_object(), "set_alias", "liveone");
    call_other(this_object(), "set_short", "A failed creation of unholy dimensions");
    call_other(this_object(), "set_long", "The liveone looks tyrannous. Its organs are visible and pulsating.\n");
    call_other(this_object(), "set_al", -15);
    call_other(this_object(), "set_aggressive", 1);


    armour = clone_object("/wizards/nalle/area/eq/livingcrown");
    move_object(armour, this_object());
    init_command("wear helm");
}
