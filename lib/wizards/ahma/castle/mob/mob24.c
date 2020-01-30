inherit "obj/monster";
int i = random(3);

reset(arg) {
  object torso, hat, boots, collar, staff;
  ::reset(arg);
  if(arg) { return; }
  set_level((i*3)+80);
  set_name("cervos");
  set_alt_name("demon");
  set_alias("mage");
  set_short("Cervos, the demon archmage banished from Hell");
  set_long("Cervos is very unusual sight among mages: It seems very pumped up both mentally\n" + 
           "and physically, its huge muscles shine in dim lighting. Legends tell, that this\n" + 
           "very demon was a pioner when they developed a killer fighter-mage combination\n" + 
           "in Hell. The training progress was very hard, but eventually the trainers in\n" + 
           "managed to create very effective combination, Cervos managed. This all happened\n" + 
           "something like a millenium ago. It is not known what happened then, but now,\n" + 
           "after a thousand of years, Cervos stands next to you, grinning you evilly and\n" + 
           "clenching its fists strongly. From its mouth rises a soft cloud of white steam\n" + 
           "in every breath it takes, its eyes glitter. Cervos seems ready to release its\n" + 
           "inner anger. The demon mage seems to be surrounded by elemental shield.\n");
  set_max_hp(query_max_hp() + 14000);
  set_hp(query_max_hp());
  set_al(-150);
  set_aggressive(1);
  set_resists("fire",100);
  set_resists("cold",30+(random(40)));
  set_resists("electric",30+(random(40)));
  set_mage(10);
  set_int(1000);
  set_str(query_str() + 250);
  set_dex(query_dex() + 200);
  set_skill("strike", 85);
  set_skill_chance("strike", 69);
  set_skill("tremendous blow", 80);
  set_skill_chance("tremendous blow", 37);
  set_skill("bludgeons", 100);
  set_skill("pound", 100);
  set_skill("attack", 100);
  set_skill("critical", 80);
  set_skill("enhance criticals", 80);
  set_skill("find weakness", 90);
  set_skill("stun", 80);
  set_skill("weapon parry", 75);
  set_skill("parry", 85);
  set_skill("dodge", 70);
  set_skill("riposte", 100);
  set_skill("tumble", 30);
  set_skill("throw weight", 80);
  set_skill("alertness", 80);
  set_skill("foresee attack", 70);
  set_skill("round blow", 60);
  set_skill_chance("round blow", 8);
  set_log();
  
  torso = clone_object("/wizards/ahma/castle/eq/bonemail");
  move_object(torso, this_object());
  init_command("wear mail");
  
  staff = clone_object("/wizards/ahma/castle/eq/battlestaff");
  move_object(staff, this_object());
  init_command("wield staff");

  if(i == 0) {
    boots = clone_object("/wizards/ahma/castle/eq/sandals");
    move_object(boots, this_object());
    init_command("wear sandals");
    
    collar = clone_object("/wizards/ahma/castle/eq/collar");
    move_object(collar, this_object());
    init_command("wear collar");
  }
  
  if(i == 1) {
    collar = clone_object("/wizards/ahma/castle/eq/collar");
    move_object(collar, this_object());
    init_command("wear collar");
    
    hat = clone_object("/wizards/ahma/castle/eq/hat");
    move_object(hat, this_object());
    init_command("wear hat");
  }
  
  if(i == 2) {
    hat = clone_object("/wizards/ahma/castle/eq/hat");
    move_object(hat, this_object());
    init_command("wear hat");
    
    boots = clone_object("/wizards/ahma/castle/eq/sandals");
    move_object(boots, this_object());
    init_command("wear sandals");
  }

  set_dead_ob(this_object());
}

monster_died() {
  call_other("/wizards/ahma/castle/rooms/area51", "props");
  call_other("/wizards/ahma/castle/rooms/area50", "props");
  call_other("/wizards/ahma/castle/rooms/area49b", "props");
  call_other("/wizards/ahma/castle/rooms/area49", "props");
}