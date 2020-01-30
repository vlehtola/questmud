inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 29);
    call_other(this_object(), "set_name", "nikita");
    call_other(this_object(), "set_alias", "stan");
    call_other(this_object(), "set_short", "Stan Nikita the Doughnut parlor keeper");
    call_other(this_object(), "set_long", "Stan stands up and looks at you hungrily\n"+
                                         "and welcomes you to his parlor.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Stan says: Why is it, that when you kill a man in defence it's heroic, yet when you kill a man in the heat of passion, it's called murder ?\n";
        chat_str[1] =
          "Stan says: I never did a stupid thing in my life before that night.\n";
        chat_str[2] =
          "Stan says: Did you know that if it's below zero, you can see steam rising up from the wounds. \n";
        chat_str[3]=
          "Stan grabs a doughnut and eats it.\n";
        chat_str[4]=
         "Stan says: Mmm, doughnuts.\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Stan says: oh well, looks like I'm gonna have to kill yet another human.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/wayne/weapons/roller");   
    move_object(armour, this_object());
    init_command("wield roller");
 
    weapon = clone_object("/wizards/walla/wayne/armour/doughnut");
    move_object(weapon, this_object());
    init_command("");
}
