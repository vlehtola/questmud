inherit "obj/monster";

reset(arg) {
 object armour;
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 14);
  set_race("gnome");
  set_name("gnome");
  set_alias("guard");
  set_gender(2);
  set_short("Gnome guard");
  set_long("The muscular gnome guards the entrance to the gnome city. She looks alert\n"+
           "of evil monsters which walk around the mountains.\n");
  set_al(9);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/cloak01");
   move_object(armour, this_object());
   init_command("wear cloak");

   weapon = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/axe01");
   move_object(weapon, this_object());
   init_command("wield axe");
}
