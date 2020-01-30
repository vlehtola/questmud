inherit "obj/monster";

reset(arg) {
 object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2) + 7);
  set_name("gnome");
  set_alias("child");
  set_race("gnome");
  set_gender(1);
  set_short("Gnomish child");
  set_long("The small child of the gnomes seems to be as tough as its elders. This hard\n"+
           "environment must make the children grow strong and resistant.\n");
  set_al(11);
  set_al_aggr(200);
  set_max_hp(query_hp()+50);
  set_hp(query_max_hp());
   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/tunika01");
   move_object(armour, this_object());
   init_command("wear tunika");
}
