inherit "room/room";

reset(arg) {

        add_exit("south","/wizards/jenny/linnake/huoneet/kaytava3.c");
        add_exit("up","/wizards/jenny/linnake/huoneet/ylakerta1.c");
        short_desc = "You are walking in a hallway";
        long_desc = "You are walking in a hallway and you see stairs leading\n"+
                    "up next to you and a big clean looking hall in south.\n"+
                    "You hear some chambermaids giggling somewhere near.\n";

        set_not_out();
}
