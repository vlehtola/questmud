inherit "obj/monster";
int ogre_invis;

turn_invisible() {
  say("The ogremage suddenly vanishes!\n");
  ogre_invis = 1;  
}

id(str) {
  if(ogre_invis && !this_player()->query_see_invisible() < 3) {
    return 0;
  }
  return ::id(str);
}

reset(arg) {
  int i;
  string chat_str, a_chat_str;
  object money, weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(60);
  set_race("ogre");
  set_int(query_int()*10);
  set_int(query_wis()*5);
  set_gender(1);
  set_log();
  set_name("grumph");
  set_alias("mage");
  set_short("Grumph, the ogre mage");
  set_long(
"Grumph is an ogre, he is big and strong. His teeth point out of his\n"+
"open mouth as he screams the words of magic. He's dressed in combination\n"+
"of fighter and mage equipment.\n");
  chat_str = allocate(5);
  chat_str[0] = "Grumph states 'They died. We won.'\n";
  chat_str[1] = "Grumph ponders and says 'I wonder how good the defences of Duranghom really are.'\n";
  chat_str[2] = "Grumph smiles at Heinr revealing his teeth.\n";
  chat_str[3] = "Grumph says 'Nobody can stop us, not even Sinrad. We are invincible.\n";
  chat_str[4] = "Grumph tells a joke and starts laughing maniacally.\n";
  load_chat(25, chat_str);
  set_mage(1);
  set_special(100);
}

special_move() {
  object ob;
  ob = present("heinr", environment(this_object()));
  if(attacker_ob && ob) {
    tell_room(environment(this_object()), "Heinr rushes to protect Grumph!\n");
    ob->attack_object(attacker_ob);
    return 1;
  }
  if(this_object()->query_hp() > this_object()->query_max_hp() / 3) return 0;
  tell_room(environment(this_object()),
"Grumph shouts 'Guards! Help me!'\n"+
"Grumph disappears behind the curtains!\n");
  move_object(this_object(), "/wizards/celtron/ogremage/3");
  call_other(environment(this_object()), "ogre_wimpy");
}
