inherit "room/room";
    object guard;
    object guard1; 
    reset(arg) {
    if(arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu3.c");
    add_exit("out","/wizards/siggy/area/unseen/roof.c");
    set_not_out(3);
    short_desc = "The Gates of Unseen University";
    long_desc = 
        "This is entrance to a huge building which is known as the Unseen University.\n"
        + "The gates are huge and you're surrounded by beatiful landscape, dense\n"
        + "forest and fresh air. Tower you see ahead is mostly made of white bricks\n"
        + "and the windows aren't made of usual glass, the material might be some kind of\n"
        + "crystal. The gates are guarded by strong looking guards wearing only robes.\n" 
        + "Gates are always open for visitors, says the sign.\n";

   items = allocate(2);
   items[0] = "sign";
   items[1] = "A wooden sign saying 'Welcome to the Unseen University'";
    
    if(!guard) {
    guard = clone_object("/wizards/siggy/area/unseen/guard.c");
    move_object(guard, this_object());
    } 
    if(!guard1) {
    guard1 = clone_object("/wizards/siggy/area/unseen/guard.c");
    move_object(guard1, this_object());
    } 
}


