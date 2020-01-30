status full;

reset(arg) {
  if(arg) return;
  full = 1;
}

init() {
    add_action("drink", "drink");
}
query_full() { return full; }
query_weight() { return 2000; }

drink(str) {
 if (present(this_object()) != this_player()) { write("Maybe you should pick it first.\n"); return 1; }
 if(!str) { write("Drink what?\n"); return 1; }
 if(str == "tankard") {
	 if(!full) {
		 write("The tankard is empty.\n"); return 1; }
		 write("You quickly drink all the beer in tankard.\n");
		 this_player()->drink_soft(1000);
		 full = 0;
		 return 1;
	 }
 }
query_long() { if(!full) { return "An empty tankard of beer.\n"; } return "A tankard full of beer.\n"; }

short() { if(!full) { return "An empty tankard of beer"; } else { return "A tankard full of beer"; } }

long(str) { if(!full) { write("Empty tankard of beer.\n"); return 1; } write("Tankard of beer.\n"); }

get() { return 1; }

id(str) {
    return str == "tankard" || str == "tankard_cheatti";
}

