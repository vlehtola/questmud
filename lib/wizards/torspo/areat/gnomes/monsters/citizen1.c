inherit "obj/monster";

reset(arg) {
 object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2) + 11);
  set_race("gnome");
  set_name("citizen");
  set_gender(1);
  set_short("Gnome citizen");
  set_long("The plain looking gnome. He has gray, rough skin and red eyes. Underearth life\n"+
           "keeps him quite slender but still muscular and strong. He's wearing\n"+
           "some woollen clothes and bears a tattoo in his neck.\n");
  set_al(10);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/trousers01");
   move_object(armour, this_object());
   init_command("wear leggings");
}
