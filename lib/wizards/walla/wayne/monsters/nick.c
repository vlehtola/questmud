inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 32);
    call_other(this_object(), "set_name", "nick");
    call_other(this_object(), "set_alias", "nick");
    call_other(this_object(), "set_short", "Nick, assistant of Wayne is checking for bugs in the camera");
    call_other(this_object(), "set_long", "Nick is a 6'0 guy and looks at you really scaery.\n"+
                                         "He makes you wanna laugh.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Nick says: I love you man, I really do, I mean it!\n";
        chat_str[1] =
          "Nick says: Totally wasted dude!\n";
        chat_str[2] =
          "Nick says: Do i frighten you? \n";
        chat_str[3]=
          "Nick start buzzing around with the camera.\n";
        chat_str[4]=
         "Nick says: And may I say that your wife is a babe ?\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Nick says: Hey stop!\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/wayne/weapons/camera");   
    move_object(armour, this_object());
    init_command("wield camera");
 
    weapon = clone_object("/wizards/walla/wayne/armour/shirt");
    move_object(weapon, this_object());
    init_command("wear shirt");
}

