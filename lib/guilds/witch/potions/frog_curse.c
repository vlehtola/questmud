int time;
object tp;

reset(arg) {
  if(arg) { return; }
}

start(int dama, object ob) {
  time = dama*3;
  tp = ob;
  if(present("frog_curse", tp)) {
          destruct(this_object()); return 1; }
  call_out("end_frog_curse", time);
  move_object(this_object(), tp);
  tell_object(tp, "You turn into frog.\n");
  return 1;
}
init() {
add_action("shout_", "shout");
add_action("say_", "say");
add_action("tell_", "tell");
}
say_(str) {
	say(this_player()->query_name()+" says 'Hriibit hriibit!'\n");
	write("You say '"+str+"'\n");
	return 1;
}

shout_(str) {
	shout("You shout '"+str+"'\n");
	say(this_player()->query_name()+" makes somekind of hrriibit voice.\n");
	return 1;
}
tell_(str) {
	write("You try to tell something but you can't be heard.\n");
	say(this_player()->query_name()+" makes somekind of hrriibit voice.\n");
return 1;
}
id(str) { return str == "frog_curse"; }
drop() { return 1; }
get() { return 0; }

end_frog_curse() {
        tell_object(tp, "Finally you turn into normal again.\n");
        destruct(this_object());
return 1;
}
