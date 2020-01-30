int exp;

id(str) { return str == "calc"; }

short() { return "Calculator: "+exp; }

calc(str) {
	int st,hp;
	if (!str) return;
	if (sscanf(str, "%d %d", st, hp) != 2) { return; }
	exp = 100 * (50+(st*60)*(st/15+1)+(hp)*(hp/2200+1)) / 10;
	write("\nExp: " +exp +"\n");
	return exp;
}

init() {
   add_action("calc", "calc");
   add_action("start","start");
}

start() {
  write("Ok.\n");
  clone_object("world/mage/mag/ld_preventer")->start(this_player());
}
