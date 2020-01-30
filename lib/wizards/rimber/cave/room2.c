inherit "room/room";

reset(arg) {
	set_light(3);
	short_desc = "Dark and damp cavern";
        long_desc = "The cave is spacious but cold. Few rays of light\n"+
          "come from outside giving some light. Puddles can be\n"+
        "seen here and there. Sound of a dripping water echoes\n"+
          "from the darkness.\n";
	add_exit("south", "/wizards/rimber/cave/room1.c");
	add_exit("north", "/wizards/rimber/cave/room4.c");
 set_not_out(1);
}
