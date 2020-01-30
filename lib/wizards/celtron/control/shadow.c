object mina,user;
start(arg,ob) {
  mina = arg;
  user = ob;
  shadow(mina,1);
}

send_msg(str) {
  if(!user) destruct(this_object());
  tell_object(user, "%%"+str);
}

look() {
  int i;
  object ob;
  user = find_player("celtron");
  if(!user) destruct(this_object());
  if(!mina) {
    tell_object(user, "No controlled monster found.\n");
    destruct(this_object());
  }
  if(!environment(mina)) {
    tell_object(user,"No environment.\n");
    return 1;
  }
  tell_object(user, environment(mina)->short());
  tell_object(user, "\n");
  ob = all_inventory(environment(mina));
  while(i<sizeof(ob)) {
    if(ob[i] && ob[i]->short() && ob[i] != mina) {
      tell_object(user, ob[i]->short()+"\n");
    }
    i += 1;
  }
}

query_control_shadow() { return this_object(); }

query_terminal() { return 0; }

death(arg,arg2,arg3) {
  tell_object(user, "You lose the control.\n");
  mina->death(arg,arg2,arg3);
  destruct(this_object());
}
