inherit "room/room";

reset(arg) {
  add_exit("northwest", "203");
  add_exit("enter", "i02");
  add_exit("hole", "nest03");
  short_desc = "An end of a narrow tunnel";
  long_desc = "The narrow tunnel ends before an icy dwelling, an igloo. Igloo's roof\n" +
              "touches the tunnel's ceiling, and its sides touch the tunnel walls. The\n" +
              "tunnel can be seen ending straight behind the igloo in a frozen wall.\n" +
              "The doorway leading into the igloo is open. A small hole can be seen near\n" +
              "the eastern tunnel wall. The narrow tunnel leads to northwest, where\n" +
              "seems to be some kind of a spacious opening.\n";

  items = allocate(2);
  items[0] = "hole";
  items[1] = "A small hole is located in the ground by the eastern wall. It might be\n" +
             "an entrance to some animal's nest";
  if(!present("husky")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
}