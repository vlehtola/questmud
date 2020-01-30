inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil27");
  add_exit("south", "/wizards/ahma/orc/village/vil12");
  short_desc = "Central part of Zark street";
  long_desc = "########### Zark street continues to north and south. The village square is\n" + 
              "#    | #### located in east, but it is surrounded by a deep moat. Two wooden\n" + 
              "#    * #### bridges are crossing the moat from the northern and southern part\n" + 
              "# H  | #### of it. The dusty, soft road feels comfortable under your feet. It\n" + 
              "########### seems that here can be even comfortable things in a village like this.\n";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/man"), this_object()); mob++; }
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