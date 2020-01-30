inherit "obj/monster";
reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }

 set_level(random(7)+45);
  set_race("priest");
  set_name("priest");
  set_short("Demonic priest wearing black cloak");
  set_long("This is a demonic priest roaming around the hall It chants some.\n"
           "demonic runes which is quite impossible to understand. The gender of\n"
    	   "this creature is impossible to determine. It doesnt look aggressive\n");
  set_al(-5);
  set_gender(1);
  set_skill("stun", 30);
  set_skill("tumble", 10);
  set_skill("stun", 90);
  set_skill("bare hands", 100);
  set_skill("critical", 40);
  set_hp(query_max_hp());
  set_special(20);

}

special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Priest cuts your throat with its siphon!\n");
  say("Priest cuts "+ob->query_name()+"'s throat with siphon!\n", ob);
  ob->hit_with_spell(65);
}