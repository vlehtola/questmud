inherit "room/room";
reset (arg) {
        if (arg) {return;}

    add_exit("north","temple3");
    add_exit("south","temple1");
        add_exit("west","temple5");
        add_exit("east","temple25");
        short_desc = "Inside the temple";
    long_desc = "The crossing of the corridors. On the walls are two paintings,\n"+
                "the first painting is presenting a ceremony of light, where the\n"+
                "sun is summoned after moon has lower. The red mad is going on to\n"+
                "north corridor, where can be heard a silent praying.\n";
      items = allocate(6);
      items[0] = "paintings";
      items[1] = "A large painting which is framed on the wall";
      items[2] = "mat";
      items[3] = "It is layed on the floor and going to the north";
      items[4] = "crossing";
      items[5] = "You are standing on the crossing of corridors";
      set_not_out(3);
      set_light(2);
}
