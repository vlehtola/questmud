inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/tower11");
  add_exit("west","/wizards/luminarc/wizcastle/upeast1");  
  add_exit("north","/wizards/luminarc/wizcastle/upnorth1");   
  add_exit("garden","/wizards/luminarc/wizcastle/garden/entrance");
  short_desc = "hall";
  
  long_desc = "Small hall opens here. Spiral ladders are leading up to the tower. \n"+
              "At north side there is huge fireplace which gives light and warm to\n"+
              "this room. Several pictures are placed on the wall and one small window\n"+
              "is placed on east wall\n";
  property = allocate(1);
  set_light(3);
}

