inherit "room/room";

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/rightmuuri");  
  add_exit("west","/wizards/rehti/dormund/leftmuuri");
  add_exit("south","/wizards/rehti/dormund/castleent");
  add_exit("north","/wizards/rehti/dormund/m1");
  add_exit("down","/wizards/rehti/dormund/tunkio");
  short_desc = "Castle hall";
  long_desc = "The entrance hall is decorated with many banners and ornaments which give nice\n"+
              "homelike feeling. There are also many candeliers around the room. It seems\n"+
              "that this castle is builded centuries ago and it has been in heavy use. Stone\n"+
              "floor has not worn under feets and it still has smooth covering which is\n"+
              "really strange. This place feels a bit magical anyway.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/entknight2"), this_object());
  if(arg) { return; }
}
}