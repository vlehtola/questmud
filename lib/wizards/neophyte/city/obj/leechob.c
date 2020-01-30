object user;
int duration;

start(object ob, int bonus) {
  user = ob;
  duration = bonus;
  shadow(user, 1);
  call_out("end_leech", duration);
  call_out("leech", 15);
}
leech() {
	int i;
	object ob;
	ob = find_object("/wizards/neophyte/city/monst/nghost");
	if(!ob) { end_leech(); return 1; }
	if(user->query_sp() < 149) { end_leech(); return 1; }
		tell_object(user, "The ghost leeches you spell points.\n");
		user->reduce_sp(150);
		ob->heal_self(150);
		call_out("leech", 15);
		return 1;
	}
query_hp_leech() {
  return 1;
}

end_leech() {
  tell_object(user, "Finally the leeching ends!\n");
  destruct(this_object());
}
