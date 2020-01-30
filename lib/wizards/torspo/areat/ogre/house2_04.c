inherit "room/room";

reset(arg) {
  if(arg) { return; }

 if(!present("king")) {

  move_object(clone_object("/wizards/torspo/areat/ogre/monsters/king.c"), this_object());
 }
 if(!present("guard")) {
  move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre11.c"), this_object());
 }
 
  add_exit("south", "/wizards/torspo/areat/ogre/house2_01.c");

  short_desc = "throne room";
  long_desc = "The throne room of mighty ogre king, Tahn'garth. A huge banner is\n"+
              "placed behind the throne. Throne is made of oak and decorated\n"+
              "with gold and silver. A red velvet carpet is placed on the floor.\n";
              
  items = allocate(6);
  items[0] = "banner";
  items[1] = "Huge white flag with blue cross painted on it";
  items[2] = "throne";
  items[3] = "The huge throne is made of oak. There are some symbols painted over it\n"+
             "with gold and silver";
  items[4] = "carpet";
  items[5] = "Red velvet carpet. It looks quite new but is already dirty and worn";
  set_not_out(1);
  set_light(3);
}
