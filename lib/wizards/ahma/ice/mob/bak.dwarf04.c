inherit "obj/monster";
int done;
string plr, chat_str;
object ob;

reset(arg) {
  string a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(17 + random(3));
  set_name("gordon");
  set_race("dwarf");
  set_gender(1);
  set_short("Gordon, the banished snow Dwarf");
  set_long("Gordon is quite unusual-looking Dwarf. He does not have beard on his rough\n" +
           "skin at all. The reddish colouring of his facial skin is indicating that\n" +
           "he probably keeps shaving the newly-grown beard off almost daily. Gordon\n" +
           "seems to have inborn, friendly look on his face all the times. Gordon is\n" +
           "quite small-sized and is wearing a warm set of leather clothes.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Gordon says: 'We got banished from upper levels because we were different!'\n";
    chat_str[1] = "Gordon says: 'My neighbor, Dooris, is really cute person.'\n";
    chat_str[2] = "Gordon sighs: 'Where could I get more firewood, I really could use some right now.'\n";
    chat_str[3] = "Gordon says: 'The strange liquid near Dooris's igloo is wonderful when exhausted.'\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Gordon shouts: 'I see, you consider us different, too!'\n";
    a_chat_str[1] = "Gordon screams: 'Die, you bloody rasist!'\n";
  }
  
  load_chat(4, chat_str);
  load_a_chat(10, a_chat_str);
  set_resists("cold", 40);

  move_object(clone_object("/wizards/ahma/ice/eq/lcap"), this_object()); init_command("wear cap");
  move_object(clone_object("/wizards/ahma/ice/eq/ljacket"), this_object()); init_command("wear jacket");
  move_object(clone_object("/wizards/ahma/ice/eq/lgloves"), this_object()); init_command("wear mittens");
  move_object(clone_object("/wizards/ahma/ice/eq/lpants"), this_object()); init_command("wear pants");
  move_object(clone_object("/wizards/ahma/ice/eq/lshoes"), this_object()); init_command("wear slippers");
}

catch_tell(str) {
  string target;
  if(sscanf(str, "%s gives A pile of gray bones to you.", plr) != 1) { return 1; }
  ob = find_player(lower_case(plr));
  if(done) {
    say("Gordon says: 'Thanks, but I already have enough firewood of my own.'\n");
    say("Gorgon gives bones to " + plr + ".\n");
    move_object(present("bones"), ob);
    return 1;
  }
  if(present("bones")->query_no_save()) {
    say("Gordon shouts: 'Hmm, I sense that this illusion doesn't burn. Guess what? YOU WILL!!\n");
    set_int(100000);
    set_wis(100000);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_skill("cast fire", 100);
    set_skill("knowledge of heat", 100);
    set_skill("cast bolt", 100);
    set_skill("cast essence", 100);
    set_skill("counter spell", 100);
    set_skill("reflect spell", 100);
    set_mage();
    set_spell_chance(100, "exs fla blt");
    call_out("attackob", 1);
    return 1;
  }
  say("Gordon says: 'Absolutely brilliant thinking, my friend! I will go light\n" +
      "              these right ahead. You can join with me if you like. Meet\n" +
      "              me at the campfire just outside my igloo.\n");
  destruct(present("bones", this_object()));
  done = 1;
  call_out("movement1", 3);
  return 1;
}

attackob() {
  attack_object(ob);
}

movement1() {
  say("Gordon leaves out.\n");
  load_chat(0, chat_str);
  move_object(this_object(), "/wizards/ahma/ice/rooms/311");
  say("Gordon arrives from enter.\n");
  call_out("campfire1", 7);
}

campfire1() {
  say("Gordon places all bones in a nice pile inside the circle of icy rocks.\n");
  call_out("campfire2", 7);
}

campfire2() {
  say("Gordon smiles as he looks at his work of art.\n");
  call_out("campfire3", 7);
}

campfire3() {
  say("Gordon starts skillfully rub two of the bones against each other.\n");
  call_out("campfire4", 7);
}

campfire4() {
  say("Very thin smoke starts rising from the two bones.\n");
  call_out("campfire5", 7);
}

campfire5() {
  say("Gordon manages to light a small fire with the bones.\n");
  call_out("campfire6", 7);
}

campfire6() {
  say("Gordon seems very confident as the flames in the campfire start to grow.\n");
  call_out("campfire7", 7);
}

campfire7() {
  say("Gordon says: 'Ah, I did it! I think I just sit here for a moment and watch the fire.'\n");
  scanforlady();
}

scanforlady() {
  if(present("dooris", environment(this_object()))) {
    call_out("beginquest", 6);
    return 1;
  }
  call_out("scanforlady", 5);
  return 1;
}

beginquest() {
  say("Gordon looks at Dooris.\n");
  call_out("quest1", 7);
}

quest1() {
  say("Dooris smiles mysteriously at Gordon.\n");
  call_out("quest2", 7);
}

quest2() {
  say("Gordon winks meaningfully at Dooris.\n");
  call_out("quest3", 7);
}

quest3() {
  say("Dooris whispers something to Gordon.\n");
  call_out("quest4", 7);
}

quest4() {
  say("Gordon giggles inanely.\n");
  call_out("quest5", 7);
}

quest5() {
  say("Gordon whispers something to Dooris.\n");
  call_out("quest6", 7);
}

quest6() {
  say("Dooris blushes in bright red.\n");
  call_out("quest7", 7);
}

quest7() {
  say("Gordon pulls Dooris in his arms and gives her a long, passionate kiss.\n");
  call_out("quest8", 7);
}

quest8() {
  say("Dooris stares dreamingly at Gordon.\n");
  call_out("quest9", 7);
}

quest9() {
  say("Gordon winks behind his shoulders.\n");
  say("Gordon leaves in enter.\n");
  move_object(this_object(), "/wizards/ahma/ice/rooms/i04");
  say("Gordon arrives from out.\n");
  call_out("quest10", 5);
}

quest10() {
  present("dooris", "/wizards/ahma/ice/rooms/311")->beginquest();
}

disablequest() {
  chat_str[2] = "Gordon smiles: 'Living down here isn't so bad, after all. I think I can make it.'\n";
  done = 1;
}
