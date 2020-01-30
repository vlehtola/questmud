inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/w");
  add_exit("south","/wizards/gynter/area2/city1/y");
  /* setting desc */
  short_desc = "The Golden Walk";
  long_desc = "Everything on this road was once covered with gold.\n"+
              "But now the only thing the road and houses are\n"+
              "covered with is grey dust and brown mud.\n";
}
