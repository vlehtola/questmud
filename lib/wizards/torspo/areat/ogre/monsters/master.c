inherit "obj/monster";

reset(arg) {
  object weapon;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5)+60);
  set_skill("strike", 90);
  set_skill_chance("strike", 60);
  set_race("ogre");
  set_name("master");
  set_alias("master");
  set_short("Ogre training master");
  set_long("Scarred muscular ogre training master. He has served this outpost for years,\n"+
           "teaching young ogres the fighting techniques and skills.\n");
  set_al(-25);
  set_gender(1);
  set_log();
  set_str(query_str() + 50);
  set_dex(query_dex() + 25);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/axe01.c");
   move_object(weapon, this_object());
   init_command("wield axe");

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/ring01.c");
   move_object(armour, this_object());
   init_command("wear ring");
}
