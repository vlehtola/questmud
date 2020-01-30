inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/temple1");
  add_exit("south","/wizards/gynter/area2/city2/temple4");
  /* setting desc */
  short_desc = "1:st circle walk";
  long_desc = "This is the walk of the first circle. No priest under the circle\n"+
              "of two may go furthen than these halls.\n";
}
