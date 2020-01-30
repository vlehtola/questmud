int time;
object tp;

reset(arg) {
  if(arg) { return; }
}

start(int dama, object ob) {
  time = dama*3;
  tp = ob;
  if(present("say_curse", tp)) {
          destruct(this_object()); return 1; }
  call_out("end_say_curse", time);
  move_object(this_object(), tp);
  tell_object(tp, "You are muted.\n");
  return 1;
}
init() {
add_action("cursed", "say");
add_action("cursed", "tell");
}
cursed() {
write("You are cursed and unable to do that.\n");
write("You can use channels thought.\n");
return 1;
}

id(str) { return str == "say_curse"; }
drop() { return 1; }
get() { return 0; }

end_say_curse() {
        tell_object(tp, "Finally you can open your mouth.\n");
        destruct(this_object());
return 1;
}
