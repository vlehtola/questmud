inherit "room/room";

reset(arg) {
add_exit("ship", "/wizards/aarrgh/ship/ship1");
short_desc = "On the Dock";
long_desc = "You are standing on the old looking dock. The dock is almost\n"+
"empty, only some old barrels made from wood are lying here. You see\n"+
"a small sized War Galleon anchored to the dock.\n";

items = allocate(4);
items[0] = "ropes";
items[1] = "These ropes are just those boat ropes what sailors use";
items[2] = "barrels";
items[3] = "Some empty barrels";
}
