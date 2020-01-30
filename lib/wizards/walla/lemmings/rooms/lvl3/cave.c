inherit "room/outroom";

start() {
  mapfile = "/wizards/walla/lemmings/rooms/lvl3/virtual_map";
  short_desc = "In a huge cavern deep underground";
  long_desc = "You are walking through a huge cavern, that has virtually\n"+
              "no roof. The ground is made of rock, that has been polished\n"+
              "with some sort of stones, and it's perfectly smooth.\n"+
              "The cave seems to have no end to it, and you really are \n"+
              "amazed at the craftsmanship of the place\n";
}
reset() {
  ::reset();
  if(!present("animal") && !random(10)) {
    move_object(clone_object("/wizards/walla/lemmings/mobs/blocker.c"), this_object());
  }
  if(!present("animal2") && !random(10)) {
    move_object(clone_object("/wizards/walla/lemmings/mobs/walker.c"), this_object());
  }
  if(!present("animal3") && !random(10)) {
    move_object(clone_object("/wizards/walla/lemmings/mobs/builder.c"), this_object());
  }
  if(!present("animal4") && !random(10)) {
    move_object(clone_object("/wizards/walla/lemmings/mobs/digger.c"), this_object());
  }
  if(!present("animal5") && !random(10)) {
    move_object(clone_object("/wizards/walla/lemmings/mobs/climber.c"), this_object());
  }

}
