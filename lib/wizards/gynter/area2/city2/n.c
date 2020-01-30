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
  add_exit("north","/wizards/gynter/area2/city2/j");
  /* setting desc */
  short_desc = "Main road leaving the control towers";
  long_desc = "This is the main road that leads away from the towers.\n"+
              "It is made out of ivory and strangely enough the ivory\n"+
              "seems totaly unscathed even though it is completly obvious\n"+
              "that this road is used on a daily basis.\n";
}
