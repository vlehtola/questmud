inherit "room/room";
object monster;

reset(arg) {
  add_exit("north","/wizards/rehti/dormund/ne");
  add_exit("west","/wizards/rehti/dormund/cs");  
  add_exit("south","/wizards/rehti/dormund/se");
  short_desc = "East part of inner city";
  long_desc = "This is the eastern part of inner city. There are children playing with\n" +
              "their parents and they really look happy. This is perfect place to spend\n" + 
              "time. Beautiful flowers and the most green grass grows here. Central square\n"+
              "is west from here.\n";
  items = allocate(4);
  items[0] = "walls";
  items[1] = "These walls are sturdy like they were when looked from outside, only difference is that there are no cracks at all";
  if(!present("man")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/man"), this_object());
  if(arg) { return; }
}
  if(!present("boy")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/boy"), this_object());
  if(arg) { return; }
}
}