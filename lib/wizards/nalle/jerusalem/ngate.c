inherit "room/room";

reset(arg) {
add_exit("south","wizards/nalle/jerusalem/elattar1");
add_exit("north","out: 89 104");
  short_desc = "Harod's gate";
  long_desc =
"This is the northern gate of the city of Jerusalem,\n" +
"which is also know as 'The Eternal City' because of\n" +
"the miraculous happenings that have happened in it in\n" +
"the past. People walk in and out of the gates in great\n" +
"numbers. \n";
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

