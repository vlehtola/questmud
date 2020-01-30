inherit "room/room";

reset(arg) 
   {
        add_exit("stairs","stairs2.c");
        add_exit("north", "lib2.c");
        add_exit("east", "lib6.c");
        add_exit("south", "lib8.c");
        add_exit("west", "lib4.c");

   short_desc = "Wide stair looking plates floating in the spiral formation.";
    long_desc = "Here in the center of the tower floats thousands of plates in a spiral\n"+
               "formation. With quick inspection these plates are used as stairs.\n"+ 
               "You have no idea what material the plates are but you get the feeling that\n"+
               "they have no weight at all but still every step is stabile. With a peek\n"+
               "up they allow access to every floor in the tower. Faint blue light\n"+
               "flashes every time you step on a plate. The whole stairway is lit by a\n"+ 
               "pillar of dim magenta ligh. The light is somehow coming through the floor.\n";

        set_light(3);
  
        items = allocate(2);
        items[0] = "light";
        items[1] = "Mysterious magenta light is coming through the floor. Maybe there is something under the first floor.";
}
