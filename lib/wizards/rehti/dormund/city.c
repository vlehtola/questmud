inherit "room/room";

reset(arg) {
    add_exit("north","/wizards/rehti/dormund/cs");
    add_exit("east","/wizards/rehti/dormund/se");
    add_exit("west","/wizards/rehti/dormund/sw");
    add_exit("south","/wizards/rehti/dormund/entrance");
    short_desc = "Dormund city entrance";
    long_desc = "It seems that this fortress is so well protected that children are able to run around\n" +
                "and play their games without any fear. There is no any sign of guards.\n"+
                "But these are not times of war, which gives more reason for these people to be happy.\n"+
                "Brisk wind blows through open gate. Central square is to the north.\n";
} 