inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wimp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/croom6.c");
  add_exit("northeast","/wizards/grathlek/area4/croom4.c");
  add_exit("southeast","/wizards/grathlek/area4/mroom4.c");
  set_light(2);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "This is a gloomy junction and\n"+
              "the red light looms from the west.\n"+
              "This is the area where nobles desert\n"+
              "their garbage. Filth and dirt smells\n"+
              "awful here.\n";

}
