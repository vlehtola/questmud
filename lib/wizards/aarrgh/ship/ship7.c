inherit "room/room";

reset(arg) {

add_exit("northwest", "/wizards/aarrgh/ship/ship6");
add_exit("southwest", "/wizards/aarrgh/ship/ship2");
short_desc = "At the front section of ship";
long_desc = "You are now at the front section of the ship. It seems\n"+
"to be higher than other parts of the ship. The deck is clean and well\n"+
"polished. There are some barrels left lying on the floor. You \n"+
"notice a compass next to the helm.\n";

items = allocate(8);
items[0]= "compass";
items [1]= "A small compass. You notice a small magnet attached to it";
items[2]= "barrels";
items[3]= "These barrels seems to be empty.\n";
}
init() {
    ::init();
add_action("remove", "remove");
}

remove(str)  {
    if(str != "magnet") return;
write("You remove the magnet from the compass.\n");
write("The compass starts pointing the right direction.\n");
say("As "+this_player()->query_name()+" removes the magnet, it" +
    "starts spinning rapidly!.\n");
write("You fixed the compass, Gongratulations!\n");
this_player()->set_quest("fix compass", 4);
return 1;
}
