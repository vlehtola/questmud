object target;
get() { return 1; }
short() { return "An ethereal vine"; }
long() {
  string str;
  if(target) str = target->query_name();
  write("This is an ethereal vine thrown to you by "+str+".\n"+
    "If you pull it, it'll transport you to the same location with "+str+".\n");
}

set_target(ob) { target = ob; call_out("dest", 30); }
init() {
  add_action("pull", "pull");
}
id(str) { return str == "vine"; }

pull(str) {
  if(!str || !environment()) return 0;
  if(this_object() != present(str, environment(this_object()))) return 0;
  if(!target) {
    write(target->query_name()+" is not in game.\n");
    destruct(this_object());
    return 1;
  }
  write("You pull the vine and feel sucked away.\n");
  say(this_player()->query_name()+" pulls the vine and is sucked away in somekind of a rift.\n");
  this_player()->move_player("XX", environment(target));
  destruct(this_object());
  return 1;
}

dest() {
  destruct(this_object());
}
