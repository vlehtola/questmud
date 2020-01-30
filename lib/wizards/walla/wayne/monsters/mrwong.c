inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 33);
    call_other(this_object(), "set_name", "wong");
    call_other(this_object(), "set_alias", "mister");
    call_other(this_object(), "set_short", "Mister Wong, father of Cassandra (babe)");
    call_other(this_object(), "set_long", "Mister Wong starts talking in some gibberish cantonese \n"+
                                         "accent from which you don't understand shit.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Mister Wong says: Hayaaaaaaaaaaaaa.\n";
        chat_str[1] =
          "Mister Wong jumps back and forth on his hands.\n";
        chat_str[2] =
          "Mister Wong says: You're worthy of my daughter.\n";
        chat_str[3]=
          "Mr. Wong points at you and shouts Akitaakita pang.\n";
        chat_str[4]=
         "Mr Wong says: I was once a knight that said - NI!\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mister Wong says: If we were to fight, it would be better if we'd be dubbed instead of subtitled.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/wayne/weapons/reaper");   
    move_object(armour, this_object());
    init_command("wield reaper");
 
    weapon = clone_object("/wizards/walla/wayne/armour/shoes");
    move_object(weapon, this_object());
    init_command("wear shoes");
}

