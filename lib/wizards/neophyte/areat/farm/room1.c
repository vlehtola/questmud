inherit "room/room";
reset (arg) {
    if(arg) return;
        short_desc = "Entrance to the farm";
        long_desc = "This looks like a typical entrance to farm. Logs are attached to\n"+
                    "farms fence and muddy road goes inside the courtyard. There are\n"+
                    "small pools of dirty water, lots of horses footsteps and wagon\n"+
                    "trails on the road. Lots of apple trees grown in here with different\n"+
                    "coloured apples on them.\n";
add_exit("east","room2");
    add_exit("out", "outmap: 142 89");
items = allocate(6);
items[0] = "gate";
items[1] = "A gate made of logs is attached to fence";
items[2] = "road";
items[3] = "Little muddy road that goes inside the countyard, pools of water\n"+
           "are formed on the surface of road";
items[4] = "trees";
items[5] = "An apple tree with different coloured apples on the branches";

}

