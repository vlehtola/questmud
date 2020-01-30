inherit "room/room";

/* recoded by Celtron */

reset(arg) {
  if(arg) return;
  set_light(3);
  set_not_out(1);
  short_desc = "The Commander's room";
  long_desc = "This is the commander's room. There are papers\n" +   
              "concerning tactics and such rubbish everywhere.\n" +  
              "There are also many pictures of the tower of High\n" +
              "Sorcery, and a dartboard with Darvox's picture on\n" +
              "it.\n";
  add_exit("down", "wizards/nalle/area/i5");
  move_object(clone_object("/wizards/nalle/area/monsters/commander"), this_object());
  items = allocate(2);   
  items[0] = "dartboard";
  items[1] = "A dartboard with a picture of Darvox. Most of the darts seem to have missed, though";
}
