inherit "room/room";

reset (arg) {

        add_exit("south","temple2");
    add_exit("north","temple4");
        short_desc = "Front of a chapel";
        long_desc = "Front of a chapel.On the both side of great hall is a balcony\n"+
                    "where are lots of people listening the mass. The walls are made\n"+
                    "oak balk's and there are couple of paintings hanging. Red mad is\n"+
                    "going on north where are the mass noises coming. A large skylight\n"+
                    "window with a ancient looking picture is on the ceiling.\n";
      items = allocate(4);
      items[0] = "balcony";
      items[1] = "In the balcony is lots of peoples listening the mass";
      items[2] = "walls";
      items[3] = "On the walls is pictures of gods and other historical events";
      set_not_out(3);
}
