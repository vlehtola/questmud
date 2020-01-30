inherit "room/room";
reset(arg) {
    if(arg) return;
    add_exit("down","/wizards/siggy/area/unseen/uu21.c");
    add_exit("south","/wizards/siggy/area/unseen/uu33.c");
    set_not_out(3);
    short_desc = "Stairs going down";
    long_desc = 
        "This is the last floor of the tower. You can hear a screaming noise above\n"
        + "you. It comes from the roof. The stairs are not as good condition as\n" 
        + "they were in first and second floor. In here lives all archwizards. You can\n"
        + "sense the weird feeling almost like the magic floating here would be touching\n"
        + "you.\n";
}




