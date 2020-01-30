inherit "obj/monster";
int i;
reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+22);
  set_name("salesman");
  set_alt_name("man");
  set_alias("salesmani");
  set_race("orc");
  set_gender(1);
  set_short("An Orcish salesman is trying to sell a strange animal");
  set_long("A young salesman is standing on the square and selling some livestock.\n" + 
           "The man seems to be very glib when he advertises and praises his crappy\n" + 
           "merchandise. While shouting praises and prices of his merchandise, he\n" + 
           "also seems to observe carefully his surroundings for possible thieves\n" + 
           "and customers.\n");
  
  if(!i) { call_out("cloneanimal", 1); i = 1; }
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Salesman shouts: 'This animal is for sale only today!'\n";
    chat_str[1] = "Salesman shouts: 'Special discount for the quickest!'\n";
    chat_str[2] = "Salesman shouts: 'Great livestock for sale!'\n";
    chat_str[3] = "Salesman hits the ground with his wooden staff to gain attention.\n";
  }
  load_chat(7, chat_str);
  
  if(!present("staff", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/staff"), this_object()); init_command("wield staff"); }
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/salerobes"), this_object()); init_command("wear robes"); }
}

cloneanimal() {
  move_object(clone_object("/wizards/ahma/orc/mob/animal"), environment(this_object()));
}

  
