inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/tower21");
  add_exit("south","/wizards/luminarc/wizcastle/upeast2");   
  short_desc = "corner room";
  
  long_desc = "This room is pretty small there is only tiny fireplace and ladders leading\n"+
              "to second tower. Nice and warm light is emitting from the fireplace. Small\n"+ 
              "window is placed on north side of the room.\n";
  property = allocate(1);
  set_light(3);
 ob = clone_object("/wizards/luminarc/wizcastle/humans/guard.c");
 move_object(ob, this_object());
 ob = clone_object("/wizards/luminarc/wizcastle/humans/repair.c");
 move_object(ob, this_object());
}

