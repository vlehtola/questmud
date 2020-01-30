inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/eimp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/croom7.c");
  add_exit("east","/wizards/grathlek/area4/croom5.c");
  set_light(2);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "On the edge of this path are many rocks\n"+
              "on the row. Red light looms from the west.\n"+
              "Garbage on the ground smells like shit and\n"+
              "carrion animals swarm here.\n";

}
