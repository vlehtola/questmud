inherit "room/room";
object ywonha;
reset(arg) {
    if(arg) return;
    add_exit("east","/wizards/siggy/area/unseen/uu33.c");
    set_not_out(3);
    short_desc = "The workroom of Archwizard Ywonha";
    long_desc = 
        "This is the room of the highest woman wizard in Unseen University and maybe\n"
        + "the most powerful woman in the whole world. This room is very luxurious. There\n" 
        + "is a statue made of diamond. You can't even imagine how rich she is. You can\n"
        + "recognice the statue, that it describes herself. There is lots of other.\n"
        + "extravagant things.\n";

    items = allocate(2);
    items[0] = "statue";
    items[1] = "A beatiful diamond statue describing its owner ArchWizard Ywonha.";
    
    if(!ywonha) {
    ywonha = clone_object("/wizards/siggy/area/unseen/ywonha.c");
    move_object(ywonha, this_object());
    }
  }





