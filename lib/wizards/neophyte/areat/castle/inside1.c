inherit "room/room";
object captain;

reset(arg) {
if(arg) return;
        if (!captain) {
                captain = clone_object("/wizards/neophyte/areat/castle/monst/captain");
                move_object(captain, this_object());
        }

        add_exit("north","inside2");
        add_exit("south","gateway");
        add_exit("northwest","rest1");
        add_exit("northeast","rest2");

        short_desc = "Inside the castle";
        long_desc = "A small corridors are leading to different directions, confusing the\n"+
                    "travellers sense of direction. The ground is full of dust and garbage,\n"+
                    "left by the indifferent travellers.\n";
        set_not_out(3);
}
