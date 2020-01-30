inherit "room/room";

reset(arg) {
add_exit("north","wizards/nalle/jerusalem/elattar4");
add_exit("south","out: 89 106");
  short_desc = "Zion gate";
  long_desc =
"This is the southern gate of the city of Jerusalem,\n" +
"also known as the Zion Gate. The El Attar road is to\n" +
"your north and it seems pretty crowded. People seem\n" +
"to be hurring to the marketplaces to sell their animals\n" +
"and other goods. \n";
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
