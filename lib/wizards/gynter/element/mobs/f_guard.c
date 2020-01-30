inherit "obj/monster";

reset(arg) {
  int i;
  object weapon;
  ::reset(arg);
  if(arg) { return; }
set_race("demon");
  i = random(3);
  set_level(35+i*6);
  set_name("guard");
  set_alias("demon");
  set_short("A huge fire guard");
  set_long("These are the great ones assassins, but worth to remember is that.\n" +
           "the fire assassins does not kill their target's through stealth but\n" +
           "through pure brutal force.\n");
  set_al(10);
  set_aggressive(0);
  set_skill("shield block", 50);
  set_skill("kick", 50);
  set_block_dir("northwest");

  weapon = clone_object("/wizards/gynter/element/eq/f_blade");
  move_object(weapon, this_object());
  init_command("wield blade");

  weapon = clone_object("/wizards/gynter/element/eq/f_shield");
  move_object(weapon, this_object());
  init_command("lwield shield");
}
