inherit "room/room";
reset(arg) {
    if (arg) return;
    add_exit("west","/wizards/siggy/area/unseen/uu5.c");
    add_exit("east","/wizards/siggy/area/unseen/uu7.c");
    add_exit("south","/wizards/siggy/area/unseen/uu3.c");
    add_exit("north","/wizards/siggy/area/unseen/uu8.c");
    set_not_out(3);
    short_desc = "Hallway leading to the stairs";
    long_desc = 
        "This part of hallway is like a mirror picture of the southern hallway. The same\n"
        + "pictures of wizard that are covering the other first hallway are covering these\n"
        + "walls also. The biggest picture is a portrait of the Archwizard Jinx. You hear\n" 
        + "awful noice coming from the east.\n";
}




