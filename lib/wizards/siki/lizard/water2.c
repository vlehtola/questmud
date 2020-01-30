inherit "room/room";

reset(arg) {


  add_exit("surface","/wizards/siki/lizard/dock2");
  add_exit("down","/wizards/siki/lizard/water");

  short_desc = "In the lake";
  long_desc = "The water is quite muddy. The bottom is hard and there are\n"+
              "some plants growing. When you take a closer look, you see\n"+
              "strange pieces of different kinds of metals on the bottom.\n"+
              "There are also some white long items, they look little like bones.\n";
        
  set_water(10);
}
