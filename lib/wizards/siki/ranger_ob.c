#define TP this_player()
#define TIME 5
object bow;
object arrow;
object target;
int damage;

short() {
  return "Ranger object";
}
id(str) {
  return str == "ob";
}
long() {
  write("Commands available:\n"+
         "reload [bow]\n"+
         "shoot [target]\n"+
         "create [arrow|bow]\n");
}
drop() {
  return 1;
}
get() {
  return 1;
}
reset(arg) {
  if(arg) return;
}

init() {
  if(!this_player()->query_wiz()) {
	 destruct(this_object());
	 return 1;
 }
  add_action("cmd_reload", "reload");
  add_action("cmd_shoot", "shoot");
  add_action("cmd_create", "create");
}
cmd_shoot(string str) {
	string what, tgt;
	if(!str) { write("Usage: shoot [bow] at [arrow]\n"); return 1; }
	if(sscanf(str, "%s at %s", what, tgt))
	bow = present(what, this_player());
	if(!bow) { write("You don't have such thing to shoot.\n"); return 1; }
	if(!bow->query_bow()) { write("You can't shoot with that.\n"); return 1; }
	if(!bow->query_reloaded()) { write(what+" is not reloaded with anything.\n"); return 1; }
	write("You start to aiming your bow at "+tgt+"\n");
	say(TP->query_name()+" starts aiming "+TP->query_possessive()+" bow at "+tgt+".\n");
	call_out("real_shoot", TIME, tgt);
	return 1;
}
real_shoot(string str) {
	target = present(str, environment(this_player()));
	damage = this_player()->query_dex()+this_player()->query_level()+bow->query_quality();
	if(!target) { write("No such target present as "+str+"\n"); return 1; }
	if(!living(target)) { write(str+" is not a valid target.\n"); return 1; }
	write("You release your hands from the string of bow and.\n");
	write("You hit the "+str+" with your arrow.\n");
	tell_object(target, TP->query_name()+ " hits you with "+TP->query_possessive()+" the arrow\n");
	say(TP->query_name()+" shoots with "+TP->query_name()+" bow at "+str+"\n");
	this_player()->attack_object(target);
	target->hit_with_spell(damage, "physical");
	return 1;
}

cmd_reload(string str) {
	string what, with;
   if(!str) { write("Usage: reload [bow] with [arrow]\n"); return 1; }
   if(sscanf(str, "%s with %s", what, with))
   bow = present(what, this_player());
   if(!bow) { write("You don't have anything such thing as '"+what+"'\n"); return 1; }
   if(!bow->query_bow()) { write("You can't reload that.\n"); return 1; }
   arrow = present(with, this_player());
   if(!arrow) { write("You don't have such thing as "+with+"\n"); return 1; }
   if(!arrow->query_arrow()) { write("You can't reload the "+what+" with "+with+".\n"); return 1; }
   if(bow->query_reload()) { write("The "+what+" is already reloaded with something\n"); return 1; }
   bow->set_reload(arrow->short(), arrow->query_quality());
   destruct(arrow);
   write("You reload your "+what+" with "+with+".\n");
   say(TP->query_name()+" reloads "+TP->query_possessive()+" "+what+" with "+with+".\n");
   return 1;
}
