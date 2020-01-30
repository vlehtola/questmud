inherit "room/room";
object tislaela;
reset(arg) {
    if(arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu22.c");
    add_exit("east","/wizards/siggy/area/unseen/uu26.c");
    set_not_out(3);
    short_desc = "Apprentice Tislaela's room";
    long_desc = 
        "This room is pink. Everywhere pink, the furnitures are pink, the clothes are\n"
        + "pink, the floor and roof are pink, the walls are pink. There are pink flowers\n" 
        + "on the table. Also there is a pink chest. This room looks weird. You feel\n"
        + "the magic in here. Your eyes go almost blind as you watch all the bright.\n"
        + "pink things.\n";
    if(!tislaela) {
    tislaela = clone_object("/wizards/siggy/area/unseen/tislaela");
    move_object(tislaela, this_object());
    }
  }
