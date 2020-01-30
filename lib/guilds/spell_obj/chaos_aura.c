object user;

start(object ob, int power) {
  user = ob;
  shadow(user, 1);
  call_out("end_chaos_aura", power);
}

end_chaos_aura() {
	if(user) {
	tell_object(user, "You are no longer surrouded by chaos aura.\n");
}
destruct(this_object());
}

short() {
        return user->short()+" <surrounded by chaos>";
}

query_chaos_aura() { return 1; }

