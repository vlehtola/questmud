inherit "room/room";

object monster;
int done;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/areas/mg/mobs/keeper");
    move_object(monster, this_object());
    if(done) monster->alreadydone();
  }
  if(arg) return;
  add_exit("west","13");
  add_exit("southwest","23");
  add_exit("south","24");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. A grave stands on your\n" +
"left side. It seems to be unfinished, thus a massive hole is in the place\n"+
"of the grave.\n";

  items = allocate(2);
  items[0] = "grave";
  items[1] = "An unfinished grave.";
  

}

questdone() {
  done++;
}