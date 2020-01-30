inherit "room/room";
object fisher1, fisher2;
reset (arg) {
    if(!present("fisher 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/fisher"), this_object());
    if(!present("fisher 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/fisher"), this_object());
    if(arg) return;
        short_desc = "Beach";
        long_desc = "The gentle, cooling wind which blow in here makes the beach very\n"+
                "nice. The sand is gold-coloured and feels quite nice under\n"+
                "your feet. Birds are flying in the skies and they\n"+
                "are singing so beautifully that you would listen the singing\n"+
                "for hours.\n";
    add_exit("north","/wizards/neophyte/forest/room11");
    add_exit("west","/wizards/neophyte/forest/room13");
}
