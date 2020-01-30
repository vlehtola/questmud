inherit "room/room";

reset(arg) {
    if (arg) return;
    make_rincewind();
    make_luggage();
    set_light(1);
    short_desc = "Apprentice Rincewind's room";
    no_castle_flag = 0;
    long_desc = 
        "This is very slotty and small room. There is only a bed, closet, chair\n"
        + "and a luggage. The bed is quite cruel, it is made of wood and nothing soft\n" 
        + "between your back and the wooden bed. The closet is small and you can\n"
        + "keep only clothes and few books in there. The luggage is a living creature.\n";
    dest_dir =
        ({
        "/wizards/siggy/area/unseen/uu21.c", "northeast",
        "/wizards/siggy/area/unseen/uu25.c", "south",
        "/wizards/siggy/area/unseen/uu23.c", "east",
        });
}

query_light() {
    return 1;
}

object rincewind;
object luggage;

make_rincewind() {
    if(!rincewind) {
    rincewind = clone_object("/wizards/siggy/area/unseen/rincewind");
    move_object(rincewind, this_object());
    }
}
make_luggage() {
    if(!luggage) {
    luggage = clone_object("/wizards/siggy/area/unseen/luggage");
    move_object(luggage, this_object());
    }
}

}




