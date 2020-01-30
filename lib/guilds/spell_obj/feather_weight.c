object user;
int effect;

query_weight() {
  return user->query_weight()/effect;
}

start(object ob, int power) {
  user = ob;
  effect = power;
  if(user->query_feather_weight()) {
    write(user->short()+" is already enchanted.\n");
    destruct(this_object());
    return 1;
  }

  // disabled by Celtron 22092005
  destruct(this_object());

  tell_room(user, user->short()+" seems lighter.\n");
  shadow(user, 1);
  this_player()->fix_weight();
}

short() {
        return user->short()+" <light>";
}
query_feather_weight() {
  return this_object();
}

prevent_insert() {
	write(user->short()+" cannot be inserted because of it's unnatural state.\n");
	return 1;
}
