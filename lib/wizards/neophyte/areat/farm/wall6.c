inherit "room/room";
object mouse;
reset (arg) {
    if(arg) return;
      if (!mouse) {
              mouse = clone_object("/wizards/neophyte/areat/farm/monst/mouse");
              move_object(mouse, this_object());
        }
        short_desc = "Inside the wall";
        long_desc = read_file("/wizards/neophyte/areat/farm/walldesc.c");
    set_not_out(1);
    set_light(2);
    items = allocate(4);
        items[0] = "holes";
        items[1] = "Small holes that are gnawed inside the wall boards";
        items[2] = "tunnels";
        items[3] = "Small tunnels that are gnawed inside the wall boards";
        property = allocate(1);
    property[0] = "no_summon";
add_exit("south","wall7");
add_exit("west","wall5");
}

