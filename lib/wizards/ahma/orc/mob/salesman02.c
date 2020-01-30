inherit "obj/monster";
int i = random(4);

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+24);
  set_name("salesman");
  set_alt_name("man");
  set_race("orc");
  set_gender(1);
  if(i==0) { set_short("A bearded salesman is selling some beauty equipment"); }
  if(i==1) { set_short("A sturdy salesman is selling hunting equipment"); }
  if(i==2) { set_short("An elderly salesman is selling self-made chairs and tables"); }
  if(i==3) { set_short("An odd-looking salesman is selling jewelry"); }
  set_long("An Orcish salesman is selling various stuff here. Salesman is shouting\n" + 
           "prices and discounts to the crowd walking around the village square.\n" + 
           "Salesman looks quite fed up with the work he is doing, but still keeps\n" + 
           "shouting prices after prices. Salesman seems to be prepared for thieves\n" + 
           "and other trouble-makers.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Salesman shouts: 'The cheapest prices in this realm are found here!'\n";
    chat_str[1] = "Salesman shouts: 'The best discoveries can be made right here!'\n";
    chat_str[2] = "Salesman smiles politely at you.\n";
    chat_str[3] = "Salesman hits the ground with his wooden staff to gain attention.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 200);
  set_hp(query_max_hp());

  if(!present("staff", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/staff"), this_object()); init_command("wield staff"); }
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/salerobes"), this_object()); init_command("wear robes"); }
}

  