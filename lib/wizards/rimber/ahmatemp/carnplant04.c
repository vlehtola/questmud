inherit "obj/monster";
object ob;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 45);
  set_name("carnivorous plant");
  set_alt_name("plant");
  set_short("A huge and hungry carnivorous plant");
  set_long("A huge carnivorous plant lets out some furious sounds. It seems to be\n" + 
           "extremely hungry and aggressive. In its trunk grows dozens of mouths full\n" + 
           "of sharp teeth. The smacking sounds made by the mouths indicate that they\n" + 
           "are dying to devour with a fresh meat of some animal or humanoid creature.\n");

  set_max_hp(query_hp() + 50000);
  set_hp(query_max_hp());
  set_animal();
  set_aggressive(1);
  set_str(query_str() * 2);
  set_skill("doublehit", 80);
  set_skill("critical", 80);
  set_skill("enhance criticals", 70);
  set_skill("find weakness", 70);
  set_skill("deceived attack", 90);
  set_skill("throw weight", 80);
  set_dead_ob(this_object());
  set_al(-70);
}

monster_died() {
  ob = query_attack();
  if(!ob->query_quests("Devouring the carnivorous plants")) {
    tell_object(ob, "You completed the quest 'Devouring the carnivorous plants'.\n");
    ob->set_quest("Devouring the carnivorous plants");
  }
  else {
    tell_object(ob, "You have already completed this quest.\n");
  }
  tell_room(environment(this_object()), "The plant scatters into small pieces.\n");
  return 0;
}