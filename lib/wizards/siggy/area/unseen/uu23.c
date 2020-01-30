inherit "room/room";
object apprentice;
object apprentice1;
reset(arg) {
    if (arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu21.c");
    add_exit("south","/wizards/siggy/area/unseen/uu26.c");
    add_exit("east","/wizards/siggy/area/unseen/uu24.c");
    add_exit("west","/wizards/siggy/area/unseen/uu22.c");
    set_not_out(3);
    short_desc = "A hall";
    long_desc = 
        "This is colorful but bore looking hall. There are color all the way between\n"
        + "black and white, like red pillars and blue signs and so on. There are three\n" 
        + "signs pointing in different directions. You can see a paper nailed in the eastern wall.\n";
    if(!apprentice) {
    apprentice = clone_object("/wizards/siggy/area/unseen/wizap1.c");
    move_object(apprentice, this_object());
    }
    if(!apprentice1) {
    apprentice1 = clone_object("/wizards/siggy/area/unseen/wizap1.c");
    move_object(apprentice1, this_object());
    }
}




