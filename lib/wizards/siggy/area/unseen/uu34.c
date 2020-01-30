inherit "room/room";
object harloft;
reset(arg) {
    if(arg) return;
    add_exit("west","/wizards/siggy/area/unseen/uu33.c");
    set_not_out(3);
    short_desc = "The workroom of Archwizard Harloft";
    long_desc = 
        "The room is full of books, and the trashcan is full of paper. Archwizard\n"
        + "Harloft is sitting on his chair and reading some ancient spellbook. You\n" 
        + "maybe you shouldn't disturb him, or he might get mad.\n";
    if(!harloft) {
    harloft = clone_object("/wizards/siggy/area/unseen/harloft.c");
    move_object(harloft, this_object());
    }
  }





