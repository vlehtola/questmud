inherit "room/room";
object guard;

reset(arg) {
   
    if(!present("guard")) {
      move_object(clone_object("/wizards/jenny/linnake/mosut/bodyguard.c"), this_object());
        }

        add_exit("north","/wizards/jenny/linnake/huoneet/throne2.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/way1.c");

        short_desc = "Entrance to the throne room";
        long_desc = "You are walking at the entrance of the throne room.\n"+
                    "There are huge statues everywhere around you and\n"+
                    "red carpet is laying on the floor.\n"; 

        set_not_out();
}
