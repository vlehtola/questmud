inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 27);
    call_other(this_object(), "set_name", "jack");
    call_other(this_object(), "set_alias", "pirate");
    call_other(this_object(), "set_short", "Jack Parrot-hat, sitting at the table");
    call_other(this_object(), "set_long", "Jack Parrot-hat is the pirate you wouldexpect to\n"+
                                         "see in a place like this. He has a hat, inwhich is embedded\n" +
                                         "a parrots beak.\n");
    call_other(this_object(), "set_al", 10);
call_other(this_object(), "set_aggressive", 0);                  
  if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Jack Parrot-hat says: Thayre ais ai shippement of gunpewder cummin in temerrew.\n";
        chat_str[1] =
          "Jack Parrot-hat starts singing: And a barrel of ale for me mates and Y.\n";
        chat_str[2] =
          "Jack's parrot-hat squeeks.\n";
        chat_str[3]=
          "Jack Parrot-hat says: We will slaye all theym mightei royalytites.\n";
        chat_str[4]=
      "Jack Parrot-hat says: Ye knew. I have sailed the seven seas, but this will be me home.\n";
 
  }
    if (!a_chat_str) {
 a_chat_str = allocate(1);                       
 a_chat_str[0] = "Me parrot in me hat doesn't like fights.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/peepseye/eq/armour/parrothat");
    move_object(armour, this_object());
    init_command("wear hat");
 
    weapon = clone_object("/wizards/walla/peepseye/eq/weapons/piratesword");
    move_object(weapon, this_object());
    init_command("wield sword");
}
