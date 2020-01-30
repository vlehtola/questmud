inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(30);
  set_name("paladin");
  set_short("A paladin");
  set_long("This is one of the paladins that guards the outer\n" +
           "perimeters of the King's castle.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());
  set_block_dir("enter");

  armour = clone_object("/wizards/gynter/area2/city1/eq/sword");
  move_object(armour, this_object());
  init_command("wield sword");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/shield");
  move_object(weapon, this_object());
  init_command("lwield shield");
}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}
