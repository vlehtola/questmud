inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/areas/mg/mobs/lurker");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","41");
  add_exit("northwest","31");
  add_exit("north","32");
  add_exit("east","43");
  add_exit("northeast","33");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. A freshly filled grave\n" +
"stands next to you and it has new flowers laid upon it.\n";

  items = allocate(2);
  items[0] = "grave";
  items[1] = "A grave.";


}
