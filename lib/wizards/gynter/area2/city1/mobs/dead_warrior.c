inherit "obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(70);
  set_name("warrior");
  set_alias("undead");
  set_short("A warrior");
  set_long("This is the first king of Strakhad, and he will guard his grave\n" +
           "against anyone who want's to invade it.\n");
  set_al(-100);
  set_al_aggr(200);
  set_aggressive(0);
  set_log();
  set_undead(1);

  set_skill_chance(80, "kick");
  set_skill("kick", 100);
  set_skill("stun", 70);
  set_skill("dodge", 80);
  set_skill("find weakness", 92);
  set_skill("slash", 100);

  armour = clone_object("/wizards/gynter/area2/city1/eq/bone_sword");
  move_object(armour, this_object());
  init_command("wield sword");
}
