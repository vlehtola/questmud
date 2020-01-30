inherit "room/room";

object monsu;

reset(arg) {
  if(!monsu) {
    monsu = clone_object("/wizards/walla/areas/mg/mobs/wife");
    move_object(monsu, this_object());
  }
  if(arg) return;
  add_exit("north","21");
  add_exit("northeast","22");
  add_exit("south","41");
  add_exit("east","32");
  add_exit("southeast","42");
  add_exit("hut","hut");

  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. There is a small hut next to the path, with a run-down door on\n" +
"it. The hut looks like it has been erected in some haste, and doesn't\n"+
"look too imposing.\n";


}

