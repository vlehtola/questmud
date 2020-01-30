inherit "room/room";
object monster, monster1, monster2;
reset(arg) {
  if(!monster && !random(4)) {
    monster = clone_object("/wizards/gynter/area2/city1/mobs/ranger");
    move_object(monster, this_object());
  }
  if(!monster1 && !random(4)) {
    monster1 = clone_object("/wizards/gynter/area2/city1/mobs/ranger");
    move_object(monster1, this_object());
  }
  if(!monster2 && !random(4)) {
    monster2 = clone_object("/wizards/gynter/area2/city1/mobs/ranger");
    move_object(monster2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/2");
  add_exit("south","/wizards/gynter/area2/city1/5");
  /* setting desc */
  short_desc = "Courtyard";
  long_desc = "This is the courtyard outside the King's castle.\n"+
              "This is also the place where the King's rangers train\n"+
              "and live. They gather here so they are ready to be sent\n"+
              "out at any time in as short a time as possible.\n";
}
