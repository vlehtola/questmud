inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil22");
  add_exit("south", "/wizards/ahma/orc/village/sq05");
  add_exit("west", "/wizards/ahma/orc/village/vil18");
  add_exit("east", "/wizards/ahma/orc/village/vil09");
  short_desc = "Central part of Sralk street";
  long_desc = "########### Sralk street continues to west and east. A crossing-road between\n" + 
              "#H   |   H# Nuft and Sralk streets leads north, where the Nuft street is. An\n" + 
              "#+---*---+# old-looking wooden bridge is leading to south towards the village\n" + 
              "#| ##### |# square. An advertisement and a poster are nailed on the side of a\n" + 
              "########### wooden pole which is standing by the bridge.\n";

  items = allocate(6);
  items[0] = "pole";
  items[1] = "An ordinary-looking wooden pole. On the pole can be nailed various\n" + 
             "advertisements and posters regarding almost anything";
  items[2] = "poster";
  items[3] = "There seems to be a picture of ugly Dwarf and an X drwan on him. Some\n" + 
             "writing has been made under it: 'Join into our forces today to fight against\n" + 
             "these low-life bastards!\n" +
             "- Ner'gah, the commander of Orchish army";
  items[4] = "advertisement";
  items[5] = "When visiting the village square, visit also us! You can make real discoveries.\n" + 
             "- The owner of Naglah's artifact shop";
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}
