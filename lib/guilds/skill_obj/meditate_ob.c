object mina;

start(ob) {
  mina = ob;
  shadow(mina, 1);
  return 1;
}

kill() { return use(); }

cast() { return use(); }

tell() { return use(); }

look() {return use(); }

use() {
  tell_object(mina, "You are meditating and unable to do anything.\n");
  return 1;
} 

check_condis() {
  tell_object(mina, "You are meditating and unable to do anything.\n");
  return 0;
}

move_player() {
  tell_object(mina, "You are meditating and unable to move.\n");
  return 1;
}

restore_time_points() {
  tell_object(mina, "You are meditating and cannot fight!.\n");
  return 1;
}

short() {
        return mina->short()+" (meditating)";
}

heraa() {
  destruct(this_object());
}
