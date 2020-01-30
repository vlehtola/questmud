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
  add_exit("north","/wizards/gynter/area2/city2/c");
  /* setting desc */
  short_desc = "Main road leaving the control towers";
  long_desc = "This is the main road that leads away from the towers.\n"+
              "Strangely it seems impossible to walk south.\n"+
              "The walls are closing in on themself behind you.\n";
}
