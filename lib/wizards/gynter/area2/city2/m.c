inherit "room/room";
object demon, demon1, demon2, demon3;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(6)) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(!demon1 && random(5)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon1, this_object());
  }
  if(!demon2 && random(4)) {
    demon2 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon2, this_object());
  }
  if(!demon3 && random(2)) {
    demon3 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/g");
  /* setting desc */
  short_desc = "Main road leaving the control towers";
  long_desc = "This is the main road that leads away from the towers.\n"+
              "It is made out of ivory and strangely enough the ivory\n"+
              "seems totaly unscathed even though it is completly obvious\n"+
              "that this road is used on a daily basis.\n";
}
