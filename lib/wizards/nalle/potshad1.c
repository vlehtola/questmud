object aijys;
int str;
start(ob) {
  aijys = ob;
  shadow(aijys, 1);
  str = 4;
  update_stats();
  call_out("normal", 119);
  call_out("definate_loop", 25);
  return 1;
}

definate_loop() {
  write("You rub your muscles in an attempt to make them function correcly again.\n");
  say(call_other(this_player(), "query_name", 0) + " rubs his muscles as they fail to work properly.\n");  call_out("definate_loop",random(20)+30); 
}

update_stats() {
  aijys->update_stats();
  aijys->set_str(4);
}

normal() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = aijys;
  tell_object(aijys, "You feel like the effect of the potion is wearing off.\n");
  tell_room(environment(aijys), aijys->query_name()+" seems to feel a bit better.\n", puuh);
  str=0;
  aijys->update_stats();
  destruct(this_object());
  return 1;
}

death(arg) {
  str=0;
  aijys->update_stats();
  aijys->death(arg);
  destruct(this_object());
  return 1;
}
