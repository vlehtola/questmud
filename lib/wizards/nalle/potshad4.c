object aijys;

start(ob) {
  aijys = ob;
  shadow(aijys, 1);
  call_out("ill", random(20)+10);
  return 1;
}

ill() {
  write("You feel like your insides are on fire!\n");
  say(call_other(this_player(), "query_name", 0) + " moans in pain!\n");
  this_player()->reduce_hp(120);
  call_out("ill2", 25);
  return 1;
}

ill2() {
  write("You find it hard to breathe!\n");
  say(call_other(this_player(), "query_name", 0) + " coughs blood!\n");
  this_player()->reduce_hp(120);
  call_out("nomoreill", 25);
  return 1;
}

nomoreill() {
  write("After one final spasm you feel like the poison is dissolving.\n");
  say(call_other(this_player(), "query_name", 0) + " roars one more time and then seems like the poison would be dissolving.\n");
  this_player()->reduce_hp(70);
  destruct(this_object());
  return 1;
}

death(arg) {
  aijys->death(arg);
  destruct(this_object());
  return 1;
}
