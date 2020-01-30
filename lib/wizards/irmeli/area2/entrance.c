inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "Entrance to the old mine";
    long_desc = "A hill rises from the middle of the open plains. There is a pithead to the old\n"+ 
                  "mine on the hillside. In former times that pithead was used as an entrance to\n"+
                  "the old mine. It was some short of mine disaster which ended the minings in\n"+
                  "here. The mine has been abandoned for years.\n";

    add_exit("south", "out: 61 78");
    add_exit("enter", "wizards/irmeli/area2/ruum1.c");
}
