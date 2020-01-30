inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(15)+30);
  set_aggressive(1);
  set_follow(50, 1);
  set_str(query_str() + 50);
  set_name("crab");
  set_race("crab");
  set_short("Small crab");
  set_long("Small crab guarding it's master.");
  set_al(8);
  set_special(8);
  set_animal();
}

special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Crab cuts your flesh with its pincers.\n");
  say("Crab cuts "+ob->query_name()+".with its pincers.\n", ob);
  ob->hit_with_spell(50, "physical");
}
