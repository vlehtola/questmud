inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(8 + random(2));
  set_name("tellu");
  set_alias("dog");
  set_animal(1);
  set_short("Tellu the dog");
  set_long("Tellu is very small and cute. It is white coloured and quite rumpled. The dog\n"+
           "is happy, as young cubs always are, and looks playful.\n"+
           "It is a bichon frise.\n");

  set_al(50);
  set_al_aggr(200);

   chat_str = allocate(4);
   chat_str[0] = "Tellu lets out some joyful barks.\n";
   chat_str[1] = "Tellu runs some circles around you.\n";
   chat_str[2] = "Tellu shows its sharp teeth to you.\n";
   load_chat(15, chat_str);
}
