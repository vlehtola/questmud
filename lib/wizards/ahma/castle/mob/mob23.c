inherit "obj/monster";
int i = random(5);

reset(arg) {
  object torso, gauntlets, leggings, headband, sword, shield;
  ::reset(arg);
  if(arg) { return; }
  set_level((i+2)+70);
  set_name("rakk");
  set_alt_name("demon");
  set_alias("commander");
  set_short("Rakk the mighty, commander of the demon army");
  set_long("Extremely scary-looking and big figure. Some stories about Rakk are also known\n" + 
           "among the humans. Its malevolence is feared even in the realm of Hell. Rakk was\n" + 
           "the commander of the victorious demon army when clan of Khralak's Fist defeated\n" + 
           "the Nosfer Beasts clan and conquered the third level of Hell. After the battle\n" + 
           "and victory Rakk ordered all members of Nosfer Beasts to be executed or other-\n" + 
           "wise banished from the lower levels of Hell. This all took place somewhat four\n" + 
           "centuries ago. Anyway, the feared Rakk stands right now next to you, almost\n" + 
           "touching you, reaching inside you with its evilness, making you uncomfortable.\n" + 
           "Wheezing coming from Rakk's throat makes you think it is some huge predator\n" + 
           "waiting for its lunch to arrive. Your eyes meet with Rakk's, you can see them\n" + 
           "turning blood-red.\n");
  set_max_hp(query_hp() + 23000);
  set_hp(query_max_hp());
  set_str(query_str() + 200);
  set_al(-120);
  set_aggressive(0);
  set_resists("fire",95);
  set_skill("tremendous blow", 76);
  set_skill_chance("tremendous blow", 34);
  set_skill("weapon parry", 75);
  set_skill("parry", 75);
  set_skill("dodge", 40);
  set_skill("riposte", 100);
  set_skill("tumble", 20);
  set_skill("shield bash", 80);
  set_skill("shield parry", 70);
  set_skill("alertness", 60);
  set_skill("foresee attack", 50);
  set_skill("doublehit", 100);
  set_log();
      
  torso = clone_object("/wizards/ahma/castle/eq/bonemail");
  move_object(torso, this_object());
  init_command("wear mail");
  
  shield = clone_object("/wizards/ahma/castle/eq/shield");
  move_object(shield, this_object());
  init_command("wield shield");

  if(i == 0) {
    sword = clone_object("/wizards/ahma/castle/eq/soulsword");
    move_object(sword, this_object());
    init_command("wield sword");
    
    headband = clone_object("/wizards/ahma/castle/eq/headband");
    move_object(headband, this_object());
    init_command("wear headband");
  }
  
  if(i == 1) {
    gauntlets = clone_object("/wizards/ahma/castle/eq/gauntlets");
    move_object(gauntlets, this_object());
    init_command("wear gauntlets");
    
    sword = clone_object("/wizards/ahma/castle/eq/soulsword");
    move_object(sword, this_object());
    init_command("wield sword");
  }
  
  if(i == 2) {
    gauntlets = clone_object("/wizards/ahma/castle/eq/gauntlets");
    move_object(gauntlets, this_object());
    init_command("wear gauntlets");
    
    headband = clone_object("/wizards/ahma/castle/eq/headband");
    move_object(headband, this_object());
    init_command("wear headband");
    
    sword = clone_object("/wizards/ahma/castle/eq/bonesword");
    move_object(sword, this_object());
    init_command("wield sword");
  }
  
  if(i == 3) {
    headband = clone_object("/wizards/ahma/castle/eq/headband");
    move_object(headband, this_object());
    init_command("wear headband");
    
    leggings = clone_object("/wizards/ahma/castle/eq/leggings");
    move_object(leggings, this_object());
    init_command("wear leggings");
  
    sword = clone_object("/wizards/ahma/castle/eq/bonesword");
    move_object(sword, this_object());
    init_command("wield sword");
  }
  
  if(i == 4) {
    headband = clone_object("/wizards/ahma/castle/eq/headband");
    move_object(headband, this_object());
    init_command("wear headband");
    
    leggings = clone_object("/wizards/ahma/castle/eq/leggings");
    move_object(leggings, this_object());
    init_command("wear leggings");
    
    sword = clone_object("/wizards/ahma/castle/eq/soulsword");
    move_object(sword, this_object());
    init_command("wield sword");
  }
}