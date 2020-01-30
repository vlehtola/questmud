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
        long_desc = "This is a large hut made mostly of mud and hay although it's quite comfy\n"+
                    "because the floor is made of wood and the fireplace in the corner heat's\n"+
                    "the hut. It seems that this hut is owned by a farmer because the bookself\n"+
                    "is filled with books about farming.\n";
        set_not_out(1);
        set_light(1);
            items = allocate(4);
		            items[0] = "bookshelf";
		            items[1] = "The bookshelf is full of different type of books conserning about farming";
		            items[2] = "fireplace";
		            items[3] = "The fireplace is made of small roundish stones which are smuttish";
		add_exit("out", "room13");
        }
