inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(70);
  set_name("dark cleric");
  set_alias("cleric");
  set_short("Dark Cleric");
  set_long("This is one of the sources of The GrandMage's power. The GrandMage has captured\n" +
           "this being in this room and is draining it's powers.\n");
  set_al(-100);
  set_al_aggr(200);
  set_aggressive(0);
  set_log();

  set_spell_chance(100, "exs mjr hrm");
  set_skill("mana control", 100);
  set_skill("chanting", 100);
  set_skill("cast essence", 100);
  set_skill("quick chant", 70);
  set_skill("cast major", 100);
  set_skill("cast harm", 100);

  armour = clone_object("/wizards/gynter/area2/city2/eq/cleric_robe");
  move_object(armour, this_object());
  init_command("wear robe");

  weapon = clone_object("/wizards/gynter/area2/city2/eq/wand_life");
  move_object(weapon, this_object());
  init_command("wear wand");
}
