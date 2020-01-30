inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 33);
    call_other(this_object(), "set_name", "john");
    call_other(this_object(), "set_alias", "pirate");
    call_other(this_object(), "set_short", "John Short Gold, the barman at Pepe's Eye Point's bar");
    call_other(this_object(), "set_long", "John is a very big man eventhough his name might indicate something else.\n"+
                                         "He has a large moustache and a red and white striped shirt which is covered with holes.\n" +
                                         "Under theses holes are marks of puncture and of fighting. You might not want to get\n" +
                                         "thrown out by him.\n");
  call_other(this_object(), "set_al", 3);                   
  call_other(this_object(), "set_aggressive", 0);
  call_other(this_object(), "set_block_dir","curtain");
  if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "John says: We have the best ale fer many hundred miles heir.\n";
        chat_str[1] =
          "John says: We have the best ale fer many hundred miles heir.\n";
        chat_str[2] =
          "John says: We have the best ale fer many hundred miles heir.\n";
        chat_str[3]=
          "John says: We have the best ale fer many hundred miles heir.\n";
        chat_str[4]=
         "John says: We have the best ale fer many hundred miles heir.\n";
 
  }
 if (!a_chat_str) {                   
   a_chat_str = allocate(1);
   a_chat_str[0] = "John says: I'll kick yer bloody arse to hell.\n";
   }
    load_chat(5, chat_str);
    load_a_chat(21, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/peepseye/eq/armour/barshirt");
    move_object(armour, this_object());
    init_command("wear shirt");
 
    weapon = clone_object("/wizards/walla/peepseye/eq/weapons/ironfist");   
    move_object(weapon, this_object());
    init_command("wield fist");
}
 
