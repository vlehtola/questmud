inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(15);
  set_name("bear");
  set_alt_name("adult");
  set_alias("animal");
  set_short("An adult polar bear is looking after its offspring");
  set_long("Thick, white fur covers this adult polar bear. It seems obvious,\n" +
           "that the cold temperature does not bother it. The polar bear is\n" +
           "looking after its precious offspring. Seems that the creature is\n" +
           "capable of protecting its property with its big, sharp teeth and\n" +
           "strong-looking claws.\n" +
           "It is a polar bear.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Adult bear watches you reservedly.\n";
    chat_str[1] = "Adult bear growls at its offspring.\n";
    chat_str[2] = "Adult bear sits on the snow, but soon stands up again.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Adult bear roars at you in anger.\n";
    a_chat_str[1] = "Adult bear tries to bite your arm off, but you manage to dodge the attempt.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  set_resists("cold", 80);
}

catch_tell(str) {
  string plr;
  object ob;
  if(sscanf(str, "%s attacks", plr) == 1) {
    ob = find_player(lower_case(plr));
    if(!ob || query_attack()) return;
    say("The adult bear tries to protect its kin and attacks " + ob->query_name() + ".\n");
    attack_object(ob);
  }
}
