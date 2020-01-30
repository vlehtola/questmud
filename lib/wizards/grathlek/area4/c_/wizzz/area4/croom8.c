inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/croom9.c");
  add_exit("east","/wizards/grathlek/area4/croom7.c");
  set_light(2);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "Red light shines round the corner\n"+
              "and it glows on the walls like a blood\n"+
              "stream in a nightmare.\n";

}
