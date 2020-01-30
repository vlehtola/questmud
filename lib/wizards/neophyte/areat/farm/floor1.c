inherit "room/room";
int mouses;
reset (arg) {
    if(arg) return;
        short_desc = "Space under the floorboards";
        long_desc = "You stand in a crawlspace under the floorboards of the old\n"+
     "woman's house. The air is warm and damp and light filters down\n"+
     "through a hole in the floorboards.\n";
    set_not_out(1);
    set_light(2);
add_exit("north","wall5");
add_exit("south","wall1");
add_exit("west","wall3");
add_exit("east","wall7");
    mouses = 8;
}
reduce_number() {
        mouses -= 1;
if (mouses == 0 ) {
        call_out("mouses_killed", 2);
}
}
mouses_killed() {
        object lmouse;
        if (mouses == 0) {
              lmouse = clone_object("/wizards/neophyte/areat/farm/monst/lmouse");
              move_object(lmouse, this_object());
}
}
