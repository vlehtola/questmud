inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/luminarc/wizcastle/room1");
  add_exit("up","/wizards/luminarc/wizcastle/up1");
  short_desc = "North part of hall";
  long_desc = "This is the  north side of the mainhall. In the northern part of the room\n"+ 
              "marble stairs are leading up to the second level of the castle. Beautiful\n"+
              "flowers are placed all around the room. The smell of them fill the room\n"+
              "with a peaceful feeling\n";  
  set_light(3);

}




