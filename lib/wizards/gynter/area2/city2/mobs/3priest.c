inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(30);
  set_name("priest");
  set_short("A third circle priest");
  set_long("This is one of the priests that occupy this city. They are only dressed\n" +
           "in the cloak assigned to them by the Grand Mage.\n"+
           "This mage is not long before he will have the right to stand beside the Grand Mage\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());
  set_spell_chance(70, "exs sol arr");
  set_skill("cast essence", 100);
  set_skill("cast earth", 100);
  set_skill("cast arrow", 100);
  set_skill("mana control", 100);

  weapon = clone_object("/wizards/gynter/area2/city2/eq/3priest_cloak");
  move_object(weapon, this_object());
  init_command("wear cloak");
}

monster_init() {
  if(!this_player()->query_quests("Strakhand, Kill the mage")) { return 1; }
}
