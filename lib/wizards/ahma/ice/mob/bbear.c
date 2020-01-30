inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(11);
  set_name("bear");
  set_alt_name("baby");
  set_alias("animal");
  set_short("A baby polar bear is playing around in here");
  set_long("Ignoring the surrounding coldness, this small playful creature is\n" +
           "having a good time in here. Thick, white fur covers this baby bear\n" +
           "thoroughly, efficiently protecting it from cold. Polar bear cannot\n" +
           "be more than few months old, but its sharp teeth have already popped\n" +
           "up from its pink gums.\n" +
           "It is a polar bear.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Baby bear rolls in the snow playfully.\n";
    chat_str[1] = "Baby bear runs happily around the room.\n";
    chat_str[2] = "Baby bear growls at you happily.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Baby bear whines painfully.\n";
    a_chat_str[1] = "Baby bear looks at you with its freightened eyes.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  set_resists("cold", 60);
}