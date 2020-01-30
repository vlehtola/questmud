inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(40);
  set_name("gate guard");
  set_alias("guard");
  set_short("A gate guard");
  set_long("This is one of the guards that see to that no unathorized people\n" +
           "enters the city.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  weapon = clone_object("/wizards/gynter/area2/city1/eq/sword");
  move_object(weapon, this_object());
  init_command("wield sword");
}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}
