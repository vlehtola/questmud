inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "dog");
    call_other(this_object(), "set_alias", "barf");
    call_other(this_object(), "set_short", "Garth's lookalike dog");
    call_other(this_object(), "set_long", "Garth's dog waggs its tail at you\n"+
                                         "and bites you.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 1);
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Dog barks at you.\n";
        chat_str[1] =
          "Dog barks at you.\n";
        chat_str[2] =
          "Dog wags his tail and barks at you. \n";
 
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Dog says: Wuff.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
 
    armour  = clone_object("/wizards/walla/wayne/armour/bone");
    move_object(weapon, this_object());
    init_command("wield bone");
}
