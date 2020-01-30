inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 45);
  set_name("elemental");
  set_race("elemental");
  set_short("A huge earth elemental");
  set_long("This huge boulder-like earth elemental seems to be having a lunch break\n" + 
           "in this room. Elemental stuffs huge rocks into its big mouth. When the\n" + 
           "elemental chews its stony food, loud cracking can be heard. Creature's\n" + 
           "torso looks like a huge boulder and its legs and arms are very short\n" + 
           "compared to the torso. Though the legs and arms are short, they are very\n" +
           "muscular and seem to be capable of crushing even bigger boulders easily.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Elemental grunts something at you.\n";
    chat_str[1] = "Elemental grabs couple of rocks from the ground and tosses them into its mouth.\n";
    chat_str[2] = "Elemental spits a piece of rock out from its mouth on the floor.\n";
  }
  load_chat(3, chat_str);
  
  set_max_hp(query_hp() + 10000);
  set_hp(query_max_hp());
  set_str(query_str() + 120);
  set_resists("electric", 100);
  set_skill("kick", 100);
  set_skill_chance("kick", 100);
  set_skill("critical", 90);
  set_skill("enhance criticals", 50);
  set_skill("find weakness", 60);
  set_al(-15);
}
