inherit "room/room";
reset(arg)  {
add_exit("southeast", "/wizards/aarrgh/pyramid/entrance");
add_exit("northwest", "/wizards/aarrgh/pyramid/pyra4");
            short_desc = "In a large hall";
            long_desc = "You are standing in a large hall.\n"+
                        "Walls are made of brownish yellow stones.\n"+
                        "You can hear some strange screaming...\n";


if(!present("mummy 2"))  {
move_object(clone_object("/wizards/aarrgh/pyramid/mon/mummy"), this_object());
move_object(clone_object("/wizards/aarrgh/pyramid/mon/mummy"), this_object());
                          }
}
