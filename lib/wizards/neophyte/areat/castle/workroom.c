inherit "room/room";
object pidur,zelcy;

reset(arg) {
        if(arg) return;
        if (!pidur) {
                pidur = clone_object("/wizards/neophyte/areat/castle/monst/pidur");
                move_object(pidur, this_object());
        }
                if (!zelcy) {
                                zelcy = clone_object("/wizards/neophyte/areat/castle/monst/zelcy");
                                move_object(zelcy, this_object());
                        }
        add_exit("down","hall");
short_desc = "Inside Pidurs workroom";
long_desc = "You have managed to reach the private workroom of Pidur, the king of the\n"+
            "castle. It's a rather small and not very much furnished room, usual looking\n"+
            "workroom. A cosy looking golden throne, made for the king, is in the middle\n"+
            "of the workroom.\n";
set_not_out(1);
    items = allocate(2);
    items[0] = "throne";
    items[1] = "It's made of pure gold";
property = allocate(2);
property[0] = "no_summon";
property[1] = "no_tele";
}
