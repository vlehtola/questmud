inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(35);
  set_name("white paladin");
  set_alias("paladin");
  set_short("A white paladin");
  set_long("This is one of the best paladins there is. They always wear\n" +
           "white clothes to symbolise their purity.\n");
  set_al(100);
  set_al_aggr(100);
  set_aggressive(1);
  set_init_ob(this_object());

  armour = clone_object("/wizards/gynter/area2/city1/eq/white_sword");
  move_object(armour, this_object());
  init_command("wield sword");

  armour = clone_object("/wizards/gynter/area2/city1/eq/white_shield");
  move_object(armour, this_object());
  init_command("lwield shield");

  armour = clone_object("/wizards/gynter/area2/city1/eq/white_helmet");
  move_object(armour, this_object());
  init_command("wear helmet");
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
  if(slump == 2) set_block_dir("east");
  if(slump == 3) set_block_dir("west");
  set_block_message("None shall pass!\n");
}
