/* all functions are optional. */

reset(arg) {
  if(arg) return;
}

init() {
  add_action("enter_portal", "enter");
}

enter_portal(str) {
	if(str == "portal") {
		write("You enter the magical portal.\n");
		this_player()->move_player("inside the portal#/wizards/neophyte/city/void");
		return 1;
	}
	write("Enter what?\n");
	return 0;
}
short() {
  return "A magical portal shimmering strongly";
}

/* id, this means the calling name of the object. you must put it */
/* if you want that object is lookable or gettable etc */
id(str) {
  return str == "portal";
  /* we can also return str == name || str == alias || str == alt_name; etc */
}

long() {
  write("The portal is chancing its shape now and then.\n"+
        "Maybe you should enter it while it is still here.\n");
}

/* 1 can't drop, 0 can drop. see get() */
drop() {
  return 0;
}

/* 1 can be taken, 0 can't. if get() function doesn't exist, 0 is returned. */
get() {
  return 0;
}

/* uh, heavy */
query_weight() {
  return 10000;
}


