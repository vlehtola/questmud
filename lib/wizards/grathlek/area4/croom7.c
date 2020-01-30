inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/eimp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/croom8.c");
  add_exit("east","/wizards/grathlek/area4/croom6.c");
  add_exit("southwest","/wizards/grathlek/area4/mroom8.c");
  set_light(2);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "This is a red glowing junction.\n"+
              "Red light shines from the west and\n"+
              "it warms this cold cave.\n";

}
