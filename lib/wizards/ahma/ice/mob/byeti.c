inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(10 + random(3));
  set_name("baby yeti");
  set_alias("yeti");
  set_alt_name("baby");
  set_race("yeti");
  set_short("A small furry yeti is stumbling around");
  set_long("Almost looking like a big hairball, this small creature has a thick\n" +
           "gray hair. This yeti seems to be just a child, or maybe, just a baby.\n" +
           "Seems that it has some problems even with walking. Who knows, it\n" + 
           "might just have learned how to use its feet for walking.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Small yeti giggles childishly.\n";
    chat_str[1] = "Small yeti stumbles around the room.\n";
    chat_str[2] = "Small yeti stares at you with its innocent black eyes.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Small yeti tries to flee, but stumbles and falls down.\n";
    a_chat_str[1] = "Small yeti sobs helplessly.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_resists("cold", 55);
}