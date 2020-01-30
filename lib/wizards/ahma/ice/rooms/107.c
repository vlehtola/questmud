inherit "room/room";

reset(arg) {
  add_exit("north", "108");
  add_exit("south", "112");
  add_exit("west", "106");
  add_exit("east", "109");
  short_desc = "An intersection between narrow tunnels";
  long_desc = "The narrow tunnels divide into four directions from here. A weak gusts of\n" +
              "wind can be felt blowing in east-west direction. Some echoes can be heard\n" +
              "floating around the tunnel system with the gusts. The tunnel walls and\n" +
              "ceiling are covered with frozen snow. In the low ceiling cannot be seen\n" +
              "any icicles.\n";
  if(!present("husky")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
}