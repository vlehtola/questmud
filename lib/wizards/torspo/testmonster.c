inherit "obj/monster";

reset(arg) {
 object weapon;
  ::reset(arg);   
  if(arg) { return; }
  set_level(1);
  set_name("monster");
  set_alias("testmonster");
  set_race("Demon");
  set_short("Testmonster(99)");
  set_long("Ok.\n");
  set_max_hp(1000000);
  set_hp(1000000);
  set_al(0);
  set_skill("strike", 100);
  set_skill_chance("strike", 100);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/axe01.c");
   move_object(weapon, this_object());
   init_command("wield axe");
}
