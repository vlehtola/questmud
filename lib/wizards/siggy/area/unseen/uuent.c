inherit "room/room";

reset(arg) {
    if (arg) return;
    make_guard();
    make_guard1();
    set_light(1);
    short_desc = "The Gates of Unseen University";
    no_castle_flag = 0;
    long_desc = 
        "This is the entrance to a great univerity called the Unseen University\n"
        + "The gates are huge, about 15 feet. You can see a huge hall ahead, and\n"
        + "lots of wizards wandering in a hurry in the hall. This is like a tower.\n"
        + "There is 4 floors, and this is the first. You can see a sign 'Unseen University'.\n"
        + "You can almost feel the magic in this place.\n";
    dest_dir =
        ({
        "/wizards/siggy/area/unseen/uu3.c", "north",
        "/wizards/siggy/area/unseen/pois.c", "out",
        });
}

query_light() {
    return 1;
}

object guard;
object guard1;

make_guard() {
    if(!guard) {
    guard = clone_object("/wizards/siggy/area/unseen/guard");
    move_object(guard, this_object());
    }
}
make_guard1() {
    if(!guard1) {
    guard1 = clone_object("/wizards/siggy/area/unseen/guard");
    move_object(guard1, this_object());
    }
}





