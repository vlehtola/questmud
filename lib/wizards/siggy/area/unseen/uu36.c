inherit "room/room";

reset(arg) {
    if (arg) return;
    make_jinx();
    set_light(1);
    short_desc = "The workroom of Archwizard Jinx";
    no_castle_flag = 0;
    long_desc = 
        "This is the room of the oldest of the wizards on the university. He is\n"
        + "Archwizard Jinx, and he is the only member who has been member from the\n" 
        + "creation of the tower. He came member when he was 21 and he is now 157\n";
        + "years old, so he has been member for 136 years, and that's quite much.\n";
    dest_dir =
        ({
        "/wizards/siggy/area/unseen/uu33.c", "north",
        "/wizards/siggy/area/unseen/roof.c", "up",
        });
}

query_light() {
    return 1;
}
/*
object jinx;

make_jinx() {
    if(!jinx) {
    jinx = clone_object("/wizards/siggy/area/unseen/jinx");
    move_object(jinx, this_object());
    }
  }
*/





