inherit "room/room";

object luu;

reset(arg) {
  if(!luu) {
    luu = clone_object("/wizards/walla/areas/mg/stuph/bone");
    move_object(luu, this_object());
  }
  if(arg) return;
  add_exit("west","31");
  add_exit("east","33");
  add_exit("north","22");
  add_exit("south","42");
  add_exit("northeast","23");
  add_exit("northwest","21");
  add_exit("southeast","43");
  add_exit("southwest","41");
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
