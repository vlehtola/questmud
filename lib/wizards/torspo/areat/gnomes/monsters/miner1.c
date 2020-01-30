inherit "obj/monster";

reset(arg) {
 object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2) + 14);
  set_race("gnome");
  set_name("gnome");
  set_alias("miner");
  set_gender(1);
  set_short("Dusty gnomish miner");
  set_long("The gnome is covered with dust. He is clad in dirty and ragged clothes and\n"+
           "looks very sturdy. His eyes glitter in the darkness of the tunnel. He has fuzzy\n"+
           "sideburns and moustache. He seems to be expert in using his mining tools.\n");
  set_al(9);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   weapon = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/pick1");
   move_object(weapon, this_object());
   init_command("wield maul");
}
