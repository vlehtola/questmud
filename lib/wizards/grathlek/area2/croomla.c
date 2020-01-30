inherit "room/room";
object monster; 

 
reset(arg) {
   if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/belz.c");
    move_object(monster, this_object());
  }
  add_exit("east","/wizards/grathlek/area2/croomp.c");
  add_exit("west","/wizards/grathlek/area2/croom7.c");
  
  short_desc = "Arch bishops room.";
  long_desc = "This is arch bishops workroom. This\n"+
              "room is very dirty and messed. It looks\n"+
              "like some maniac would been racing.\n"+
              "around this room.\n"; 
 }
