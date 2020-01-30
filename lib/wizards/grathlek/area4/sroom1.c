inherit "room/room";
object monster; 
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/afamu.c");
    move_object(monster, this_object());
   }
  add_exit("out","/wizards/grathlek/area4/mroom10.c");
  set_light(2);
 
  short_desc = "In the familiar hole.";
  long_desc = "This is the home of familiars.\n"+
              "Some garbage is on the ground.\n"+
              "It's very warm and gloomy here.\n";
}
