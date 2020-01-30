inherit "room/room";

reset(arg) {
  add_exit("east", "107");
  add_exit("northwest", "102");
  short_desc = "A narrow tunnel";
  long_desc = "The tunnel is very narrow, making the moving difficult in it. The tunnel\n" +
              "is shaped like a small pipe. The walls seem to be covered thoroughly with\n" +
              "frozen snow, but they are not smooth. Some harder bumps make the moving\n" +
              "in the tunnel even more uncomfortable. In the ceiling, there cannot be\n" +
              "seen any icicles, which seems to be just about only positive thing in this\n" +
              "narrow and uncomfortable tunnel. The floor is also covered with frozen\n" +
              "snow. The tunnel continues to east and in northwest can be seen a small\n" +
              "opening.\n";
  if(!present("wolverine")) move_object(clone_object("/wizards/ahma/ice/mob/wolverine"), this_object());
}