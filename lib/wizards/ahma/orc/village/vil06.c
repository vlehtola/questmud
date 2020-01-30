inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/sq11");
  add_exit("south", "/wizards/ahma/orc/village/house02");
  add_exit("west", "/wizards/ahma/orc/village/vil12");
  add_exit("east", "/wizards/ahma/orc/village/vil05");
  short_desc = "Central part of Galor street";
  long_desc = "########### The Galor street continues in west and east from here.\n" + 
              "#| ##### |# An old-looking wooden bridge is leading over the moat to north\n" + 
              "#+---*---+# where the village square is. In south can be seen a simply built\n" + 
              "#|   H   |# house. The doorway is open, so it can be entered from here. A\n" + 
              "########### poster is nailed on the pole located in the roadside.\n";

  items = allocate(4);
  items[0] = "pole";
  items[1] = "An ordinary-looking wooden pole. On the pole can be nailed various\n" + 
             "advertisements and posters regarding almost anything";
  items[2] = "poster";
  items[3] = "There seems to be a picture of an ugly Dwarf and an huge X drawn on him.\n" + 
             "Something has been written under it: 'Join into our forces today to fight\n" + 
             "against these low-life bastards!\n" +
             "- Ner'gah, the commander of Orcish army";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/walker02"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

childdead() {
  mob--;
}