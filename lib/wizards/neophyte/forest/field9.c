inherit "room/room";
object rb1, rb2;
reset (arg) {
if(!present("rabbit 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/rabbit"), this_object());
if(!present("rabbit 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/rabbit"), this_object());
    if(arg) return;
        short_desc = "A southeast corner of the field";
        long_desc = read_file("/wizards/neophyte/forest/fieldesc.c");
    add_exit("north","/wizards/neophyte/forest/field8");
    add_exit("west","/wizards/neophyte/forest/field4");
            items = allocate(3);
                    items[0] = "hay";
                    items[1] = "It looks rather old because they are all brown,";
}
