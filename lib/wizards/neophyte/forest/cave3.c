inherit "room/room";
object bear;
reset (arg) {
    if(!present("bear", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/bear"), this_object());
    if(arg) return;
        short_desc = "A small cave";
        long_desc = "You are at the dark and moisty cave. The cave echoes all the noises\n"+
                    "which scares you a little. Water drops from the ceiling making awfull noise.\n"+
                    "The tunnel leads to northwest and southwest.\n";
    add_exit("northwest","/wizards/neophyte/forest/cave1");
    add_exit("southwest","/wizards/neophyte/forest/cave4");
    set_not_out(2);

}
