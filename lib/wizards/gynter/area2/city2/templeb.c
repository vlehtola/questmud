inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/2priest");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/templec");
  add_exit("west","/wizards/gynter/area2/city2/templea");
  add_exit("north","/wizards/gynter/area2/city2/temple7");
  /* setting desc */
  short_desc = "2:nd circle walk";
  long_desc = "Now the corridor is getting finer with each step. Before there\n"+
              "was nothing but naked walls but now the walls are magically decorated\n"+
              "with the thought's of the bypasser.\n";
}
