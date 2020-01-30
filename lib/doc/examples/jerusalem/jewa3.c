inherit "room/room";

reset(arg) {
add_exit("north","wizards/nalle/jerusalem/jewb3");
add_exit("west","wizards/nalle/jerusalem/jewa2");
  short_desc = "Southwestern part of the Jewish Quarter";
  long_desc =
"You are by the southern wall of Jerusalem, in the south-\n" +
"western part of the Jewish quarter. There are not many\n" +
"people here except those standing by the wall, inserting\n" +
"bits of paper in the cracks between the rocks of the wall.\n" +
"Your surroundings are somewhat clean and well kept. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/jmap");
   return 1;
}
