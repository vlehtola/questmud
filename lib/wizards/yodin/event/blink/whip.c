reset(arg) {
	if(arg) return;
}
short() {
	return "A long whip";
}
id(str) {
	return str == "whip";
}
long() {
	write("A brown leather whip.\nGood for catching dogs.\n");
}
	drop() {
		return 0;
	}
	get() {
		return 1;
	}
	query_weight() {
		return 10;
	}
init() {
	add_action("catch_dog", "catch");
	add_action("test_catch", "tcatch");
}

catch_dog(str) {
	object ob;
	if(str != "dog") { write("You can only try to catch blink dog with this.\n"); return 1; }
	ob = present(str, environment(this_player()));
	if(!ob) { write("You failed to catch anything.\n"); return 1; }
	if(!ob->query_blink_dog()) { write("You can't catch that.\n"); return 1; }
	ob->catch_me();
	return 1;
}
test_catch() {
	object ob;
	ob = find_object("/wizards/neophyte/blink/blinkdog");
		if(!this_player()->query_wiz()) return;
	if(!ob) return;
	destruct(ob);
}
