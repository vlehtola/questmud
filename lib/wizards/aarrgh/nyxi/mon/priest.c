inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) { return; }

  set_level(random(7)+40);
  set_max_hp(query_max_hp() * 2);
  set_hp(query_max_hp());
  set_name("priest");
  set_short("Demonic priest wearing black cloak");
set_gender(3);
  set_long("This is a demonic priest roaming around the hall It chants some.\n"
           "demonic runes which is quite impossible to understand. The gender of\n"
    	   "this creature is impossible to determine. It doesnt look aggressive\n");
  set_al(-5);
  set_skill("stun", 30);
  set_skill("tumble", 10);
  set_skill("stun", 90);
  set_skill("bare hands", 100);
  set_skill("critical", 40);
  set_special(20);

}

