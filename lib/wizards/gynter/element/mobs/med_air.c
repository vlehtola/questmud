inherit "obj/monster";

reset(arg) {
  object weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("ghost");
  i = random(2);
  set_level(28+i*5);
  set_name("scout");
  set_alias("scout");
  set_short("A medium sized scout");
  set_long("These are the scouts of the vast armies of the airial realms.\n" +
           "They are dumb and nearsighted but have an extraordinary hearing.\n");
  set_al(0);
  set_aggressive(0);

  weapon = clone_object("/wizards/gynter/element/eq/med_air_shield");
  move_object(weapon, this_object());
  init_command("wield shield");

  weapon = clone_object("/wizards/gynter/element/eq/vorp_blade");
  move_object(weapon, this_object());
  init_command("wield blade");
  set_special(35);  /* Enable special_move() */
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
 	tell_object(ob, "The scout knocks you to the ground with his shield!\n");
 	say("The scout knocks "+ob->query_name()+"to the ground with his shield!\n", ob);
 	ob->hit_with_spell(100, "physical");
}
