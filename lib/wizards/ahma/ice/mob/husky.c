inherit "obj/monster";
int i = random(5) + 1;
string colour;

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(9 + (i/2));
  set_name("husky");
  set_alt_name("dog");
  set_alias("animal");
  if(i == 1) colour = "gray";
  if(i == 2) colour = "brown";
  if(i == 3) colour = "silver";
  if(i == 4) colour = "black";
  if(i == 5 || i == 6) colour = "golden";
  set_short("A wandering " + colour + " husky");
  set_long("This hairy dog is wandering around in the tunnels. The dog does not\n" +
           "seem to be bothered by the cold temperature, its thick hair and skin\n" +
           "give it a good natural resistance against cold. The dog looks bigger\n" +
           "than the normal dogs, but it must be caused by the thick hair.\n" +
           "It is a husky.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Husky sniffs the snowy ground.\n";
    chat_str[1] = "Husky waves its hairy tail in the air.\n";
    chat_str[2] = "Husky glares at you, but soon lowers its head.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Husky slashes you with its tail, what a powerless attack.\n";
    a_chat_str[1] = "Husky sinks its rear legs into the snow and gets ready to make an attack.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  if(!present("collar", this_object())) {
    if(!random(3)) {
      move_object(clone_object("/wizards/ahma/ice/eq/collar"), this_object());
      init_command("wear collar");
    }
  }
  set_resists("cold", 45);
}

golden() {
  i = 6;
}
