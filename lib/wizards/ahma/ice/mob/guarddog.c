inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(15);
  set_name("dog");
  set_alt_name("husky");
  set_alias("animal");
  set_short("A growling guard dog, chained to an igloo");
  set_long("You are relieved to see that this extremely angry-looking creature\n" +
           "has been chained to an igloo. It is wearing a collar around its neck,\n" +
           "and to the collar has been attached a metallic chain, preventing\n" +
           "the dog from reaching you. The dog is quite big and, probably, also\n" +
           "strong.\n" +
           "It is a husky.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Guard dog growls angrily at you.\n";
    chat_str[1] = "Guard dog tries to attack you but its chain prevents it.\n";
    chat_str[2] = "Guard dog walks back and forth near the igloo entrance.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Guard dog tries to sink its teeth into your leg, but you manage to dodge the attempt.\n";
    a_chat_str[1] = "Guard dog eyes you with frenzied eyes.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  if(!present("collar", this_object())) {
    move_object(clone_object("/wizards/ahma/ice/eq/collar"), this_object());
    init_command("wear collar");
  }
  set_resists("cold", 60);
}