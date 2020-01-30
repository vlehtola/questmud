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
  add_exit("east","/wizards/gynter/area2/city2/temple");
  add_exit("west","/wizards/gynter/area2/city2/temple");
  add_exit("south","/wizards/gynter/area2/city2/temple");
  /* setting desc */
  short_desc = "";
  long_desc = "\n"+
              "\n"+
              "\n";
}
