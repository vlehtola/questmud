inherit "obj/monster";
int i = random(3);

reset(arg) {
  object claw01;
  ::reset(arg);
  if(arg) { return; }
  set_level(23 + (i*2));
  set_name("small freak");
  set_alt_name("freak");
  set_alias("minion");
  if(i==0) { set_short("Tiny freak is crawling on the ground"); }
  if(i==1) { set_short("Small freak is growling at you"); }
  if(i==2) { set_short("Hostile small freak is slashing the air"); }
  set_long("Extremely hostile and ugly-looking small piece of Freak is standing on\n" +
           "the ground and glaring at you with its small, red eyes. From the tip of\n" +
           "the creature's right hand grows five long, sturdy claws. The creature is\n" +
           "slashing the air with them, like trying to warn you about something that\n" +
           "might happen if you would try to harm it.\n");
  
  set_max_hp(query_hp() + 500);
  set_hp(query_max_hp());
  set_str(query_str() * 2);
  set_aggressive(1);
  set_dead_ob(this_object());
  if(!claw01) {
    move_object(claw01 = clone_object("/wizards/ahma/orc/eq/wepclaws"), this_object()); init_command("wield claws"); }
  set_skill("critical", 70);
  set_skill("enhance critical", 50);
  set_skill("find weakness", 50);
  set_skill("doublehit", 80);
  set_skill("dodge", 70);
  set_skill("parry", 50);
  set_skill("weapon parry", 50);
  set_skill("tumble", 50);
  set_skill("blades", 90);
  set_skill("slash", 90);
  set_al(-50);
}

monster_died() {
  if(present("leader", environment(this_object()))) {
    present("leader", environment(this_object()))->reducecloned();
  }
  if(present("claws", this_object())) {
   destruct(present("claws", this_object()));
   } 
  return 0;
}
