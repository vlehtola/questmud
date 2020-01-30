inherit "obj/monster";

reset(arg) {
  object armour,weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("elemental");
  i = random(2);
  set_level(30+i*5);
  set_name("guard");
  set_alias("air");
  set_short("A medium sized guard");
  set_long("These are the guard trainees. They get all the dangerous jobs,\n" +
           "like being the guards in front. But as you look into the guards eyes\n" +
"you see something strange.\n");
  set_al(0);
  set_aggressive(0);
  set_skill("axes", 50);

  weapon = clone_object("/wizards/gynter/element/eq/vorp_axe");
  move_object(weapon, this_object());
  init_command("wield axe");

  weapon = clone_object("/wizards/gynter/element/eq/med_air_shield");
  move_object(weapon, this_object());
  init_command("wield shield");
}
