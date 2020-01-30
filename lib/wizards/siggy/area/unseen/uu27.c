inherit "room/room";
object alister;
reset(arg) {
    if (arg) return;
    add_exit("southwest","/wizards/siggy/area/unseen/uu28.c");
    add_exit("north","/wizards/siggy/area/unseen/uu24.c");
    add_exit("west","/wizards/siggy/area/unseen/uu26.c");
    set_not_out(3);
    short_desc = "Apprentice Alister's room";
    long_desc = 
        "Alister's room is quite normal, well the most normal room in this level you\n"
        + "think, but there's really nothing normal in here. There are some mirrors and\n" 
        + "you sense that she likes to watch herself, wow. And you're not suprised as you\n"
        + "see a picture of her. She is very good looking young woman. And you're in love.\n";
    if(!alister) {
    alister = clone_object("/wizards/siggy/area/unseen/alister");
    move_object(alister, this_object());
    }
  }





