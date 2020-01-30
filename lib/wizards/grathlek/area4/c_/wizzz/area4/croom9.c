inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("southwest","/wizards/grathlek/area4/mroom10.c");
  add_exit("east","/wizards/grathlek/area4/croom8.c");
  set_light(2);
 
  short_desc = "A rocky path leading to southwest.";
  long_desc = "Red light glows everywhere in the\n"+
              "tunnel and it creates creepy shadows\n"+
              "like demons on the walls. Some strange\n"+
              "looking rocks are on the ground.\n";

items = allocate(4);
  items[0] = "rock";
  items[1] = "The rock looks heavy.";
}

int rock_lifted;
 
init() {
  add_action("lift", "move");
  add_action("lift", "lift");
  add_action("crawl", "crawl");
  ::init();
}
 
crawl(str) {
  if(rock_lifted) {
    write("You crawl to the hole.\n");
    say(this_player()->query_name()+" crawls in a hole.\n");
    rock_lifted = 0;
    move_object(this_player(), "/wizards/grathlek/area4/sroom9.c");
    say(this_player()->query_name()+" crawls out of the hole.\n");
    return 1;
  }
}
  if(str == "rock" || str == "rocks") {
  if(rock_lifted) {
      write("There is a hole under the rock.\n");
      return 1;
    } else {
      write("There is somehting under the rock.\n");
      return 1;
    }
  }
} 
id(str) {
  if(str == "hole") { return 1; }
  if(str == "rock" || str == "rocks") { return 1; }
 
lift(str) {
  if(str == "rock" || str == "rocks") {
    write("You lift one rock up and see a hole under it.\n");
    say(capitalize(this_player()->query_name())+" lifts one rock up with "+
            "great effort.\n");
    rock_lifted = 1;
    return 1;
  }
}
 

