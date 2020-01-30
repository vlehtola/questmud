inherit "room/room";
object monster;

reset(arg) {
  add_exit("north","/wizards/rehti/dormund/e");
  add_exit("west","/wizards/rehti/dormund/city");  
  short_desc = "Southeastern part of inner city";
  long_desc = "This is the southeastern part of inner city. There are children playing with\n" +
              "their parents and they really look happy. This is perfect place to spend\n" + 
              "time. Beautiful flowers and the most green grass grows here. Central square\n"+
              "is northwest from here.\n";
  items = allocate(4);
  items[0] = "flowers";
  items[1] = "The most beautiful flowers that you have seen";
  if(!present("boy")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/boy"), this_object());
  if(arg) { return; }
}
if(!present("girl")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/girl"), this_object());
  if(arg) { return; }
}
}