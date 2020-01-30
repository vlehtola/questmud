inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) {return; }
  set_name("guard");
  set_level(57);
  set_race("human");
  set_experience(21000);
  set_gender(1);
  set_str(query_str()*2);
  set_dex(query_dex()*4);
  set_con(query_con()*2);
  set_max_hp(query_hp()+(15000));
  set_block_dir("west");
  set_al(-3);
  set_short("Captains elite guard is standing here");
  set_long("This is a strong looking man whose job is to watch that nobody \n"+
           "tries to enter the captains room. He is not using any weapons, \n"+
           "but he sure looks like he could kick your ass pretty easily.\n");
        set_skill("kick", 100);
        set_skill_chance("kick", 40);
        set_skill("tumble", 20);
        set_skill("stun", 80);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
   

}



