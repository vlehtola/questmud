inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("down", "/world/city/adventurers_hall.c");

move_object(clone_object("/wizards/kaappi/questplaque.c"), this_object());

short_desc = "A quest plaque room";
long_desc = "The room is extremely wide, walls have been masoned with\n"+
           "bricks by extreme accuracy. The walls have been lit excellently\n"+
           "with chandeliers, ephasizing the details in the room. The walls\n"+
           "are full of painted pictures of several different locations around\n"+
           "the world. There is a pedestal on the longitudinal end of the room\n"+
           "which stands in front of a plaque.\n";

set_light(3);
}
