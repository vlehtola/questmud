object target, what, p_ob;
int time, damage;
string damage_type;

id(str) {
  return str == "throw_object";
}
drop() {
  return 1;
}
get() {
  return 1;
}
start_throw(w, t) {
  what = present(w, this_player());
  if(!what) { write("You don't have such thing as '"+w+"' to throw.\n"); stop_throw(); return 1; }
  if(!what->is_throwable()) { write("You can't throw the '"+w+"'.\n"); stop_throw();  return 1; }
  target = present(t, environment(this_player()));
  if(!target) { write("No such target present as '"+t+"'\n");  stop_throw(); return 1; }
  if(!living(target)) { write(t+" is not a valid target.\n");  stop_throw(); return 1; }
  p_ob = this_player()->query_party();
  if(p_ob && !p_ob->first_in_row(this_player())) {
  write("You can't throw anything from back of the party.\n");
  stop_throw();
  return 1;
}
  if(this_player()->query_stunned()) {
  write("You are unable to throw anything while stunned.\n");
  stop_throw();
  return 1;
}

  time = 10;
  if(random(110) > this_player()->query_skills("conceal throwing")) {
  write("You start consentrating an throwing attempt.\n");
  say(this_player()->query_name()+" starts consentrating an throwing attempt.\n");
  call_out("resolve_throw", time);
  return 1;
}
else { write("You start ceonsentrating an throwing attempt.\n");
       call_out("resolve_throw", time);
	   return 1;
}
}

resolve_throw() {
if(random(110) > this_player()->query_skills("throw")) {
  write("You fail your throwing attempt.\n");
  say(this_player()->query_name()+" fails to throw anything.\n");
  stop_throw();
  return 1;
}
damage = what->query_quality()+this_player()->query_dex()+this_player()->query_level();
if(damage > 500)damage = 500;
damage_type = what->query_damage_type();
if(!damage_type)damage_type = "physical";
write("You throw the "+what->short()+" at "+target->query_name()+".\n");
say(this_player()->query_name()+" throws the "+what->short()+" at "+target->query_name()+".\n",target);
tell_object(target, this_player()->query_name()+" throws the "+what->short()+" at you!\n");
target->hit_with_spell(damage, damage_type);
this_player()->attack_object(target);
stop_throw();
return 1;
}
stop_throw() {
remove_call_out("resolve_throw");
if(this_object()) { destruct(this_object()); }
return 1;
}