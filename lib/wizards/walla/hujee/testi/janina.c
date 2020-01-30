inherit "obj/monster";
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);   
    if(arg) { return; }
    call_other(this_object(), "set_level", 121);
    call_other(this_object(), "set_name", "Janina");
    call_other(this_object(), "set_alias", "janina");
    call_other(this_object(), "set_short", "Hjanina Frostell poses here");
    call_other(this_object(), "set_long", "Janina is SOOOOOOOOOO cute.\n" +
                                          "She is here to please Walla\n" +
                                          "So piss off.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
     
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/hujee/testi/suit");
    move_object(armour, this_object());
    init_command("wear suit");
 
}

