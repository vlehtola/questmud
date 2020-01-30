object mina;
int time, effect;

start(ob,bonus) {
  mina = ob;
  effect = bonus;
  shadow(mina, 1);
}

death() {
  object room;
  write("You are covered by the darkness of Death.\n");
  if (random(100) > effect) {
	write("Your soul starts emitting a weak light of life, but it is swallowed by the darkness.\n");
	mina->death();
	destruct(this_object());
	return 1;
  }
  write("Your soul starts emitting a weak light of life, soon growing and vanquishing the darkness. Your soul start to regenerate..\n");
  room = environment(mina);
  move_object(mina, "/world/special/hell");
  tell_room(room, mina->query_name()+" is DEAD, R.I.P.\n");
  call_out("recover", 40);
}

recover() {
  tell_object(mina,"You feel like you have gained enough power.\n");
  tell_object(mina,"Your vision starts to blur as your will to live breaks free.\n");
  tell_object(mina,"Everything is shockingly bright for a while and then you wake up.. totally exhausted.\n");
  tell_room("/world/cleric/altar1", mina->query_name()+" raises from the ground.\n");
  move_object(mina, "/world/cleric/altar1");
  mina->set_hp(1);
  mina->set_sp(1);
  mina->set_ep(1);
  mina->reduce_ep(1000);  
  mina->remove_death();
  destruct(this_object());
}
