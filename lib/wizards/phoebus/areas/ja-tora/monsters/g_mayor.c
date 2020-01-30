inherit "obj/monster";

reset(arg) {
  object armour;
  object weapon;
  string chat_str;  
  ::reset(arg);

    set_name("Gnome mayor");
    set_level(15);
    set_al(60);
    set_alias("gnome");
    set_alt_name("mayor");
    set_race("gnome");

      set_short("Gnome mayor");
      set_long("This Gnome is sitting reading something, but you can make it out.\n"+
                      "As you enter his home he stands to welcome you. He looks very \n"+
                     "upset.\n");
   
    set_spell_chance(25, "exs fla grs");
    set_skill("cast essence", 30);
    set_skill("cast fire", 30);
    set_skill("cast grasp", 30);
    set_skill("mana control", 25);

  armour = clone_object("/wizards/phoebus/areas/ja-tora/eq/l_tunic");
  move_object(armour, this_object());
  init_command("wear tunic");

  weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/g_staff");
  move_object(weapon, this_object());
  init_command("wield sword");

    if(!chat_str)  {
        chat_str = allocate(1);
        chat_str[0] = "Major says: Welcome  .\n"+
                                                  "Our town is in grave danger from evil trolls. \n"+
                                                  "Years ago we came to this area and built our \n"+
                                                  "little town beside the mountains. But then a \n"+
                                                  "group of evil trolls appeared in the caverns \n"+
                                                  "to the east. They keep killing our villagers. \n"+
                                                  "Please if you can help you must kill there king. \n"+
                                                  "If you can return with his hidious head i will \n"+
                                                  "reward your efforts...\n";        
   }
  load_chat(8, chat_str);
}
