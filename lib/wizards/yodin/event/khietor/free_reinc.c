short() { return "A small paper labeled 'free reinc'"; }

long() {
	write("A small paper labeled 'free reinc'\n");
	write("You can get free reinc by typing 'free_reinc'\n");
	write("You will lose all the equipments that you are carrying.\n");
}

id(str) {
        return str == "paper";
}

init() {
	add_action("reinc_me", "free_reinc");
}
query_name() { return "paper"; }

reinc_me() {
	object ob;
	int i;
	if (present(this_object()) != this_player()) {
		write("Maybe you should pick it up first.\n");
		return 1;
	}
	this_player()->end_berserk();
	this_player()->save_me(1);
	  ob = all_inventory(this_player());
	  while(i<sizeof(ob)) {
	    if(ob[i] && ob[i]->short()) {
	      if (!ob[i]->id("house key")) {
	        /* force drop all. regardless of keep etc */
	        move_object(ob[i], environment(this_player()));
	        // Destruct guildleaderitems ++Celtron
	        if(ob[i]->drop()) destruct(ob[i]);
	      }
	    }
	    i += 1;
	  }
	  move_object(this_player(), "/obj/race_selection");
      this_player()->look();
      destruct(this_object());
      return 1;
}

drop() {
  return 0;
}
get() {
  return 1;
}
query_weight() { return 50; }