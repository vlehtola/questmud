inherit "room/room";
object monster; 
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/guard2.c");
    move_object(monster, this_object());
  }
  add_exit("west","/wizards/grathlek/area2/room19.c");
  add_exit("enter","/wizards/grathlek/area2/croome.c");
  set_light(0); 
  short_desc = "Entrance to the dark cathedral of Kahnduras";
  long_desc = "You are standing on the entrance of dark \n"+
              "cathedral Kahnduras. cathedral looks really\n"+
              "creepy and scary. Maybe you should think\n"+
              "twice before entering.\n";
}
