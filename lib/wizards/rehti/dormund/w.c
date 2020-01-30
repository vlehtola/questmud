inherit "room/room";
object monster;

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/cs");
  add_exit("north","/wizards/rehti/dormund/nw");
  add_exit("west","/wizards/rehti/dormund/cleric");  
  add_exit("south","/wizards/rehti/dormund/sw");
  short_desc = "West part of inner city";
  long_desc = "This is the western part of inner city. There are children playing with\n" +
              "their parents and they really look happy. This is perfect place to spend\n" + 
              "time. Beautiful flowers and the most green grass grows here. Central square\n"+
              "is east from here. There's cleric's office to west from here.\n";
  items = allocate(4);
  items[0] = "walls";
  items[1] = "These walls are sturdy like they were when looked from outside, only difference is that there are no cracks at all";
  if(!present("man")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/man"), this_object());
  if(arg) { return; }
}
  if(!present("woman")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/woman"), this_object());
  if(arg) { return; }
}
  if(!present("girl")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/girl"), this_object());
  if(arg) { return; }
}
}