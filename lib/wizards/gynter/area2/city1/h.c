inherit "room/room";
object demon, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon, this_object());
  }
  if(!demon2 && random(3)) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city1/r");
  add_exit("east","/wizards/gynter/area2/city1/i");
  add_exit("west","/wizards/gynter/area2/city1/g");
  /* setting desc */
  short_desc = "Falcon road";
  long_desc = "This is the road that binds the east and west side of the town\n"+
              "together. It is called Falcon road because of that it spreads it's wings\n"+
              "all over town. There is only one road that is linking with this one.\n";
}
