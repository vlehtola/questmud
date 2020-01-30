inherit "room/room";
object guard;

reset(arg) {
   
    if(!present("guard")) {
      move_object(clone_object("/wizards/jenny/linnake/mosut/hallguard.c"), this_object());
        }

        add_exit("north","/wizards/jenny/linnake/huoneet/sisaovi.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/hall19.c");

        short_desc = "You are walking in a hallway";
        long_desc = "You are walking in a hallway and you see stairs leading\n"+
                    "up in north and a big clean looking hall in south.\n"+
                    "You hear some chambermaids giggling somewhere near.\n";

        set_not_out();
}
