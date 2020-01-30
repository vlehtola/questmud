inherit "room/room";
object monster;

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/castleent");  
  add_exit("south","/wizards/rehti/dormund/w");
  short_desc = "Northwestern part of inner city";
  long_desc = "This is the northwestern part of inner city. There are children playing with\n" +
              "their parents and they really look happy. This is perfect place to spend\n" + 
              "time. Beautiful flowers and the most green grass grows here. Central square\n"+
              "is southeast from here. Castle entrance is to the east.\n";
  items = allocate(4);
  items[0] = "walls";
  items[1] = "These walls are sturdy like they were when looked from outside, only difference is that there are no cracks at all";
  if(!present("woman")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/woman"), this_object());
  if(arg) { return; }
}
  if(!present("girl")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/girl"), this_object());
  if(arg) { return; }
}
}