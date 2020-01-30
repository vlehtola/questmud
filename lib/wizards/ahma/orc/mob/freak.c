inherit "obj/monster";
int cloned, i = random(3);

reset(arg) {
  string chat_str;
  object claw01, claw02, ring;
  ::reset(arg);
  if(arg) { return; }
  set_level(68 + (i*3));
  set_name("freak");
  set_alias("leader");
  set_alt_name("creature");
  set_short("Deformed freak living in the pond");
  set_long("A big, deformed creature is breathing wildly on a shore of the pond. The\n" + 
           "creature is covered with green algae and other weeds from the bottom of\n" + 
           "the pond. Its small, red eyes scan at its surrounding carefully, and a\n" + 
           "thin cloud of steam rises from its mouth everytime it exhales. Creature's\n" + 
           "skin pores seem to excrete some kind of liquid, which seems to burn small\n" + 
           "holes on the ground when hitting it.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Freak lets out some screaming voices.\n";
    chat_str[1] = "Freak stares at you maniacally with its red eyes.\n";
    chat_str[2] = "Freak bangs its fist to the ground and roars loudly.\n";
  }
  load_chat(3, chat_str);
  
  set_resists("fire", 80 + random(21));
  set_max_hp(query_hp() + 30000);
  set_hp(query_max_hp());
  set_str(query_str() * 2);

  set_dead_ob(this_object());
  if(!claw01) {
    move_object(claw01 = clone_object("/wizards/ahma/orc/eq/wepclaws"), this_object()); init_command("wield claws"); }
  if(!claw02) {
    move_object(claw02 = clone_object("/wizards/ahma/orc/eq/wepclaws"), this_object()); init_command("wield claws"); }
  if(!ring) {
    move_object(ring = clone_object("/wizards/ahma/orc/eq/freakring"), this_object()); init_command("wield ring"); }

  set_special(20);

  if(i==1) {
    move_object(clone_object("/wizards/ahma/orc/eq/freakbracers"), this_object());
    init_command("wear bracers");
  }
  
  if(i==2) {
    move_object(clone_object("/wizards/ahma/orc/eq/freakbelt"), this_object());
    init_command("wear belt");
  }

  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("weapon parry", 80);
  set_skill("doublehit", 50);
  set_skill("critical", 80);
  set_skill("enhance criticals", 60);
  set_skill("find weakness", 60);
  set_skill("tremendous blow", 65);
  set_skill_chance("tremendous blow", 25);
  set_skill("round blow", 40);
  set_skill_chance("round blow", 14);
  set_skill("tumble", 40);
  set_log();
  set_al_aggr(200);
  set_al(-100);
}

monster_died() {
  tell_room(environment(this_object()), "As the freak stops breathing, the surface of the pond starts to bubble\n" + 
                        "and some dead fish appear to float on the surface. After bubbling few\n" + 
                        "seconds, the surface seems to purify from the green poisonous substance.\n");
  call_other("/wizards/ahma/orc/forest/for11", "purifyon");
  if(present("claws", this_object())) { destruct(present("claws", this_object())); }
  if(present("claws", this_object())) { destruct(present("claws", this_object())); }
  move_object(clone_object("/wizards/ahma/orc/eq/claws"), this_object());
  move_object(clone_object("/wizards/ahma/orc/eq/claws"), this_object());
  return 0;
}

special_move() {
  if(cloned < 8) {
    say("Small piece of Freak's flesh drops on the ground. The moment the piece touches\n" +
        "the ground, small feet and arms grow to the chunk of flesh. Small freak attacks.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/freak02"), environment(this_object()));
    cloned++;
  }
}

reducecloned() {
  cloned--;
}
