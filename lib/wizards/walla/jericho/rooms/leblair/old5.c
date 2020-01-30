inherit "room/room";
 
object leb;
 
reset(arg) {
  if(!leb) {
    leb = clone_object("/wizards/walla/jericho/mobs/leb");
    move_object(leb, this_object());
  }
 
  if(arg) return;
  add_exit("northeast","wizards/walla/jericho/rooms/leblair/regenne");
  add_exit("northwest","wizards/walla/jericho/rooms/leblair/regennw");
  add_exit("southeast","wizards/walla/jericho/rooms/leblair/regense");
  add_exit("southwest","wizards/walla/jericho/rooms/leblair/regensw");
  add_exit("south","wizards/walla/jericho/rooms/leblair/leblair4");
  short_desc = "Pentagram room";
  long_desc = "This is the biggest room in the underground lair so far. A huge pentagram\n"+
              "covers the floor, and in each the points, there is a a pillar, with a burning\n"+
              "flame in it. You can sense something bad about this room, as an eerie feeling\n"+
              "creeps up on you.\n";
 
}
 
 
 
 
