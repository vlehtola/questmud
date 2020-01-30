inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 40);
  set_name("elemental");
  set_race("elemental");
  set_short("A man-sized earth elemental");
  set_long("Almost six feet tall earth elemental is standing still in the middle\n" + 
           "of the room. Its muscular arms are folded in front of its chest. The\n" + 
           "elemental is looking at the ceiling, like there would be something\n" + 
           "interesting in there. Earth elemental is breathing with deeps sighs.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Elemental sighs deeply.\n";
    chat_str[1] = "Elemental blinks its eyes dreamingly.\n";
    chat_str[2] = "Elemental draws some pictures on the ground with its foot, but covers them quickly.\n";
  }
  load_chat(3, chat_str);
  
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_str(query_str() + 80);
  set_skill("kick", 100);
  set_skill_chance("kick", 90);
  set_skill("critical", 70);
  set_skill("enhance criticals", 30);
  set_skill("find weakness", 50);
  set_resists("electric", 100);
  set_al(-10);
}
