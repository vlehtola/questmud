inherit "room/room";

reset(arg)  {


            add_exit("southwest", "/wizards/aarrgh/nyxi/path4");
            add_exit("west", "/wizards/aarrgh/nyxi/mist");
            add_exit("gates", "/wizards/aarrgh/nyxi/volcano1");
short_desc= "In front of huge stone gates";
long_desc = "Enormous stone gates that lead inside the volcano open in the front.\n"
	    "The left gate is open so someone could get through it. Exit leading west\n"
            "side of the Volcano can be noticed. A strange mist is floating there.\n";
  items = allocate(4);
  items[0] = "gates";
  items[1] = "Someone has left the other side of the gate open";



}

