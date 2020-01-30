inherit "obj/monster";

reset(arg) {
 object armour;
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 15);
  set_race("gnome");
  set_name("gnome");
  set_alias("guard");
  set_gender(2);
  set_short("Gnome guard");
  set_long("The muscular gnome guards the mountain path. She seems to be expert in handling\n"+
           "weapons.\n");
  set_al(9);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/cloak01");
   move_object(armour, this_object());
   init_command("wear cloak");

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/axe01");
   move_object(armour, this_object());
   init_command("wield axe");
}
