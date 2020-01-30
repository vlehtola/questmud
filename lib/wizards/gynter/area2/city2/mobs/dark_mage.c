inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(70);
  set_name("dark mage");
  set_alias("mage");
  set_short("Dark Mage");
  set_long("This is one of the sources of The GrandMage's power. He has captured\n" +
           "this being in this room and drain's it of it's powers. So it's mad.\n");
  set_al(-100);
  set_al_aggr(200);
  set_aggressive(0);
  set_log();

  set_spell_chance(100, "exs fla blt");
  set_skill("mana control", 100);
  set_skill("cast fire", 100);
  set_skill("cast essence", 100);
  set_skill("quick chant", 70);
  set_skill("cast bolt", 100);

  armour = clone_object("/wizards/gynter/area2/city2/eq/mage_robe");
  move_object(armour, this_object());
  init_command("wear robe");

  weapon = clone_object("/wizards/gynter/area2/city2/eq/orb_enlight");
  move_object(weapon, this_object());
  init_command("wear orb");
}
