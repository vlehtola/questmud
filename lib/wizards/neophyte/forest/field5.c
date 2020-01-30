inherit "room/room";
object rb1, rb2, mother;
reset (arg) {
if(!present("mother", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/mother"), this_object());
if(!present("white 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/rabbit"), this_object());
if(!present("white 2", this_object())) move_object(clone_object("/wizards/neophyte/forest/monst/rabbit"), this_object());
    if(arg) return;
        short_desc = "A center of the field";
        long_desc = "This is the center of the hay field. The hay is\n"+
                "ready for harvest which can be seen from the brown\n"+
                "colour of the hay. Small animals like moles, mice and\n"+
                "birds can be seen everywhere here. Ground is full of small holes\n"+
                "which seem to be dug by animals.\n";
    add_exit("north","/wizards/neophyte/forest/field6");
    add_exit("south","/wizards/neophyte/forest/field4");
    add_exit("east","/wizards/neophyte/forest/field8");
    add_exit("west","/wizards/neophyte/forest/field2");
            items = allocate(4);
                    items[0] = "hole";
                    items[1] = "One of the holes looks a lot bigger than others and in there is something shimmering";
                    items[2] = "holes";
                    items[3] = "One of the holes looks a lot bigger than others and in there is something shimmering";
}

init() {
        add_action("enter", "enter");
  ::init();
}

enter(str) {
  if(str == "hole") {
      write("You enter the large hole.\n");
      say(this_player()->query_name()+" enters a large hole.\n");
      move_object(this_player(),"/wizards/neophyte/forest/hole");
          command("look",this_player());
      return 1;
}
      write("Enter where?.\n");
      return 1;
    }

