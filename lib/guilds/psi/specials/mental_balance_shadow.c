object mina;
int amount;

start(ob,poks) {
  mina = ob;
  amount = poks;
  shadow(mina, 1);
  call_out("remove_mb",10);
}

kill() { return use(); }

cast() { return use(); }

use() {
  tell_object(mina, "You are balancing your mental state and unable to do anything.\n");
  return 1;
}

check_condis() {
  tell_object(mina, "You are balancing your mental state and unable to do anything.\n");
  return 0;
}

move_player() {
  tell_object(mina, "You are balancing your mental state and unable to do anything.\n");
  return 1;
}

restore_time_points() {
  tell_object(mina, "You are balancing your mental state and unable to do anything.\n");
  return 1;
}

remove_mb() {

tell_object(mina,"You balance your mental state and wake up from dormancy exhausted but mentally relaxed.\n");
	this_player()->add_sp(amount*3);
	this_player()->set_ep(0);
	destruct(this_object());
}


