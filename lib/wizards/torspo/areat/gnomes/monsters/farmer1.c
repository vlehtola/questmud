inherit "obj/monster";

reset(arg) {
 object armour;
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 11);
  set_race("gnome");
  set_name("gnome");
  set_alias("farmer");
  set_gender(1);
  set_short("Gnome farmer");
  set_long("The small, strong looking gnome farmer is whining something about the\n"+
           "crop here. His dirty, used clothes and rough skin show the truth of his hard\n"+
           "work.\n");
  set_al(8);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/trousers01");
   move_object(armour, this_object());
   init_command("wear leggings");

   weapon = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/knife01");
   move_object(weapon, this_object());
   init_command("wield dagger");
}
