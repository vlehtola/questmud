inherit "room/room";
reset(arg) {
add_exit("enter","/wizards/terror/goblin/roomit/g1.c");
items = allocate(4);
items[0] = "A sign";
items[1] = "This is enterance of goblin forest.\n"+
"This place is well keeped and the builders were ancestors of goblins.\n"+
"There will be not alloved evil people so be carefully.\n";
short_desc = "Enterance of the old goblin forest";
long_desc = "You see some alive at the end of short path.\n"+
"There is someone living knowing any machines and technicals.\n";
}

