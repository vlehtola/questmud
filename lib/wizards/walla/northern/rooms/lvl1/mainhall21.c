inherit "room/room";
init() {
  ::init();
  add_action("straighten", "straighten");
}

straighten(str) {
  if(str != "torchholder") return;
  write("You straighten the torchholder, and the wall slides open.\n");
  say(""+this_player()->query_name()+" fumbles with the torchholder.\n");
  add_exit("south","/wizards/walla/northern/rooms/lvl1/torch_secret");
  command("look");
  return 1;
}


  reset(arg) {
  add_exit("northeast","/wizards/walla/northern/rooms/lvl1/mainhall12");
  add_exit("east","/wizards/walla/northern/rooms/lvl1/mainhall22");
  add_exit("north","/wizards/walla/northern/rooms/lvl1/mainhall11");
  short_desc = "In a great hall inside the mountain";
  long_desc =
"The main hall in this mountain castle is dimly lit by a great amount\n"+
"of torches, that are flickering in the light draught that you can feel\n"+
"here. There are a multitude of pillars that support the rocky roof, \n"+
"some 50 feet over your head. The hall expands in all the directions, \n"+
"and it is hard to see any walls in this faintly lit area. On the wall,\n"+
"you can see an empty torchholder, that looks different.\n";
  items = allocate(2);                
  items[0] = "torchholder";
  items[1] = "A rusty torchholder hanging from the wall. It is not hanging upright anymore";
  
}