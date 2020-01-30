inherit "room/room";
object bear;
reset (arg) {
    if(!present("bear", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/grizzly"), this_object());
    if(arg) return;
        short_desc = "A small cave";
        long_desc = "This is the bottom of the cave. Small drops of water flow from the ceiling\n"+
                    "and some leaves cover the ground. This looks like a typical bear\n"+
                    "nest.\n";
    add_exit("north","/wizards/neophyte/forest/cave4");
    set_not_out(1);
                items = allocate(2);
                            items[0] = "leaves";
                            items[1] = "The leaves are nicely placed on the ground, making a perfect resting place";
}
