inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/catb4");
  add_exit("west","wizards/nalle/jerusalem/cata3");
  add_exit("east","wizards/nalle/jerusalem/cata5");
  add_exit("out","wizards/nalle/jerusalem/chrb2");
  short_desc = "The Church of the Holy Sepulchre";
  long_desc =
"You have entered a simple cathedral, made of stone. It represents\n" +
"no definate style, but seems to have predicted the coming of the \n" +
"gothic style, when it was built. A moist smell of stone and wood\n" +
"hovers around your nose. A corridor leads to the altar to your north\n" +
"and there is a room to your east and west.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/map");
   return 1;
}

