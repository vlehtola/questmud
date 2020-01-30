inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(70);
  set_name("ranger");
  set_alias("undead");
  set_short("A ranger");
  set_long("This is the first kings bodyguard. He followed the former king\n" +
           "everywhere, even to the death and beyond.\n");
  set_al(-100);
  set_al_aggr(200);
  set_aggressive(0);
  set_undead(1);
  set_log();

  set_skill_chance(80, "strike");
  set_skill("strike", 100);
  set_skill("cut", 100);

  armour = clone_object("/wizards/gynter/area2/city1/eq/bone_axe");
  move_object(armour, this_object());
  init_command("wield axe");

  armour = clone_object("/wizards/gynter/area2/city1/eq/bone_shield");
  move_object(armour, this_object());
  init_command("lwield shield");
}
