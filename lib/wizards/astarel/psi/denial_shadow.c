object user;
int time,type;

start(ob,duration) {
  user = this_player();
  type = 10;
  time = duration;
  shadow(user, 1);
  call_out("remove_denial",time);
}

query_mentaldenial() {
  return 1;
}

remove_denial() {
  
    tell_object(user, "You are no longer mentally denied.\n");
    
  
  destruct(this_object());
}
