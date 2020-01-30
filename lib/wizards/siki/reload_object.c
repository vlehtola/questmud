object bow, arrow;
int time;

id(str) {
  return str == "reload_object";
}
drop() {
  return 0;
}
get() {
  return 1;
}
query_no_save() { return 1; }

start_reload(object what, object with, int i) {
	bow = what;
	arrow = with;
	time = i;
    call_out("do_reload", time);
}

do_reload() {
	write("You finish reloading your "+bow->short()+".\n");
	bow->set_reload(arrow->short(), arrow->query_damage(), arrow->query_crit_chance(), arrow->query_stun_chance(), arrow->query_quality()/3);
    move_object(arrow, bow);
	destruct(this_object());
}
