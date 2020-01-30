inherit "room/room";

reset(arg) {
	set_light(3);
        short_desc = "Entrance to the dark dweller caves";
        long_desc = "The cave is spacious but cold. Few rays of light\n"+
              "come from outside giving some light. Puddles can be\n"+
               "seen here and there. Sound of a dripping water echoes\n"+
		"from the darkness.\n";
        add_exit("south", "out: 207 125");
	add_exit("north", "/wizards/rimber/cave/room2.c");
 set_not_out(1);
}
