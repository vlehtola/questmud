inherit "obj/monster";
int i = random(3), h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+15);
  set_name("animal");
  if(i==0) { set_short("A weak-looking animal is standing here"); }
  if(i==1) { set_short("A starving animal is standing here"); }
  if(i==2) { set_short("A spotted ugly animal is standing here"); }
  set_long("A strange-looking animal is standing on the village square. It is\n" + 
           "covered with long, light brown fur which prevents from seeing what\n" + 
           "animal it actually is. Though the fur covers the animal thoroughly,\n" + 
           "its behaviour indicates that it has been treated badly and kept in\n" + 
           "hunger.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Animal lets out some coughing voices.\n";
    chat_str[1] = "Animal shakes its head wildly.\n";
    chat_str[2] = "Animal looks beggingly at you.\n";
  }
  load_chat(3, chat_str);


  set_animal();
  set_special(99);
  set_al(10);
}

special_move() {
  if(h) { return; } {
  object ob;
  ob = query_attack();
  if(present("salesmani", environment(this_object()))) {
    tell_room(environment(this_object()), "Salesman shouts: 'Get your hands off of my animal you dirty swine!'\n");
    present("salesmani", environment(this_object()))->attack_object(ob);
    h = 1;
  }
  }
}
