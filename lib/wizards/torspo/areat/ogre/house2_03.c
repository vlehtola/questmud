inherit "room/room";

reset(arg) {
  if(arg) { return; }

 if(!present("servant")) {

 move_object(clone_object("/wizards/torspo/areat/ogre/monsters/servant.c"), this_object());
 }
 
  add_exit("west", "/wizards/torspo/areat/ogre/house2_01.c");

  short_desc = "kitchen";
  long_desc = "This is the kitchen of this house. Oven and other kitchen accessories\n"+
              "are placed beside the walls. The cooks seem to have prepared\n"+
              "something special delicatessen for the king. Wooden table is\n"+
              "totally covered with those goodies.\n"; 

  items = allocate(4);
  items[0] = "oven";
  items[1] = "Stone oven. It's used in food making";
  items[2] = "table";
  items[3] = "Oaken table. It's covered with various kinds of foods";
  set_not_out(1);
  set_light(3);
}

