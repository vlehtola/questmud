inherit "room/room";

reset(arg) {
add_exit("east","wizards/nalle/jerusalem/vd1");
add_exit("west","out: 88 105");
  short_desc = "Jaffa gate";
  long_desc =
"This is the western gate of the old town of Jerusalem,\n"+
"and thus a gateway into a town with a striving economy\n"+
"and cultural resources that are challenged by very few\n"+
"other towns indeed. The Via Dolorosa road lies to your\n"+
"east, and the countryside to your west.\n";
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
