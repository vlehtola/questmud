inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "man");
    call_other(this_object(), "set_exp", "50000");
    call_other(this_object(), "set_alias", "gypsie");
    call_other(this_object(), "set_short", "A middle aged gyspie man playing on his balalaika.");
    call_other(this_object(), "set_long", "This man is clad in white and red clothes and seems to\n"+
                                "enjoy sitting by himself by the bonfire singing and playing his balalaika\n" +                                        "and drowning all his sorrows with a bottle of Vodka.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);
     if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Gypsie sings: Once upon a time there was a tavern...\n";
        chat_str[1] =
          "Gypsie sings: Those were the days my friend.\n";
        chat_str[2] =
          "Gypsie engages in a balalaika solo making his fingers bleed and a string snap audibly *snap*.\n";
        chat_str[3]=
          "Gypsie takes his bottle and sips carefully from it.\n";
        chat_str[4]=
         "Gypsie states: I hope my wife, Petra, doesn't see me.\n";
 
  }
    if (!a_chat_str) {
 a_chat_str = allocate(1);                       
a_chat_str[0] = "I want to got to town tonight.\n";
    }
 
 load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/ravenloft/areas/vistani_camp/armour/gypsiedress_man");
    move_object(armour, this_object());
    init_command("wear dress");
    
   weapon = clone_object("/wizards/walla/ravenloft/areas/eq/rod_part_5");
   move_object(weapon, this_object());
   init_command("wield rod");

}
