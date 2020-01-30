inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("out","/wizards/luminarc/mountain/bot2");
  add_exit("forward","/wizards/luminarc/mountain/cave12");
  short_desc="Cave";
  long_desc="Large granite cave opens here. Granite on the walls is cold and\n"+
            "thin layer of ice is covering it. On ground there is some slimy\n"+
            "green material. The cave leads deeper on the ground. \n"+
            "Weird crumbling sound is echoing from the bottom of the cave.\n";
  property = allocate(1);
  set_light(3);
}

