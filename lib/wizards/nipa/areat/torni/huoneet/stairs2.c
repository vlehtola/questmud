inherit "room/room";

reset(arg) 
   {
        add_exit("down", "stairs1");
        add_exit("up", "stairs3.c");
        add_exit("north", "2lib2.c");
        add_exit("east", "2lib6.c");
        add_exit("south", "2lib8.c");
        add_exit("west", "2lib4.c");

   short_desc = "Wide stair looking plates floating in the spiral formation.";
    long_desc = "Here in the center of the tower floats thousands of plates in a spiral\n"+
                "formation. These plates are used as stairs. You have no idea what material\n"+ 
                "the plates are but you get the feeling that they have no weight at all but\n"+
                "still every step is stabile. With a peek up they allow access to every floor\n"+
                "in the tower. Faint blue light flashes every time you step on a plate.\n"+
                "The whole stairway is lit by a pillar of dim magenta light.\n";
               
        set_light(3);
}
