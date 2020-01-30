inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 28);
    call_other(this_object(), "set_name", "roger");
    call_other(this_object(), "set_alias", "pirate");
    call_other(this_object(), "set_short", "Roger Jolly, the ship captain");
    call_other(this_object(), "set_long", "Roger is dressed in a great looking black suit, with golden buttons on.\n"+
                                         "He has a nice hat and a sword dangling from his belt. He doesn't seem to bother with\n" +
                                         "you having come in. He is too busy plotting an assault with Jack Parrot-hat.\n");
    call_other(this_object(), "set_al", 10);
 call_other(this_object(), "set_aggressive", 0);                  
   if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Roger Jolly says: Ye knew. Ey reccon that thie shippe wille be loaded wit' soldiers.\n";
        chat_str[1] =
          "Roger Jolly says: Aye, it's all true, but the maine thinge is to git the gold safely to Cotton-Eye Joe.\n";
        chat_str[2] =
          "Roger sings: Y have pillaged and burnt, I have no lessons learnt.\n";
        chat_str[3]=
          "Roger says: Cotton-Eye Joe needs all the gold he cans gets. We will sinks thatte shippe temerrew.\n";
        chat_str[4]=
          "Roger Jolly says: Ye knew, thise is the best bar Y remember. And Y remember until yesterday.\n";
 
  }
    if (!a_chat_str) {
 a_chat_str = allocate(1);                
 a_chat_str[0] = "Ye damn fool.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/peepseye/eq/armour/captainshat");
    move_object(armour, this_object());
    init_command("wear hat");
 
    weapon = clone_object("/wizards/walla/peepseye/eq/weapons/captainssword");
    move_object(weapon, this_object());
    init_command("wield sword");
}

