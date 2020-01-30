
inherit"obj/monster";

reset(arg) {
  object weapon;  
  ::reset(arg);
  if(arg) { reset(arg); }
  set_name("cook");
  set_level(30);
  set_ep(5000);
  set_gender(1);
  set_al(10); 
  set_al_aggr(200);
  set_alias("human");
  set_alt_name("cook");
  set_race("human");
  set_short("Cook making delicious dinner");
  set_long("The cook of the Unseen University is making delicious dinner for wizards.\n"
         + "They say that he is the one of them around here who can't cast spells at\n"
         + "all. Well, you still should not be aggressive to him, his cleaver in his\n"
         + "hand is looking quite sharp today.\n");
  set_aggressive(0);
  set_dead_ob(0);
  set_skill("attack", 100);
  set_skill("find weakness", 70);


    weapon = clone_object("/wizards/siggy/area/unseen/cleaver");
    move_object(weapon, this_object());
    init_command("wield cleaver");

}
