inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
  if(arg) return;
  monster = clone_object("/wizards/grathlek/area1/monsies/cpaladin.c");
  move_object(monster, this_object());
  }
  add_exit("north","/wizards/grathlek/area1/uproom5.c");
  
  short_desc = "This is an well lighted room.";
  long_desc = "This is the room where the light begins.\n"+
              "There is a huge meteor on hanging from the ceiling of this room.\n"+
              "The light seems to come from the meteor.\n"; 

items = allocate(4);
  items[0] = "meteor";
  items[1] = "Meteor is hanging from the ceiling of this room.\n"+
             "Meteor has a magical glow and light the whole temple.";              
               
 

}
