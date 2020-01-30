
object mina;

start(ob) {
  mina = ob;
  shadow(mina, 1);
  return 1;
}

kill() { return use(); }

cast() { return use(); }

use() {
  tell_object(mina, "You are concentrating on elements and unable to do anything.\n");
  return 1;
}

check_condis() {
  tell_object(mina, "You are concentrating on elements and unable to do anything.\n");
  return 0;
}

move_player() {
  tell_object(mina, "You are concentrating on elements and unable to move.\n");
  return 1;
}

restore_time_points() {
  tell_object(mina, "You are concentrating on elements and cannot fight!.\n");
  return 1;
}

short() {
        return mina->short()+" (concentrating)";
}

heraa() {
  destruct(this_object());
}


