inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil05");
  add_exit("west", "/wizards/ahma/orc/village/vil02");
  add_exit("east", "/wizards/ahma/orc/village/vil04");
  short_desc = "Intersection between Orgam and Ilem streets";
  long_desc = "########### The Orgam street continues to east and west. Ilem street starts\n" +  
              "#H   |   H# from here and leads further to north. Fresh-looking green bushes\n" + 
              "#+---*---+# are lining the street in the southern edge. Behind the bushes\n" + 
              "#|        # starts a thick, almost dark forest. Some animals are wandering\n" + 
              "########### around the forest bed, though the bushes block the full view.\n";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/dog"), this_object()); mob++; }
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