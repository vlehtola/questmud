
inherit"obj/monster";

reset(arg) {
  object armour; 
  ::reset(arg);
  if(arg) { return; }
  set_name("dragon");
  set_level(60);
  set_ep(15000);
  set_al(8);
  set_al_aggr(100);
  set_alias("red dragon");
  set_alt_name("dragon");
  set_race("dragon");
  set_short("Red Dragon scanning the surroundings");
  set_long("Just a look on it's eyes makes you scare the hell out of you! This is the\n"
         + "last place you want to go! You really should make a run for it! RUN while\n"
         + "you can! Dragon's red skin shimmers in sun shine. It's so big that you\n"
         + "can't see nothing but its chest\n");
  set_aggressive(0);
  set_dead_ob(0);
  set_skill("attack", 100);
  set_skill("stun", 100);
  set_skill("strike", 100);
  set_skill("find weakness", 100);
  set_skill("critical", 100);

    armour = clone_object("/wizards/siggy/area/unseen/scale.c");
    move_object(armour, this_object());
    init_command("wear scale");

}
