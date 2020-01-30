inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("north", "/wizards/aarrgh/nyxi/path4");
            add_exit("south", "/wizards/aarrgh/nyxi/path2");
            short_desc = "Path leading to the volcano";
          long_desc =  "This path leads to the volcano. Corpses of some foolish adventurers\n"
			 "lie on the ground, mutilated. Serious fight have been fought here and\n"
			 "dismembered parts of the losing ones can be seen on the ground.\n"
			 "Adventuring heroes should prepare themselves for the coming battle.\n"
                         "The Volcano lies ahead.\n";

items = allocate(4);
  items[0] = "corpses";
  items[1] = "These corpses has been torn apart by hellhounds. Everything is covered with blood";



if(!present("hound")) {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/hound"),
this_object());
}
if(!present("hound 2")) {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/hound"),
this_object());
}
}

