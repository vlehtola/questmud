inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(17);
  set_race("hobbit");
  set_name("guard");
  set_alias("bodyguard");
  set_short("Royal bodyguard of the old hobbit king <defender>");
  set_long("The royal bodyguard is best of the best, only the best become choosen to\n"+
           "defend the king. He has proven his loyalty to the dynasty of the hobbits,\n"+
           "serving the royal generation for ages. Even his father served in the royal\n"+
           "bodyguard forces.\n");
  set_al(-5);
  set_block_dir("north");
  set_gender(1);

    weapon = clone_object("/wizards/irmeli/area2/equ/shield.c");
    move_object(weapon, this_object());
    init_command("wield shield");

}
