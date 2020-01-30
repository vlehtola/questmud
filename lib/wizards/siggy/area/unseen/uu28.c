inherit "room/room";
object jehu;
reset(arg) {
    if(arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu26.c");
    add_exit("northeast","/wizards/siggy/area/unseen/uu27.c");
    set_not_out(3);
    short_desc = "Leader Jehu's room";
    long_desc = 
        "Uh, this is big. It is big enough for a huge fountain which is located in the\n"
        + "middle of the room. There's a large desk and behind it is the chair where Jehu\n" 
        + "usually sits. There are about 10 bookselves full of books. This is the place\n"
        + "where magic lives. Normally Jehu is wandering around the room podering some important.\n"
        + "questions.\n";
    if(!jehu) {
    jehu = clone_object("/wizards/siggy/area/unseen/jehu.c");
    move_object(jehu, this_object());
    }
  }




