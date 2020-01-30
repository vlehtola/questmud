inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(31+i*5);
  set_name("beast");
  set_alias("beast");
  set_short("A large aerial beast");
  set_long("This is one of the feared pets of the arial lords. They have massive\n"+
           "fangs and rows upon rows of them. It has 6 legs and on each leg it has a set\n"+
           "of ten extremely sharp claws.\n");
  set_al(0);
  set_aggressive(0);
  set_animal(1);
  set_special(35);  /* Enable special_move() */
}

special_move() {
  object ob;
  int i;
  i = random(10);
  if(i>6) {
	  ob = this_object()->query_attack();
  	tell_object(ob, "The Airial beast jumps at you and sinks its fangs into your neck!\n");
  	say("Airial beast BITES a big chunk out of "+ob->query_name()+"'s neck!\n", ob);
  	ob->hit_with_spell(400, "physical");
	} else {
	  ob = this_object()->query_attack();
  	tell_object(ob, "Airial beast CLAWS you!\n");
  	say("Airial beast CLAWS "+ob->query_name()+" with its HUGE claws!\n", ob);
  	ob->hit_with_spell(300, "asphyxiation");
  }
}
