inherit "obj/monster";

reset(arg) {
  object weapon,armour;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(20);
  set_name("ranger");
  set_alias("green ranger");
  set_short("A green ranger");
  set_long("This is one of the rangers that occupy this city. They are dressed all in green\n" +
           "so that they may blend in better when they are in the forest.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  weapon = clone_object("/wizards/gynter/area2/city1/eq/ranger_axe");
  move_object(weapon, this_object());
  init_command("wield axe");

  armour = clone_object("/wizards/gynter/area2/city1/eq/ranger_cloak");
  move_object(armour, this_object());
  init_command("wear cloak");
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
