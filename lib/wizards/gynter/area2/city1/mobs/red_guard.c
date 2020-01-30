inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(35);
  set_name("guard");
  set_alias("red guard");
  set_short("A red guard");
  set_long("This is one of the kings personal guards. They are all dressed in red\n" +
           "to symbolise that they will give their blood for the king.\n");
  set_al(0);
  set_al_aggr(1000);
  set_aggressive(1);
  set_init_ob(this_object());

  weapon = clone_object("/wizards/gynter/area2/city1/eq/red_sword");
  move_object(weapon, this_object());
  init_command("wield sword");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/red_shield");
  move_object(weapon, this_object());
  init_command("lwield shield");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/red_leggings");
  move_object(weapon, this_object());
  init_command("wear leggings");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/red_helmet");
  move_object(weapon, this_object());
  init_command("wear helm");

  weapon = clone_object("/wizards/gynter/area2/city1/eq/red_armour");
  move_object(weapon, this_object());
  init_command("wear plate");
}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}
/*
catch_tell(str) {
  string tmp1, tmp2;
  object king, guard;
  object ob;
  ::catch_tell(str);
  if(sscanf(str, "%s attacks %s!", tmp1,tmp2) == 2) {
    this_object()->attack_object(this_player());
    return 1;
  }
}
*/