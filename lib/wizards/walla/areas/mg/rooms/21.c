inherit "room/room";

object statue;

reset(arg) {
  if(!statue) {
    statue = clone_object("/wizards/walla/areas/mg/stuph/statue");
    move_object(statue, this_object());
  }
  if(arg) return;
  add_exit("north","11");
  add_exit("northeast","12");
  add_exit("south","31");
  add_exit("east","22");
  add_exit("southeast","32");

  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. There is a statue of some former goddess standing here. You feel\n" +
"at ease in this room, as if the statue would bear some mystical powers.\n";


}


