inherit "obj/monster";

reset(arg) 
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 51);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_hp", "21000");
    call_other(this_object(), "set_exp", "10000000");
    call_other(this_object(), "set_short", "A mean looking guard");
    call_other(this_object(), "set_long", "This guard guards somthing.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("north");

    armour = clone_object("/wizards/walla/area/weapons/executioner");
    move_object(armour, this_object());
    init_command("wield sword");

    weapon = clone_object("/wizards/walla/area/armour/icering");
    move_object(weapon, this_object());
    init_command("wear ring");
}
