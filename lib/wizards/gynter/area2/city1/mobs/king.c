inherit "obj/monster";

reset(arg) {
  string chat_str;
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(40);
  set_name("king");
  set_short("The King");
  set_long("This is the king. He is an old man and he seems like if he has lost his\n" +
           "will to live. The only thing that keeps him going is his hatred\n"+
           "against the magelord of the village of Therheran.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  set_spell_chance(80, "exs fla arr");
  set_skill("mana control", 100);
  set_skill("cast essence", 100);
  set_skill("cast fire", 100);
  set_skill("cast arrow", 100);
  set_skill("find weakness", 100);

  if (!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "The King says: If someone could kill that mage!\n";
    chat_str[1] = "The King says: I would reward the person greatly.\n";
    chat_str[2] = "The King says: That mage and his village is a menace.\n   They are destroying us!\n";
    chat_str[3] = "The King says: Bring me his holy amulet!\n";
  }

  load_chat(60, chat_str);

  armour = clone_object("/wizards/gynter/area2/city1/eq/crown");
  move_object(armour, this_object());
  init_command("wear crown");

  armour = clone_object("/wizards/gynter/area2/city1/eq/emerald_sword");
  move_object(armour, this_object());
  init_command("wield sword");

  armour = clone_object("/wizards/gynter/area2/city1/eq/emerald_shield");
  move_object(armour, this_object());
  init_command("lwield shield");

}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}

catch_tell(str) {
  string tmp1, tmp2;
  ::catch_tell(str);
  if(!this_player()->query_quests("Therheran, Killed king")) {
    if (sscanf(str, "%s gives amulet %s.", tmp1, tmp2) == 2) {
      if (present("amulet", this_object()) && this_player()->query_name() == tmp1) {
        if(!this_player()->query_quests("Strakhand Kill Mage Unproven")) {
          write("You have FOOLED ME! You have not killed the mage!");
          this_object()->attack_object(this_player());
          return;
        }
        write("When you give the amulet to the king you see for the first time\n");
        write("some joy in his face. It looks like his face is bathing in sunshine\n");
        write("when he says: You did well, now the entrance is open for you!\n");
        this_player()->set_quest("Strakhand, Kill the mage");
        return 1;
        }
      }
    }
  }
}

/* When mob dies */
monster_died() {
  this_player()->set_quest("Therheran, Killed King Unproven");
}