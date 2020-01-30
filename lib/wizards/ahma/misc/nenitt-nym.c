inherit "obj/monster";
object ob;
int location = 0;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) return;
  set_level(40);
  set_name("nenitt-nym");
  set_alias("informer");
  set_race("human");
  set_gender(1);
  set_short("Nenitt-Nym, the informer of upcoming events");
  set_long("Nenitt-Nym is a wandering informer who now and then travels through the\n" +
           "realm, sharing the bits and pieces of his endless wisdom and knowledge.\n" +
           "Nenitt-Nym has arrived in Duranghom definitely for some particular\n" +
           "reason, this seems to be a priceless opportunity for everyone nearby to\n" +
           "civilize themselves with this man's information. Nenitt-Nym seems to be\n" +
           "carrying some kind of leather bag full of somewhat wrinkled brochures.\n" +
           "Maybe you could 'get brochure' from him.\n");
  
  
    if(!chat_str) {
    chat_str = allocate(10);
    chat_str[0] = "Nenitt-Nym coughs loudly to gain attention.\n";
    chat_str[1] = "Nenitt-Nym says: 'If you haven't got your brochure yet, please take it.'\n";
    chat_str[2] = "Nenitt-Nym shouts: 'Mudcon is coming! You can take part by registering in tavern!'\n";
    chat_str[3] = "Nenitt-Nym sobs: 'Too bad the brochure is for Finnish people only.'\n";
    chat_str[4] = "Nenitt-Nym looks at you and offers an interesting-looking brochure. \n";
    chat_str[5] = "Nenitt-Nym explains: 'The list of those persons who have already registered\n" +
                  "                      into the con is available in the city tavern.'\n";
    chat_str[6] = "Nenitt-Nym smiles: 'No one knows what kind of Suffeli can be gained when\n" +
                  "                    participating in the Mudcon.'\n";
    chat_str[7] = "Nenitt-Nym nods and says: 'There seems to be life beyond MUD after all.'\n";
    chat_str[8] = "Nenitt-Nym says: 'For further details about Mudcon, get a brochure from me\n" +
                  "                  or contact Celtron.'\n";
    chat_str[9] = "Nenitt-Nym informs: 'The T-day is in Saturday, 9th of March. Everyone is invited.\n" +
                  "                     The sauna and spending the night is totally free of charge.'\n";
  }
  load_chat(10, chat_str);
  set_exp(10);
  set_str(10);
  set_max_hp(1000000);
  set_hp(query_max_hp());
  set_max_ep(1000000);
  set_ep(query_max_ep());
  set_special(60);
  set_dead_ob(this_object());
  call_out("wander", 20);
}

wander() {
  string *dirs;
  dirs = ({"north", "north", "north", "west", "west", "west", "south", "south", "south", "south", "south", "east", "east", "east", "north", "north", "west", "west", "west", "south", "south", "east", "east", "east", "east", "east", "north", "north", "west", "west"});
  init_command(dirs[location]);
  location++;
  if(location >= sizeof(dirs)) {
    location = 0;
    call_out("wander", 40);
    return 1;
  }
  call_out("wander", 20);
  return 1;
}

monster_died() { return 0; }

special_move() {
  ob = query_attack();
  say("Nenitt-Nym quickly claps his hands and " + query_attack()->query_name() + " disappears.\n", query_attack());
  tell_object(query_attack(), "Nenitt-Nym quickly claps his hands and the reality blurs in your eyes for a short period of time.\n\n");
  move_object(ob, "/world/city/inn");
  tell_room("/world/city/inn", ob->query_name() + " materializes in the mid-air and falls face-first down on the floor.\n");
  stop_all();
  stop_all_hunting();
  heal_self(10000);
}

init() {
  ::init();
  add_action("get", "get");
}

get(str) {
  if(str != "brochure") return;
  tell_object(this_player(), "Nenitt-Nym smiles: 'Here you go, take this brochure and examine it carefully.'\n");
  say("Nenitt-nym smiles and gives a brochure to " + this_player()->query_name() + ".\n", this_player());
  move_object(clone_object("/wizards/ahma/misc/brochure"), this_player());
  return 1;
}
  
