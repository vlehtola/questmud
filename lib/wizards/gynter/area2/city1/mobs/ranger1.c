inherit "obj/monster";

reset(arg) {
  string chat_str;
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(20);
  set_name("ranger");
  set_alias("green ranger");
  set_short("A green ranger");
  set_long("This is one of the rangers that occupy this city. They are dressed all in green\n" +
           "so that they may blend in better when they are in the forest.\n"+
           "Yet this one looks kind of sad.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  weapon = clone_object("/wizards/gynter/area2/city1/eq/ranger_axe");
  move_object(weapon, this_object());
  init_command("wield axe");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/ranger_cloak");
  move_object(weapon, this_object());
  init_command("wear cloak");

  if (!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "The ranger says: If I could only get my key.\n";
    chat_str[1] = "The ranger says: I lost it when I had to leave my shop.\n";
  }
  load_chat(60, chat_str);
}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}

init() {
  int slump;
  ::init();
  slump = random(4);
  if(slump == 0) set_block_dir("north");
  if(slump == 1) set_block_dir("south");
  if(slump == 2) set_block_dir("west");
  if(slump == 3) set_block_dir("east");
  set_block_message("None shall pass!\n");
}

catch_tell(str) {
  string tmp1, tmp2;
  ::catch_tell(str);
  if (sscanf(str, "%s gives key %s.", tmp1, tmp2) == 2) {
    if (present("key", this_object()) && (!this_player()->query_quests("Strakhand Breaking Bread")) && (this_player()->query_name() == tmp1)) {
      write("As you give the key to the ranger his face breaks up into\n");
      write("a smile because he has found happines.\n");
      this_player()->set_quest("Strakhand, Give Key to Baker");
    }
  }
}
