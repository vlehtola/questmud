inherit "obj/monster";

reset(arg) {
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_name", "thief");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_short", "A man clad in dark clothes is standing on the road");
    call_other(this_object(), "set_long", "The man is tall, but still he looks agile. His clothes are dark and\n" +  
                                          "he is wearing a black hood on his head, therefore you are unable to\n" + 
                                          "see his face. He doesn't seem to be paying any attention on you.\n");
    call_other(this_object(), "set_al", -50);
    call_other(this_object(), "set_aggressive", 0);


    weapon = clone_object("/world/mine/eq/c_knife.c");
    move_object(weapon, this_object());
    call_other(this_object(), "init_command", "wield knife");
        
}

