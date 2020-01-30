

inherit "room/room";
 
reset(arg) {
 
  add_exit("south","leblair1");
  short_desc = "In an underground lair";
  long_desc = "The room, that you have just entered, is surely one of the more frightening\n"+
              "places you've ever seen. The ground is covered with blood, and remainders of\n"+
              "brave adventurers can bee seen in heaps. On the walls, you can see chandeliers\n"+
              "that give some light to this room.\n";
  property = allocate(2);
  property[0] = "no_kill";
  property[1] = "no_summon";
 }
