inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/egimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom10.c");
  add_exit("west","/wizards/grathlek/area4/kroom1.c");
  set_light(3);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "This is the main corridor of this cave.\n"+
              "There are bones and black blood on the path.\n"+
              "Red light and a burning heat shines very\n"+
              "brightly from the west.\n";
}
