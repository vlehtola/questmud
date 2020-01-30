inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+28);
  set_name("hunter");
  set_alias("man");
  set_race("orc");
  set_gender(1);
  set_short("An alert-looking Orcish hunter");
  set_long("A dark green, short figure is standing still and observing the forest.\n" +
           "The Orc is quietly smoking his pipe, prepared to run for an animal if\n" +
           "one should show up. The man is wearing a furry vest and is wielding a\n" +
           "sharp knife to help him in battle against the animals.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Hunter observes his surroundings carefully.\n";
    chat_str[1] = "Hunter blows a small cloud of smoke out from his mouth.\n";
    chat_str[2] = "Hunter smokes his pipe.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 300);
  set_hp(query_max_hp());
  if(!present("vest", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/vest"), this_object()); init_command("wear vest"); }
  if(!present("knife", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/knife"), this_object()); init_command("wield knife"); }
  /* EI TOIMI PIPE
  if(!present("pipe", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/pipe"), this_object()); init_command("smile"); }
  if(!random(4)) { move_object(clone_object("/wizards/ahma/orc/eq/grass"), this_object()); init_command("load base with grass"); }
*/
}
