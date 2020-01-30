inherit "room/room";

reset(arg) {
  add_exit("west", "211");
  add_exit("ladders", "301");
  short_desc = "A snowy and spacious room";
  long_desc = "The ground of this spacious room is covered with soft snow. The ceiling\n" +
              "is quite high, giving you some precious space to move in. The walls are\n" +
              "frozen solid and. therefore, reflect any kind of light very efficiently.\n" +
              "A wooden ladders covered in frozen snow are leading down in the hole by\n" +
              "the southern wall of this room. Some light is luminating in from the\n" +
              "hole. On the eastern wall there seems to be numerous small tunnels,\n" +
              "maybe made by some animals'.\n";
  
  items = allocate(2);
  items[0] = "tunnels";
  items[1] = "Numerous tunnels can be seen on the eastern wall of this room. The\n" +
             "tunnels are too small for you to fit in them, maybe they are dug by\n" +
             "some small animals such as minks";
}