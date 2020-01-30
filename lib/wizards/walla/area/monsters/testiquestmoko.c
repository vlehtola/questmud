inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 50);
    call_other(this_object(), "set_name", "alchemist");
    call_other(this_object(), "set_alias", "efraim");
    call_other(this_object(), "set_short", "Efraim En-Dor the alchemist");
    call_other(this_object(), "set_long", "Efraim stands here trying to find the way of making gold\n" +
                                          "of cheap and worthless metals, he has'nt succeeded, but rumours about.\n"+
                                          "Leb-Kamar having a special formula have been told to him.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Efraim says: Bring me the piece of metal that makes me gold.\n";
        chat_str[1] =
          "Efraim says: It is rumoured that Leb-Kamar has it.\n";
        chat_str[2] =
          "Efraim begs: Bring it please, or me whole life has failed.\n";
        chat_str[3]=
          "Efraim says: If you bring it to me I shall reward you somehow.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Efraim says: Noooooooooooooooo!.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
   armour = clone_object("/wizards/walla/area/weapons/axe");
    move_object(armour, this_object());
    init_command("wield axe");
 
    weapon = clone_object("/wizards/walla/area/armour/goggles");
    move_object(weapon, this_object());
    init_command("wear goggles");
}

catch_tell(str) {
  object ob;
  string tmp,tmp2;
  if(sscanf(str,"%s gives %s to "+cap_name+".",tmp,tmp2) == 2) {
    if(ob = present(tmp2,this_object())) {
      if(ob == find_object("/wizards/walla/eku")) {
        /* quest completed */
        return 1;
      } else {
        say(cap_name+" says: 'Thanks!'\n");
        return 1;
      }
    }
  }
}
