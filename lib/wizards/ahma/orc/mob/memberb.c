inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 10);
  set_name("figure");
  set_short("A black-robed figure");
  set_gender(1);
  set_race("orc");
  set_long("A black-robed figure stands in the middle of a large room, near the wooden\n" + 
           "table. The creature in the robes cannot be seen, but from the voice with\n" + 
           "which he is chanting can be concluded that he is a male. A sharp blade of\n" + 
           "a dagger shimmers from one sleeve of the black robe.\n");

  set_max_hp(query_hp() + 1000);
  set_hp(query_max_hp());
  set_aggressive(1);
  set_block_dir("stairs");
  set_al(-20);
  if(!present("hood", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/blackhood"), this_object()); init_command("wear hood"); }
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/blackrobes"), this_object()); init_command("wear robes"); }
  if(!present("knife", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/knife"), this_object()); init_command("wield knife"); }
}