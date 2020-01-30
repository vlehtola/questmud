inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/3priest");
    move_object(demon, this_object());
  }
  if(!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/3priest");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/templeh");
  add_exit("north","/wizards/gynter/area2/city2/templee");
  /* setting desc */
  short_desc = "3:rd circle walk";
  long_desc = "Now the walls are showing the thought of long since gone warriors\n"+
              "and archmage's. And strangely one of the things repeating itself\n"+
              "is the word WAR!\n";
}
