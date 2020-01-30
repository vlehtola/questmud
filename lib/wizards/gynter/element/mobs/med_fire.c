inherit "obj/monster";

reset(arg) {
  object armour,weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("demon");
  i = random(2);
  set_level(9+i*5);
  set_name("demon");
  set_alias("demon");
  set_short("A medium fire demon");
  set_long("This is the scouts of the generals. They have extremely keen sences and\n"+
           "acute hearing. They are realitively small demons but that is not dependant on strength.\n");
  set_al(1);
  set_aggressive(0);

  weapon = clone_object("/wizards/gynter/element/eq/smf_blade");
  move_object(weapon, this_object());
  init_command("wield blade");
}
