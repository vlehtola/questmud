inherit "obj/monster";
int follow, i, drinkon, h, done;
string plr, plr2, chat_str;
object ob;

reset(arg) {
  string a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(16 + random(3));
  set_name("dooris");
  set_race("dwarf");
  set_gender(2);
  set_short("Dooris, the banished snow Dwarf female");
  set_long("Dooris is a small, somewhat plump Dwarven female. Her cheeks are a bit\n" +
           "reddish, maybe because of the cold temperature. Dooris has a friendly\n" +
           "smile on her lips and in whole, she seems to be happy with her life at\n" +
           "the moment. As a Dwarf, Dooris probably has some muscles under her kind\n" +
           "frontage. Dooris is wearing a warm set of leather clothes.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Dooris says dreamily: 'I think I'm in love with my neighbor, Gordon.'\n";
    chat_str[1] = "Dooris giggles: 'Gordon is such a handsome man.'\n";
    chat_str[2] = "Dooris says: 'Oh, I would love to get some of Gordon's tea right away!'\n";
    chat_str[3] = "Dooris says: 'After Terran imprisoned us in this level, I have actually\n" +
                  "              started to enjoy of being down here.'\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Dooris shouts: 'I sweep you away in no time! Just look!'\n";
    a_chat_str[1] = "Dooris slaps you in the right cheek.\n";
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
  if(!follow) {
    if(sscanf(str, "%s gives A brass tea pan to you.", plr) != 1) { return 1; }
    ob = find_player(lower_case(plr));
    if(done) {
      say("Dooris says: 'I'm not in the mood right now. Take this one back.'\n");
      move_object(present("pan"), ob);
      return 1;
    }
    if(present("pan")->query_no_save()) {
      say("Dooris screams: 'What the hell! This is an illusion! DIE MAGGOT!!'\n");
      call_out("attackob", 2);
      return 1;
    }
    if(present("pan", this_object())->query_empty()) {
      say("Dooris frowns: 'Seems that the pan is empty, how sad.'\n");
      return 1;
    }
    say("Dooris says: 'How wonderful! Wait a moment while I drink this.'\n");
    drinkon = 1;
    done = 1;
    call_out("drinktea", 3);
    return 1;
  }
  else {
    if(sscanf(str, "%s leaves", plr2) != 1) { return 1; }
    if(plr2 != plr) { return 1; }
    call_out("moveto", 2);
    return 1;
  }
}

attackob() {
  attack_object(ob);
}

moveto() {
  say("Dooris leaves after " + plr + ".\n");
  move_object(this_object(), environment(ob));
  say("Dooris arrives after " + plr + ".\n");
}

checkroom() {
  if(query_current_room() == "/wizards/ahma/ice/rooms/311" && follow) {
    follow = 0;
    call_out("teareturned", 3);
    return 1;
  }
}

drinktea() {
  if(!drinkon) { return 1; }
  load_chat(0, chat_str);
  if(!random(3)) {
    h = random(6);
    if(h == 0) write("Dooris smells the pan with a fascinating look on her face.\n");
    if(h == 1) write("Dooris takes a tiny gulp of tea and smiles dreamily.\n");
    if(h == 2) write("A wonderful scent spreads in the igloo from the open tea pan.\n");
    if(h == 3) write("Dooris tips the tea pan and takes a short peek inside of it.\n");
    if(h == 4) write("Looks like Dooris would be in heaven when drinking from the pan.\n");
    if(h == 5) write("Dooris licks her lips while not drinking the tea.\n");
  }
  drinkon++;
  if(drinkon < 20) { call_out("drinktea", 3); return 1; } 
  call_out("drinkready", 2);
}

drinkready() {
  say("Dooris says: 'Oh, that was maybe the best tea moment in my life.'\n");
  call_out("drinkready2", 3);
}

drinkready2() {
  say("Dooris says: 'Now let's return this tea pan back to its original place.\n" + 
      "              I'll follow you for that time.\n");
  follow = 1;
  environment(this_object())->nopop();
}

teareturned() {
  say("Dooris hangs the tea pan back to its original place above the fireplace.\n");
  call_out("teareturned2", 5);
}

teareturned2() {
  say("Dooris says: 'I don't know actually why, but I think I'll stay here for a while.\n");
}

beginquest() {
  say("Looks like Dooris started pondering something very hard.\n");
  call_out("quest1", 5);
}

quest1() {
  say("Dooris seems to have made up her mind.\n");
  call_out("quest2", 5);
}

quest2() {
  say("Dooris leaves enter.\n");
  say("A magical field seems to block the doorway into the igloo.\n");
  if(!ob->query_quests("Helping out the neighbors")) {
    tell_object(ob, "Congratulations! You have completed the quest 'Helping out the neighbors'.\n");
    ob->set_quest("Helping out the neighbors");
  }
  else {
    tell_object(ob, "You have already completed this quest before.\n");
  }
  environment(this_object())->specdesc();
  move_object(this_object(), "/wizards/ahma/ice/rooms/i04");
  environment(this_object())->nopop();
  say("Dooris arrives from out.\n");
}

disablequest() {
  chat_str[2] = "Dooris says: 'You better believe it, Gordon makes the best tea in the world.'\n";
  done = 1;
}
