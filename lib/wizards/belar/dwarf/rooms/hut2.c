inherit "room/room";

reset(arg) {
add_exit("south","/wizards/belar/dwarf/rooms/weside1.c");
short_desc = "A baar - not redy";
long_desc = "You are standing in a doorway.This large hut seemed so little \n"+
            "from outside, but when inside it is really large. The person who\n"+
            "lives in here must be a great hunter.The northern wall is full of animal\n"+
            "heads. you can feel the force whithin. \n"+
            "a mysterious force surronding you.\n";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  items = allocate(2);
  items[0] = "desk";
  items[1] = "desk.";
}

