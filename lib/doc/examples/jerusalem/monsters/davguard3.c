inherit "obj/monster";
object weapon;

reset(arg) {
    ::reset(arg);
  if(arg) return;
  set_name("guard");
  set_level(36);
  set_race("human");
  set_aggressive(1);
  set_gender(1);
  set_block_dir("east");
  set_block_message("The guard roars 'This is the end of the road, you insolent bastard!'");
  set_alias("Guard");
  set_short("A big guard, blocking your way east");
  set_long("A big guard, who seems to be the master of the\n"+
  "Tower's personal bodyguard.\n");
  weapon = clone_object("/wizards/nalle/jerusalem/eq/longsword");
  move_object(weapon, this_object());
  init_command("wield sword");
}

