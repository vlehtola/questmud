inherit "room/room";
object guard;

reset(arg) {
   
    if(!present("guard")) {
      move_object(clone_object("/wizards/jenny/linnake/mosut/bodyguard.c"), this_object());
        }

        add_exit("west","/wizards/jenny/linnake/huoneet/throne5.c");
        add_exit("southwest","/wizards/jenny/linnake/huoneet/throne2.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/throne3.c");

        short_desc = "The throne room";
        long_desc = "Large, clean, expensively decorated room where\n"+
                    "king and queen usually give orders. There are\n"+
                    "loads of people running in and out all the time.\n"; 

        set_not_out();
}