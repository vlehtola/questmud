inherit "room/room";
object monster; 
 
 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/fall.c");
    move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area2/room15.c");
  add_exit("north","/wizards/grathlek/area2/room5.c"); 
  set_light(0);  
  short_desc = "In the cathedral street of Tristram.";
  long_desc = "You are standing on the dark coner of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "The street lamp is broken.\n";
}
