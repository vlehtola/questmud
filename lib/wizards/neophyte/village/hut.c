inherit "room/room";
object goblin,goblin2;

reset(arg) {
        if(!goblin) {
                goblin = clone_object("/wizards/neophyte/village/monst/goblin1");
                move_object(goblin, this_object());
        }
        if(!goblin2) {
                goblin = clone_object("/wizards/neophyte/village/monst/goblin2");
                move_object(goblin, this_object());
        }
        if(arg) return;
        short_desc = "A small and dark hut";
        long_desc = read_file("/wizards/neophyte/village/hutdesc.c");
        set_not_out(1);
        set_light(0);
            items = allocate(6);
		            items[0] = "log";
		            items[1] = "This log is actualy a oak tree and it is supporting the whole hut to stand";
		            items[2] = "ground";
		            items[3] = "The ground is full of dirt and small piles of rubbish";
		            items[4] = "furs";
                    items[5] = "The furs are maybe a dog or cat furs.";

        }
