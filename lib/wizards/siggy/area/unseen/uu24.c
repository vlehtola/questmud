inherit "room/room";
object elshwitch;
reset(arg) {
    if (arg) return;
    add_exit("northwest","/wizards/siggy/area/unseen/uu21.c");
    add_exit("south","/wizards/siggy/area/unseen/uu27.c");
    add_exit("west","/wizards/siggy/area/unseen/uu23.c");
    set_not_out(3);
    short_desc = "Apprentice Elshwitch's room";
    long_desc = 
        "This is so different compared to Rincewind's room. This is clean and a lot\n"
        + "bigger. It almost looks like a room of a normal person. You can see trees from\n" 
        + "from the window and a crow eating worm.\n";

    if(!elshwitch) {
    elshwitch = clone_object("/wizards/siggy/area/unseen/elshwitch.c");
    move_object(elshwitch, this_object());
    }
  }





