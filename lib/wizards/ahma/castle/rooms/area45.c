inherit "room/room";
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area46");
  add_exit("south", "/wizards/ahma/castle/rooms/area44");
  set_blocker("guard", "north");
  short_desc = "Underground tower entrance";
  long_desc =  "At the tower entrance.\n" + 
               "There are no doors in the tower entrance, like there are no shutters in the\n" + 
               "windows either, making the doorway gape from the side of the tower like a\n" + 
               "mouth. The doorway is glowing with red because of the glowy stones inside the\n" + 
               "tower. Some of the dead human guards have been dragged down here and nailed on\n" + 
               "the walls of the tower with sharp shards of stone. The glowing road leads to\n" + 
               "south towards the intersection.\n";

  set_not_out(1);

  if(!monster01) {
    monster01 = clone_object("/wizards/ahma/castle/mob/mob17");
    move_object(monster01, this_object());
  }
  if(!monster02) {
    monster02 = clone_object("/wizards/ahma/castle/mob/mob17");
    move_object(monster02, this_object());
  }
}