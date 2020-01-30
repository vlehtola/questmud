inherit "obj/monster";
int i = random(2);

reset(arg) {
  object necklace, torso, belt, shield, sword;
  ::reset(arg);
  if(arg) { return; }
  set_level((i*3)+48);
  set_name("lark");
  set_alt_name("demon");
  set_alias("fighter");
  set_short("Lark the nasty, a crap-talking demon lieutenant");
  set_long("The demon stinks badly, though it seems to be very clean. From somewhere deep\n" + 
           "inside this creature is floating enormously horrible stench, you cannot even\n" + 
           "compare it to any of the bad stenches you have encountered before. When it\n" + 
           "looks at you, in its sight and grin can be seen a great sarcasm, like it would\n" + 
           "be trying to brag about something to you. But in same time as it looks like\n" + 
           "childish little bastard, it looks like a skillful fighter ready for battle.\n");
  set_max_hp(query_hp() + 16000);
  set_hp(query_max_hp());
  set_str(query_str() + 120);
  set_al(-80);
  set_aggressive(0);
  set_resists("fire",95);
  set_skill("strike", 65);
  set_skill_chance("strike", 40);
  set_skill("tremendous blow", 64);
  set_skill_chance("tremendous blow", 25);
  set_skill("shield parry", 80);
  set_skill("parry", 80);
  set_skill("dodge", 40);
  set_skill("shield bash", 80);
  set_skill("riposte", 80);
  set_log();
  
  torso = clone_object("/wizards/ahma/castle/eq/bonemail");
  move_object(torso, this_object());
  init_command("wear mail");

  sword = clone_object("/wizards/ahma/castle/eq/bonesword");
  move_object(sword, this_object());
  init_command("wield sword");  

  shield = clone_object("/wizards/ahma/castle/eq/shield");
  move_object(shield, this_object());
  init_command("wield shield");

  necklace = clone_object("/wizards/ahma/castle/eq/necklace");
  move_object(necklace, this_object());
  init_command("wear necklace");

  if(i) {
    belt = clone_object("/wizards/ahma/castle/eq/belt");
    move_object(belt, this_object());
    init_command("wear belt");
  }
}