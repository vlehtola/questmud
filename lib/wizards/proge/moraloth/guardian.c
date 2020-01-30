inherit "obj/monster";

reset(arg) {
    object sword;
    ::reset(arg);
    if(arg) { return ; }
    call_other(this_object(), "set_level", 46);
    call_other(this_object(), "set_name", "guardian");
    call_other(this_object(), "set_short", "Horrid guardian of the forest");
    call_other(this_object(), "set_long", 
"This horrible creature before you is dressed in black rags stained\n"+
"with blood. Its swinging its huge evil looking sword in the air.\n"+
"It makes no noise as it is moving towards you. The air around it\n"+
"stinks of death and dread.\n");
    call_other(this_object(), "set_al", -170);
    call_other(this_object(), "set_aggressive", 1);
    call_other(this_object(), "set_undead", 1);
    set_mage(2, 90);
    set_log();
    sword = clone_object("/wizards/proge/moraloth/sword");
    move_object(sword, this_object());
    init_command("wield blade");
} 
