inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "mayor");
    call_other(this_object(), "set_alias", "aloc");
    call_other(this_object(), "set_short", "Aloc Acoc, the mayor of Jericho");
    call_other(this_object(), "set_long", "The newly appropriated mayor of Jericho.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    
 
    armour = clone_object("/wizards/walla/area/armour/coat");
    move_object(armour, this_object());
    init_command("wear coat");
 
    weapon = clone_object("/wizards/walla/area/armour/leggings");
    move_object(weapon, this_object());
    init_command("wear leggings");
}
