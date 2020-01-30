inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil12");
  add_exit("west", "/wizards/ahma/orc/village/vil11");
  add_exit("east", "/wizards/ahma/orc/village/vil02");
  short_desc = "Intersection between Orgam and Zark streets";
  long_desc = "########### The Orgam street continues to west and east. The Zark street leads\n" + 
              "#H   |   H# to north. The southern bank of the street is decorated with green\n" + 
              "#+---*---+# bushes. Behind the bushes you can see the darkening, thick forest\n" + 
              "#        |# from where you came through into this village. Really good smell\n" + 
              "########### is floating from somewhere inside the bushes.\n";

  items = allocate(2);
  items[0] = "bush";
  items[1] = "As you look inside the bush where the nice aroma is floating, you quickly\n" + 
             "find out what the source of it is. There seems to be a half-eaten deer pie\n" + 
             "in the bush, a juicy aroma of deer meat is emitting from it. No obvious\n" + 
             "reason is seen why someone would have discarded such a delicious-looking\n" + 
             "piece of pie, though you are not intending to touch it";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/child"), this_object()); mob++; }
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
