object aijys;
int wis;

start(ob) {
  aijys = ob;
  shadow(aijys, 1);
  wis = 2;
  update_stats();
  call_out("normal", 130);
  return 1;
}

update_stats() {
  aijys->update_stats();
  aijys->set_wis(2);
}

normal() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = aijys;
  tell_object(aijys, "You feel like the effect of the potion is wearing off.\n");
  tell_room(environment(aijys), aijys->query_name()+" seems a bit more like himself again.\n", puuh);
  wis=0;
  aijys->update_stats();
  destruct(this_object());
  return 1;
}

death(arg) {
  wis=0;
  aijys->update_stats();
  aijys->death(arg);
  destruct(this_object());
  return 1;
}
