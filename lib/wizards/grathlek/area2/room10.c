inherit "room/room";
object monster; 
 
 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/citi.c");
    move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area2/room11.c");
  add_exit("west","/wizards/grathlek/area2/room9.c");  
  set_light(0);  
  short_desc = "In the dark street of Tristram.";
  long_desc = "You are standing on the dark street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "The street lamp is broken.\n";
}
