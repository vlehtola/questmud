inherit "room/room";
object monster01;

reset(arg) {
  if(arg) return;
    if (!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob20"); 
      move_object(monster01, this_object());
    }
  
  add_exit("up", "/wizards/ahma/castle/rooms/area48");
  add_exit("down", "/wizards/ahma/castle/rooms/area46");
  short_desc = "Second floor of the tower";
  long_desc =  "On the second floor of the Demon Tower.\n" + 
               "The room looks shabby. There is some kind of panels hanging on the walls. The\n" + 
               "suspect is that these panels are there for apprentice mages to train their\n" + 
               "accuracy with different magic spells. The crumbled walls show that the ones\n" + 
               "using these panels are really in a need of practice. A piece of southwestern\n" + 
               "wall is even collapsed due to mistargeted spell. The only part of the concave\n" + 
               "wall which is not ruined by inexperienced mages is full of runes and simple\n" + 
               "pictures drawn with human blood. Crappy stairs are leading to the floor below\n" + 
               "in the north and to the upper floor in the southern part of the room.\n";

  set_not_out(1);
  set_blocker("kern'h", "up");
}
