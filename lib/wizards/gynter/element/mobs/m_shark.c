inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(15+i*5);
  set_name("medium shark");
  set_alias("shark");
  set_short("A medium sized shark");
  set_long("This is one of the assassins of the water. It has a huge tail that enables it\n"+
           "to swim extremely fast through the waters. It has a huge mouth with thousand of small\n"+
           "teeths that are sharper than any sword in the known worlds.\n");
  set_al(-50);
  set_aggressive(0);
  set_animal(1);

  set_special(35);  /* Enable special_move() */
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "The shark swimms extremely fast up to you and bites you in the throat!\n");
  say("The shark swimms up to "+ob->query_name()+" and sinks it's teeth in his throat!\n", ob);
  ob->hit_with_spell(250, "physical");
}
