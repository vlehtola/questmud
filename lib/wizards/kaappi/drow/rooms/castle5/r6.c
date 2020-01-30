inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("south", "r3.c");
  add_exit("north", "r8.c");
  add_exit("stairs", "torni2.c");
  add_exit("down", "d1.c");

  short_desc = "A hallway";
  long_desc = "You are standing under the spiral stairs which\n"+
              "are leading up to the biggest tower. Some female\n"+
              "voices are coming from the upstairs. In the corner\n"+
              "there is a smaller stairs leading to down. A wooden\n"+
              "door can be seen in the north.\n";  
  
  set_light(1);
}
