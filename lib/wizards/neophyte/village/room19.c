inherit "room/room";
object goblin,goblin1;
reset(arg) {
	        if(!goblin) {
	                goblin = clone_object("/wizards/neophyte/village/monst/goblinchild");
	                move_object(goblin, this_object());
	        }
	        if(!goblin1) {
	                goblin1 = clone_object("/wizards/neophyte/village/monst/goblinchild");
	                move_object(goblin1, this_object());
	        }
        if(arg) return;
        short_desc = "A shady shore";
        long_desc = "A shady shore surrounded by water. A dozens of bulrushes are growing\n"+
                    "in the water. A small ferry is floating on the water center of lake.\n"+
                    "The ground is full of rubbish and small round stones, which have water\n"+
                    "shaped in centries. Occasionally fishes can be seen jumping out of the\n"+
                    "water leaving trails on the water.\n";
        add_exit("southwest", "room18");
        add_exit("southeast", "room11");
        set_water(2);
        }
