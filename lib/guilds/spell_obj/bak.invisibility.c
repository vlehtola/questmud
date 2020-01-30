object user;
int time,type;

start(ob,ty,duration) {
  user = ob;
  type = ty;
  time = duration;
  shadow(user, 1);
  call_out("remove_invisibility",time);
}

query_invisible() {
  return type;
}

short(arg) {
  if(arg) return user->short();
  if(this_player()->query_see_invisible() >= type) return user->short();
}

id(str) {
  if(this_player()->query_see_invisible() >= type) {
    return user->id(str);
  }
}

remove_invisibility(silent) {
  if (!silent) {
    tell_object(user, "You feel solid.\n");
    tell_room(environment(user), user->query_name()+" turns visible!\n");
  }
  destruct(this_object());
}
