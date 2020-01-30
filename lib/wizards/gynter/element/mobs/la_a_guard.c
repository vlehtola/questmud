inherit "obj/monster";

reset(arg) {
  object weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("elemental");
  i = random(2);
  set_level(23+i*5);
  set_name("guard");
  set_alias("air");
  set_short("A large guard");
   set_long("This is the smartest of the air guards.\n"+
           "For limbs it has the gentle breeze of the southern winds, for head it has\n"+
           "the sharp wind of the northern mountains. And for a chest it has the\n"+
           "massive winds of the seven kingdoms.\n");
  set_al(10);
  set_aggressive(0);
  set_skill("shield parry", 30);
  set_skill("axes", 40);

  weapon = clone_object("/wizards/gynter/element/eq/vorp_axe");
  move_object(weapon, this_object());
  init_command("wield axe");

  weapon = clone_object("/wizards/gynter/element/eq/airial_shield");
  move_object(weapon, this_object());
  init_command("wield shield");
}
