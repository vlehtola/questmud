object corp;
start(object ob, int time) {
	corp = ob;
	call_out("melt", time);
	shadow(corp, 1);
}
decay() { return 1; }

short(arg) {
  return corp->short(arg) +" {frozen}";
}

melt() {
	say("Ice melts away and corpse is ruined.\n");
	destruct(corp);
}

query_freeze_shadow() {
  return this_object();
}
