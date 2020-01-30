inherit "room/room";

 
reset(arg) {
  add_exit("east","/wizards/grathlek/area2/hroom11.c");
  add_exit("south","/wizards/grathlek/area2/hroom1.c");
  set_light(1); 
  
  short_desc = "In the entrance of the dark labyrhint.";
  long_desc = "This is entrance of the dark labyrhint.\n"+
              "There is a huge pentagram on the floor.\n"+
              "Portal glows in red and black. It is\n"+
              "really cold in here.\n"; 
}
