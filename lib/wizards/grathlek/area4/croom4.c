inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/limp.c");
    move_object(monster, this_object());
   }
  add_exit("southwest","/wizards/grathlek/area4/croom5.c");
  add_exit("east","/wizards/grathlek/area4/croom3.c");
  set_light(2);
 
  short_desc = "A rocky path leading to southwest.";
  long_desc = "This path is full of stones and it's\n"+
              "hard to move also because this passage\n"+
              "is very tight and low.\n";

}
