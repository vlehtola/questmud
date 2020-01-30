inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+35);
  set_name("giant leech");
  set_alias("animal");
  set_alt_name("leech");
  set_short("A black giant leech");
  set_long("A huge, almost 8-feet-long leech is crawling in the bottom of the tunnel.\n" + 
           "Leech's skin is shiny from all the slime on it, the actual skin colour\n" + 
           "seems to be black. The leech makes creepy splattering sound when it moves.\n" + 
           "No eyes can be seen on the animal, but you are sure it is aware of your\n" +
           "presence.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Leech wriggles in the dirty water.\n";
    chat_str[1] = "Leech splashes water on you.\n";
    chat_str[2] = "Leech tries to climb the tunnel wall, but falls into the water.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 2000);
  set_hp(query_max_hp());
  set_str(query_str() + 60);
  set_animal();
  set_al(-30);
}