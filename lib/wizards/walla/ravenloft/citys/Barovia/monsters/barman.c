inherit "obj/monster"; 
 
reset(arg) {
    object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "igor");
    call_other(this_object(), "set_alias", "barman");
    call_other(this_object(), "set_short", "Igor the friendly barman welcomes you to Barovia");
    call_other(this_object(), "set_long", "A very strong and well built man you see behind the desk.\n" +
                                          "It looks asthough there could be some strange intelligence behind that\n" +
                                          "big moustache.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_spell_chance(69, "exs fla blt");          
    set_skill("cast essence", 69); 
    set_skill("cast fire", 69);  
    set_skill("cast bolt", 69);    
    set_skill("mastery of fire", 100);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());
 
}
