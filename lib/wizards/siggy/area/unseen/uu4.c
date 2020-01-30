inherit "room/room";
object cook;
reset(arg) {
    if(arg) return;
    add_exit("west","/wizards/siggy/area/unseen/uu3.c");
    add_exit("north","/wizards/siggy/area/unseen/uu7.c");
    add_exit("southwest","/wizards/siggy/area/unseen/uu1.c");
    set_not_out(3);
    short_desc = "Kitchen of University";
    long_desc = 
        "This is the kitchen of this university. Aaaah, it smells so good, fresh bread\n"
        + "pancake, Yummy. This is narrow room, and you feel harassing. From north\n"
        + "comes a horrible sound. The bar is located to north. The wizards are enjoying\n"
        + "drinks in the bar. Cook shouts something to you about having a beer.\n";

    if(!cook) {
    cook = clone_object("/wizards/siggy/area/unseen/cook.c");
    move_object(cook, this_object());
    }
}

