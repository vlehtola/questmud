inherit "room/room";

object guard1,guard2;
 
reset(arg) {
  if(!guard1) {
    guard1 = clone_object("/wizards/walla/jericho/mobs/ablocker");
    move_object(guard1, this_object());
  }
  
  if(!guard2) {
    guard2 = clone_object("/wizards/walla/jericho/mobs/sblocker");
    move_object(guard2, this_object());
  }
 
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/leblair/leblair4");
  add_exit("south","wizards/walla/jericho/rooms/leblair/leblair2");
  short_desc = "In an underground lair";
  long_desc = "The room, that you have just entered, is surely one of the more frightening\n"+
              "places you've ever seen. The ground is covered with blood, and remainders of\n"+
              "brave adventurers can bee seen in heaps. On the walls, you can see chandeliers\n"+
              "that give some light to this room.\n";

}




