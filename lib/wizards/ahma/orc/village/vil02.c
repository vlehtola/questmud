inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/house02");
  add_exit("south", "/wizards/ahma/orc/village/vil01");
  add_exit("west", "/wizards/ahma/orc/village/vil10");
  add_exit("east", "/wizards/ahma/orc/village/vil03");
  short_desc = "Central part of Orgam street";
  long_desc = "########### The crappy road divides in three directions. In south lies the\n" + 
              "#|   H   |# entrance to the village. To west and east continues the Orgam\n" + 
              "#+---*---+# street. In north you can see a long, simply built house. There\n" + 
              "#    |    # are no doors in it, so it can be entered from here. In the bank\n" + 
              "########### of the road is lying huge amount of rubbish.\n";

  items = allocate(2);
  items[0] = "rubbish";
  items[1] = "Various garbage thrown away from the buildings located along this road.\n" + 
             "Two broken wooden chairs, one table, lots of crappy pieces of paper and\n" + 
             "one carpet. Nothing more, just trash";
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}