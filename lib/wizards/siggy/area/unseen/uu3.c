inherit "room/room";
object monster;
reset(arg) {
if(!monster) {
monster = clone_object("/wizards/siggy/area/unseen/wizap1.c");
move_object(monster, this_object());
}
    if (arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu6.c");
    add_exit("south","/wizards/siggy/area/unseen/uu1.c");
    add_exit("west","/wizards/siggy/area/unseen/uu2.c");
    add_exit("east","/wizards/siggy/area/unseen/uu4.c");
    set_not_out(3);
    short_desc = "Unseen University's main hall";
    long_desc = 
        "The first main hall of the university. You can see pillars all over the place.\n"
        + "Never in your life you have seen such a beatiful hall. The pillars are red\n"
        + "and made of marble and must be holding this building so it wouldn't collapse. The\n"
        + "floor is also made of marble and it's very slippery. Walls on your west and eastside\n"
        + "are full of pictures. A great aroma arrives from east.\n";
}





