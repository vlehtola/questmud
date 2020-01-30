inherit "room/room";
object guard;

reset(arg) {
        if(!guard) {
                guard = clone_object("/wizards/neophyte/areat/castle/monst/guard");
                move_object(guard, this_object());
        }
        if(arg) return;

        add_exit("down","gtower6");

        short_desc = "In the guard tower";
        long_desc = "After a long climbing on ladders, you have finally arrive in the tower.\n"+
                    "In here is a small window which have good view of the near valley.\n";
        set_not_out(2);

}
