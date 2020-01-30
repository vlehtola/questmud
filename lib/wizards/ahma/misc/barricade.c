#define TPN this_player()->query_name()

inherit "obj/armour";
int north, south, west, east, set;
string size = "medium", blodir, toughness = "almost impossible";

short() { return "A "+size+"-sized barricade is built here"; }

long(str) {
  write("A "+size+"-sized barricade is blocking your way to "+blodir+".\n");
  write("The barricade is made of "+size+" rocks. It seems to be\n");
  write(toughness+" to break it.\n");
  return;
}

id(str) { return str == "barricade" ; }

get(str) { return 0; }

init() {
  ::init();
  add_action("north", "north");
  add_action("south", "south");
  add_action("west", "west");    
  add_action("east", "east");
  add_action("breek", "break");
  add_action("set_block", "set_block");
  //add_action("set_size", "set_sizez");
}

set_block(str) {
  if(set) {
    write("Direction already set to "+blodir+".\n");
    return 1;
  }
  if(str=="north") { north = 1; blodir = "north"; }
  if(str=="south") { south = 1; blodir = "south"; }
  if(str=="west") { west = 1; blodir = "west"; }
  if(str=="east") { east = 1; blodir = "east"; }
  long();
  set = 1;
  return 1;
}
  
north() {
  if(!north) return;
  write("The barricade is blocking your way to north.\n");
  return 1;
}

south() {
  if(!south) return;
  write("The barricade is blocking your way to south.\n");
  return 1;
}

west() {
  if(!west) return;
  write("The barricade is blocking your way to west.\n");
  return 1;
}

east() {
  if(!east) return;
  write("The barricade is blocking your way to east.\n");
  return 1;
}

breek(str) {
  if(str != "barricade") return;
  if(this_player()->query_str() < 1000) {
    write("You try to break to barricade but manage to inflict no visible\n");
    write("damage to it.\n");
    say(TPN+" tries to break to barricade but fails miserably.\n");
    return 1;
  }
  else {
    write("You break the barricade and the way to the west is clear.\n");
    say(TPN+" breaks the barricade and clears the way to the west.\n");
    destruct(this_object());
    return 1;
  }
}
