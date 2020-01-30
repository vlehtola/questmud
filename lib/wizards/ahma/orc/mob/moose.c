inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+27);
  set_name("moose");
  set_alias("animal");
  set_short("A great brown moose");
  set_long("This big animal is standing by the bushes and looking at the leaves. The\n" + 
           "moose is almost as big as a horse and its big horns, which divide in many\n" + 
           "directions, make it look even bigger. Moose's hair is brown in colour and\n" + 
           "quite short. Long sighs can be heard as the moose breathes with its muzzle.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Moose stomps the ground with its hoof.\n";
    chat_str[1] = "Moose shakes its head, slashing the air with its horns.\n";
    chat_str[2] = "Moose eats some leaves.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 400);
  set_hp(query_max_hp());
  set_str(query_str() + 25);
  set_animal();
}
