inherit "room/room";
object monster;

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/ne");  
  add_exit("west","/wizards/rehti/dormund/nw");
  add_exit("south","/wizards/rehti/dormund/cs");
  add_exit("north","/wizards/rehti/dormund/hall");
  short_desc = "Castle entrance";
  long_desc = "This is the entrance to the castle Dormund. This place should be well protected\n"+
              "when there's a large assault going on, but since these are peaceful times castle\n"+
              "doors are left open. Huge halls and nothing but military can be seen through doorway.\n"+
              "Maybe that is not the best place to go.\n";
  items = allocate(4);
  items[0] = "doors";
  items[1] = "Huge doors which would certainly stop attacks easily even if they were the weakest spot in walls";
  if(!present("guard")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/gateguard"), this_object());
  if(arg) { return; }
}
}