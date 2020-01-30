inherit "obj/monster"; 
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 200);
    call_other(this_object(), "set_name", "man");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "Man at work");
    call_other(this_object(), "set_long", "This man works hard here to make the city ready for the arrival of Leb-Kamar.\n" +
                                       "He prepares a road ready for his triumph.\n" +
                                          "He's happy.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("stairs");
 
 
 
    armour = clone_object("/wizards/walla/area/armour/helmet");
    move_object(armour, this_object());
    init_command("wear helmet");
}
