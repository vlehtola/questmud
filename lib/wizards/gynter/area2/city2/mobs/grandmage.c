inherit "obj/monster";

reset(arg) {
  string chat_str;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(40);
  set_name("grand mage");
  set_alias("mage");
  set_short("The Grandmage");
  set_long("This is the Grand Mage. He has long white hair and his eyes\n" +
           "litteraly shines of intelligence.\n");
  set_al(0);
  set_al_aggr(100);
  set_aggressive(1);
  set_init_ob(this_object());

  if (!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "The Mage says: I order you to find and kill my ENEMY!\n";
    chat_str[1] = "The Mage says: That king is a thorn in my foot.\nAnd I wan't that thorn to be removed!\n";
    chat_str[2] = "The Mage says: Bring me his crown as evidence that he is eliminated!\n";
  }
  load_chat(60, chat_str);

  set_spell_chance(85, "exs sol arr");
  set_skill("mana control", 100);
  set_skill("cast essence", 100);
  set_skill("cast earth", 100);
  set_skill("quick chant", 50);
  set_skill("cast arrow", 100);

  armour = clone_object("/wizards/gynter/area2/city2/eq/amulet");
  move_object(armour, this_object());
  init_command("wear amulet");
}

monster_init() {
  if(!this_player()->query_quests("Strakhand, Kill the mage")) { return 1; }
}
/* Looking for quest */
catch_tell(str) {
  string tmp1, tmp2;
  ::catch_tell(str);
  if(!this_player()->query_quests("Strakhand, Kill the mage")) {
    if (sscanf(str, "%s gives crown %s.", tmp1, tmp2) == 2) {
      if (present("crown", this_object()) && this_player()->query_name() == tmp1) {
        if(!this_player()->query_quests("Therheran, Killed King Unproven")) {
          write("You have FOOLED ME! You have not killed the king!");
          this_object()->attack_object(this_player());
          return;
        }
        write("When you give the crown to the mage he starts cackling with an insane glee\n");
        write("and as he stops laughing he looks at you and says:\n");
        write("Well. You most certainly has proven yourself worthy to see my secret.\n");
        if(!this_player()->query_quests("Therheran, Killed king")) {
          this_player()->set_quest("Therheran, Killed king");
          move_object(this_player(), "/wizards/gynter/area2/city2/templea");
          return 1;
        }
      }
    }
  }
}

/* When mob dies */
monster_died() {
  this_player()->set_quest("Strakhand Kill Mage Unproven");
}