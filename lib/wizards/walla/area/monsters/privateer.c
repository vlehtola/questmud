inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("troll");
    call_other(this_object(), "set_level", 60);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "The private guard of Leb-Kamar");
    call_other(this_object(), "set_long", "This guards mission is to protect Leb-Kamar with his life.\n" +
                                          "He is devoted to keep people off his masters area.\n" +
                                          "And since you've arrived, he has changed...\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 1);
    
 
    armour = clone_object("/wizards/walla/area/weapons/guardsword");
    move_object(armour, this_object());
    init_command("wield sword");
 
    weapon = clone_object("/wizards/walla/area/armour/guardarmour");
    move_object(weapon, this_object());
    init_command("wear plate");
} 
