inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil18");
  add_exit("south", "/wizards/ahma/orc/village/vil19");
  short_desc = "Central part of Zark street";
  long_desc = "########### Zark street continues to north and south. The village square is\n" + 
              "# /  | #### located in east, but it is surrounded by a deep moat. Behind some\n" + 
              "#'   * #### distance to your west can be seen the entrance leading deeper into\n" + 
              "#    | #### the thick, green forest surrounding this village. Only a few trees\n" + 
              "########### line the road when walking in the center of the village.\n";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/woman"), this_object()); mob++; }
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