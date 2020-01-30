init() {
  add_action("say", "say");
}


say(str) {
  call_out("echo", 2, str);
  return 0;
}

echo(str) {
  tell_room(this_object(), str+"\n");
}
