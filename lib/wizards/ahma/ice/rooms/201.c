inherit "room/room";

reset(arg) {
  add_exit("southwest", "202");
  add_exit("hole", "111");
  short_desc = "A second floor entrance";
  long_desc = "A small tunnel: an entrance to the second floor of icy caverns. The ground\n" +
              "is covered with soft snow, unlike the walls and the ceiling, which are\n" +
              "frozen solid. The tunnel leads to southwest, where can be seen a spacious\n" +
              "opening. A hole in the eastern wall leads upwards to the first floor.\n";
}