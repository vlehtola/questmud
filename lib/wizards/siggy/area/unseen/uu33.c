inherit "room/room";
object archwiz;
reset(arg) {
    if(arg) return;
    add_exit("west","/wizards/siggy/area/unseen/uu32.c");
    add_exit("east","/wizards/siggy/area/unseen/uu34.c");
    add_exit("north","/wizards/siggy/area/unseen/uu31.c");
    add_exit("south","/wizards/siggy/area/unseen/uu35.c");
    set_not_out(3);
    short_desc = "A hall";
    long_desc = 
        "This is the mainhall of the third floor. There are three exits to archwizards'\n"
        + "rooms and one to the stairs. In east is Archwizard Harloft's workroom,\n" 
        + "in west is Archwizard Ywonha's and in south the oldest of the wizards,\n"
        + "Archwizard Jinxes. There are also beds meant for wizards' resting in the hall.\n";

    if(!archwiz) {
    archwiz = clone_object("/wizards/siggy/area/unseen/archwiz.c");
    move_object(archwiz, this_object());
    }
  }





