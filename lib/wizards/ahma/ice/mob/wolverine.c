inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(12);
  set_name("wolverine");
  set_alias("animal");
  set_short("A furry wolverine is digging the ground in here");
  set_long("The hunchbacked creature is shivering still on the snowy ground. It is\n" +
           "certain that the wolverine is not feeling cold under its thick fur.\n" +
           "Maybe it is angry about something. Wolverine's black eyes stare at you\n" +
           "alertly. Something red has stained the surroundings of wolverine's mouth,\n" +
           "which seems to be full of small, sharp teeth.\n" +
           "It is a wolverine.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Wolverine shivers on the ground.\n";
    chat_str[1] = "Wolverine shows you its bloody teeth and hisses loudly.\n";
    chat_str[2] = "Wolverine raises a cloud of snow on the air as it moves.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Wolverine lets out some growling sounds.\n";
    a_chat_str[1] = "Wolverine barely scratches you with its sharp claws.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  set_resists("cold", 70);
}

specname() {
  set_name("trunz");
  set_alt_name("wolverine");
  set_alias("animal");
  set_short("Trunz, Harald's pet wolverine");
  set_long("The hunchbacked creature is shivering still on the snowy ground. It is\n" +
           "certain that the wolverine is not feeling cold under its thick fur.\n" +
           "Maybe it is angry about something. Wolverine's black eyes stare at you\n" +
           "alertly. Something red has stained the surroundings of wolverine's mouth,\n" +
           "which seems to be full of small, sharp teeth.\n" +
           "It is a wolverine.\n");

  if(!present("tail")) move_object(clone_object("/wizards/ahma/ice/eq/tail"), this_object());
}
