inherit "room/room";
object demon, demon1;

reset(arg) {
  if(!demon && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon, this_object());
  }
  if(!demon1 && random(3)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/k");
  add_exit("west","/wizards/gynter/area2/city1/i");
  /* setting desc */
  short_desc = "Falcon road";
  long_desc = "This is the road that binds the east and west side of the town\n"+
              "together. There is only one road that is linking with this one.\n";
}
