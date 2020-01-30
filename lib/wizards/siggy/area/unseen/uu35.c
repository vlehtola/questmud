inherit "room/room";
object jinx;
reset(arg) {
    if(arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu33.c");
    add_exit("up","/wizards/siggy/area/unseen/roof.c");
    set_not_out(3);
    short_desc = "The workroom of Archwizard Jinx";
    long_desc = 
        "This is the room of the oldest of the wizards on the university. He is\n"
        + "Archwizard Jinx, and he is the only member who has been member since the\n" 
        + "creation of the tower. He came member when he was just a kid. There is a\n"
        + "large crystal window which it's covered with light purple curtains. You\n" 
        + "can see few chests and bookselves around the room. There is a writing desk\n"
        + "and a chair.\n"; 
    if(!jinx) {
    jinx = clone_object("/wizards/siggy/area/unseen/jinx.c");
    move_object(jinx, this_object());
    }
  }





