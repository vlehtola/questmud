inherit "obj/monster"; 
 
reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "citizen");
    call_other(this_object(), "set_short", "A grubby looking gateguard looking at you suspiciously");
    call_other(this_object(), "set_long", "The gateguard seems bored of his work.\n" +
                                          "He doesn't like trouble-doers in the city.\n" +
                                          "I wouldn't piss him off if I were you.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("stairs");

    armour = clone_object("/wizards/walla/area/armour/garmour");
    move_object(armour, this_object());
    init_command("wear plate");
}

