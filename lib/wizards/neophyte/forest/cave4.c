inherit "room/room";
object bear;
reset (arg) {
    if(!present("bear", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/bear"), this_object());
    if(arg) return;
        short_desc = "A small cave";
        long_desc = "The cave is getting smaller and narrower, difference between\n"+
                    "the previous tunnels and this tunnel is conspicuous.\n"+
                    "There are lots of different bones of fishes and animals on the ground.\n";
    add_exit("northwest","/wizards/neophyte/forest/cave2");
    add_exit("northeast","/wizards/neophyte/forest/cave3");
    add_exit("south","/wizards/neophyte/forest/cave5");
    set_not_out(1);
                items = allocate(2);
                            items[0] = "bones";
                            items[1] = "They are bones of small animals and fishes. Looks like bear has a good appetite\n"+
                                       "because the ground is full of them";
}
