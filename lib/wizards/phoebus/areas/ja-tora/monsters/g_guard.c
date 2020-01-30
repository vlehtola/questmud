inherit "obj/monster";

reset(arg) {
  object armour;
  object weapon;
  string chat_str;  
  ::reset(arg);

    set_name("Gnome guard");
    set_level(10);
    set_al(60);
    set_alias("gnome");
    set_alt_name("guard");
    set_race("gnome");

      set_short("Gnome guard");
      set_long("This Gnome Guard stands tall, well as tall as he can. He protects the  \n"+
                      "entrance to the village of Ja-Tora and looks like he can take care of \n"+
                      "himself. So don't give him any trouble.\n");
  
  armour = clone_object("/wizards/phoebus/areas/ja-tora/eq/l_tunic");
  move_object(armour, this_object());
  init_command("wear tunic");

  weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/s_sword");
  move_object(weapon, this_object());
  init_command("wield sword");

    if(!chat_str)  {
        chat_str = allocate(3);
        chat_str[0] = "Guard says: Welcome to Ja-Tora, enjoy your stay.\n";
        chat_str[1] = "Guard says: See our leader, he has a favour to ask.\n";
        chat_str[2] = "Guard says: I don't like trolls, there smelly big lumps.\n";
   }
  load_chat(2, chat_str);
}
