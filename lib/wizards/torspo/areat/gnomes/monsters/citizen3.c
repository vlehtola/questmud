inherit "obj/monster";

reset(arg) {
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5) + 20);
  set_race("gnome");
  set_name("kalle");
  set_alias("mayor");
  set_short("Kalle, the gnomish mayor");
  set_long("Kalle looks like a normal gnome, the only difference is his lordly clothes\n"+
           "and wicked face.\n");
  set_al(-5);
  set_al_aggr(200);
  set_max_hp(query_hp() + 150);
  set_hp(query_max_hp());

   weapon = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/hammer1");
   move_object(weapon, this_object());
   init_command("wield hammer");
}
