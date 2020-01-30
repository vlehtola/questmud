inherit "obj/monster";

reset(arg) {
 object armour;
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 12);
  set_race("gnome");
  set_name("gnome");
  set_alias("ranger");
  set_gender(1);
  set_short("Gnome ranger");
  set_long("The green clothed muscular gnome stands here. He looks alert. The scars in\n"+
           "his face tell that he's experienced in fighting.\n");
  set_al(5);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/cloak01");
   move_object(armour, this_object());
   init_command("wear cloak");

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/sword01");
   move_object(armour, this_object());
   init_command("wield sword");
}
