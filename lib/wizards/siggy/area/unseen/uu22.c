inherit "room/room";
object rincewind;
object luggage;
reset(arg) {
    if (arg) return;
    add_exit("northeast","/wizards/siggy/area/unseen/uu21.c");
    add_exit("south","/wizards/siggy/area/unseen/uu25.c");
    add_exit("east","/wizards/siggy/area/unseen/uu23.c");
    set_not_out(3);
    short_desc = "Apprentice Rincewind's room";
    long_desc = 
        "This is very slotty and small room. There is only a bed, closet, chair\n"
        + "and a luggage. The bed is quite cruel, it is made of wood and nothing soft\n" 
        + "between your back and the wooden bed. The closet is small and you can\n"
        + "keep only clothes and few books in there. The luggage seems to be a living creature.\n";
    if(!rincewind) {
    rincewind = clone_object("/wizards/siggy/area/unseen/rincewind.c");
    move_object(rincewind, this_object());
    }
    if(!luggage) {
    luggage = clone_object("/wizards/siggy/area/unseen/luggage.c");
    move_object(luggage, this_object());
    }
}






