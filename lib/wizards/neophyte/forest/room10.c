inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "In the lake";
        long_desc = "The gentle, cooling wind which blow in here makes the beach very\n"+
                "nice. The sand is gold-coloured and feels quite nice when\n"+
                "walking on it. Birds are flying in the skies and they\n"+
                "are singing so beautifully that you would listen the singing\n"+
                "for hours.\n";
    add_exit("west","/wizards/neophyte/forest/room9");
    add_exit("east","/wizards/neophyte/forest/room11");
}
