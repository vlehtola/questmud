inherit "room/room";
object monster; 
 
 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/citi.c");
    move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area2/room6.c");
  add_exit("north","/wizards/grathlek/area2/room9.c");
  add_exit("south","/wizards/grathlek/area2/room14.c");
  add_exit("west","/wizards/grathlek/area2/room4.c");
  set_light(1); 
  
  short_desc = "In the main street of Tristram.";
  long_desc = "You are standing on the main street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "Street is light whit street lamps.\n";
}
