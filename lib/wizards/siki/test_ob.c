object target;

start(object ob) {
	target = ob;
	shadow(target, 1);
}

query_plan() {
  this_player()->link_death("jees", 1);
  return "Jees pocks!";
 }