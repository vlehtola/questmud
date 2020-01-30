inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(20);
  set_name("knight");
  set_short("A knight");
  set_long("This is one of the knights that guards the King's castle.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  armour = clone_object("/wizards/gynter/area2/city1/eq/sword");
  move_object(armour, this_object());
  init_command("wield sword");

  armour = clone_object("/wizards/gynter/area2/city1/eq/shield");
  move_object(armour, this_object());
  init_command("lwield shield");
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
