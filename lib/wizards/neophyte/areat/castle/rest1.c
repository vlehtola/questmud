inherit "room/room";
object guard;

reset(arg) {
        if(!guard) {
                guard = clone_object("/wizards/neophyte/areat/castle/monst/guard");
                move_object(guard, this_object());
        }
        if(arg) return;

        add_exit("southeast","inside1");

        short_desc = "resting place of guards";
        long_desc = "In here is couple of beds where guards can get some sleep\n"+
                    "after the duties. A small fireplace is build near the wall\n"+
                    "which gives warmth to sleeping guards.\n";
        set_not_out(3);

        items = allocate(2);
        items[0] = "fireplace";
        items[1] = "It is giving warmth to the sleeping guards";
}
