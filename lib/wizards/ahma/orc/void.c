inherit "room/room";

reset(arg) {
  short_desc = "Void room";
  long_desc = "Nothing here.\n";
}

moveboy() {
  if(present("boy", this_object())) {
    move_object(present("boy", this_object()), "/wizards/ahma/orc/forest/for11");
  }
}