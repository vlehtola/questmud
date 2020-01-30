inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("out","/wizards/luminarc/wizcastle/westhall");
  short_desc = "Round shaped room";
long_desc="This round shaped room looks amazing. Hunreds of small balls of\n"+ 
          "light are whirling around the room. Two pillars are placed in the center\n"+
          "of the room. They hold up a huge pool of yellow liquid. Four windows\n"+ 
          "are placed on the walls in asymmetrical order. The golden plate is\n"+
          "shining on the ground as the balls whirl madly around the room.\n"; 

  property = allocate(1);
  set_light(3);
  items = allocate(4); 
  items[0]="poll";
  items[1]="The poll contains a yellow liquid. the dark shape of item or something can be discovered bottom of the poll";
 ob = clone_object("/wizards/luminarc/wizcastle/humans/demon.c");
 move_object(ob, this_object());

}







