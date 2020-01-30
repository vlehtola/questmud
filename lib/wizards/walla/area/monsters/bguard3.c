inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 40);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A guard watching around for intruders");
    call_other(this_object(), "set_long", "The gateguard seems bored of his work.\n" +
                                          "He guards the minaret.\n" +
                                          "I wonder why.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("down");
 
    armour = clone_object("/wizards/walla/area/weapons/gsword");
    move_object(armour, this_object());
    init_command("wield sword");
 
    weapon = clone_object("/wizards/walla/area/armour/ghelmet");
    move_object(weapon, this_object());
    init_command("wear helmet");
}

