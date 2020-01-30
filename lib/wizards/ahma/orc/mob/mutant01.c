inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+38);
  set_name("snake");
  set_alt_name("mutant");
  set_alias("animal");
  set_race("mutant");
  set_short("A mutatous snake living in the sewers");
  set_long("A humongous snake is wriggling around the tunnel. The snake is mostly\n" + 
           "coloured in white, but some red areas are found on the skin. The skin is\n" + 
           "also full of bumps and incorrecties. Snake hisses loudly and its tattered\n" + 
           "tongue flutters wildly in the air. Mutant's black eyes observe you all\n" +
           "the time.\n");

  set_max_hp(query_hp() + 1500);
  set_hp(query_max_hp());
  set_str(query_str() + 60);
  set_al(-30);
  set_animal();
  set_skill("dodge", 50);
  set_skill("alertness", 40);
  set_skill("foresee attack", 30);
  set_skill("tumble", 10);
}
