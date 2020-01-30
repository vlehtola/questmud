int time;
object tp;

reset(arg) {
  if(arg) { return; }
}

start(int dama, object ob) {
  time = dama*3;
  tp = ob;
  if(present("blind_curse", tp)) {
          destruct(this_object()); return 1; }
  call_out("end_blind_curse", time);
  move_object(this_object(), tp);
  tell_object(tp, "You are blinded.\n");
  return 1;
}
init() {
add_action("cursed", "ll");
add_action("cursed", "look");
}
cursed() {
write("You are blind and unable to see anything.\n");
return 1;
}

id(str) { return str == "blind_curse"; }
drop() { return 1; }
get() { return 0; }

end_blind_curse() {
        tell_object(tp, "Finally you can see again.\n");
        destruct(this_object());
return 1;
}
