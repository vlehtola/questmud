inherit "obj/monster";

reset(arg) {
  object weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("elemental");
  i = random(4);
  set_level(30+i*5);
  set_name("guard");
  set_alias("air");
  set_short("A huge guard");
  set_long("This guard is the guardian of the west passage.\n" +
           "As you look into the eyes of this guard you see total\n" +
           "lack of intelligence. But what it misses in mind it gains in body.\n");
  set_al(0);
  set_aggressive(0);
  set_skill("shield block", 50);
  set_block_dir("southeast");

  weapon = clone_object("/wizards/gynter/element/eq/airial_shield");
  move_object(weapon, this_object());
  init_command("lwield shield");

  weapon = clone_object("/wizards/gynter/element/eq/vorp_bataxe");
  move_object(weapon, this_object());
  init_command("wield axe");
  set_special(25);  /* Enable special_move() */
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "The guard throws you to the ground and with a scream throws himself ontop!\n");
  say("The guard throws "+ob->query_name()+"  to the ground and with a scream throws himself ontop!\n", ob);
  ob->hit_with_spell(500, "physical");
}
