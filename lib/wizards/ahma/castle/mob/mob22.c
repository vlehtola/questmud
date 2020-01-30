inherit "obj/monster";
int i = random(3);

reset(arg) {
  object cloak, boots, torso, sword;
  ::reset(arg);
  if(arg) { return; }
  set_level((i*3)+48);
  set_name("alucard");
  set_alt_name("demon");
  set_alias("assassin");
  set_short("Alucard the swift, a lurky demon assassin");
  set_long("A small black figure is standing on a shadowy part of this room. Whole creature\n" + 
           "is covered with black, and probably very durable, cloth which is widely used by\n" + 
           "ninjas and assassins of this realm. Assassin's moves are very quick and silent,\n" + 
           "seems that this assassin is one of the best of its kind. The demon is holding a\n" + 
           "silvery stiletto, real assassins' weapon, on its right hand. The eyes of this\n" + 
           "can be seen burning in red through the wide hole made in the black cloth covering\n" + 
           "the rest of its head.\n");
  set_max_hp(query_hp() + 28000);
  set_hp(query_max_hp());
  set_str(query_str() + 150);
  set_dex(query_dex() + 150);
  set_al(-80);
  set_aggressive(0);
  set_resists("fire",95);
  set_skill("strike", 65);
  set_skill_chance("strike", 45);
  set_skill("tremendous blow", 67);
  set_skill_chance("tremendous blow", 30);
  set_skill("weapon parry", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("riposte", 100);
  set_skill("tumble", 80);
  set_log();
  
  torso = clone_object("/wizards/ahma/castle/eq/wraps");
  move_object(torso, this_object());
  init_command("wear wrappings");

  sword = clone_object("/wizards/ahma/castle/eq/stiletto");
  move_object(sword, this_object());
  init_command("wield stiletto");  

  if(i == 0) {
    boots = clone_object("/wizards/ahma/castle/eq/slippers");
    move_object(boots, this_object());
    init_command("wear slippers");
  }

  if(i == 1) {
    cloak = clone_object("/wizards/ahma/castle/eq/cloak");
    move_object(cloak, this_object());
    init_command("wear cloak");
  }

  if(i == 2) {
    boots = clone_object("/wizards/ahma/castle/eq/slippers");
    move_object(boots, this_object());
    init_command("wear slippers");
    
    cloak = clone_object("/wizards/ahma/castle/eq/cloak");
    move_object(cloak, this_object());
    init_command("wear cloak");
  }

  set_dead_ob(this_object());
}

monster_died() {
    call_other("/wizards/ahma/castle/rooms/area49", "remove_exit", "down");
    call_other("/wizards/ahma/castle/rooms/area48", "remove_exit", "up"); 
    tell_room(environment(this_object()), "Just before the final blow, demon rushes and slams the hatch down near the\n" + 
                                          "stairs. A loud click can be heard as the hatch locks up. A soft, blue magical\n" +
                                          "glow can be seen surrounding the hatch, making it impossible for you to open\n" + 
                                          "it again.\n");
    return 0;
}