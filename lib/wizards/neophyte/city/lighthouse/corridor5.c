inherit "room/room";
reset(arg) {
          if(!present("undead")) {
            move_object(clone_object("/wizards/neophyte/city/monst/undead"), this_object());
}
if(arg) return;

set_not_out(1);
set_light(1);

add_exit("north","corridor6");
add_exit("west","corridor3");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A corridor is curving inside the ancient lighthouse, leading alternately\n"+
             "to the four cardinal points of the compass, to east, west, north and south.\n"+
             "The ancient lighthouse hasen't dilapidated at all, the corridors are still\n"+
             "in good condition. The cold and gloomy walls are made of stone, full of\n"+
             "worned out writings and pictures. The rough ceiling is full of spiderwebs.\n"+
             "The rough floor is dusty, so dusty that, there are footprints left in the\n"+
             "dust. There's a dim light coming from west, drawing shadows on the walls.\n"+
             "The corridor, located on the first floor of the lighthouse, leads towards\n"+
             "north and west.\n";

    items = allocate(8);
    items[0] = "walls";
    items[1] = "The stone walls are cold and gloomy. There are some worned out writings and pictures on the walls, which can't be interpret";
    items[2] = "ceiling";
    items[3] = "Spiderwebs are covering the ceiling";
    items[4] = "floor";
    items[5] = "Rough and dusty floor is full of different sized footprints";
    items[6] = "footprints";
    items[7] = "There are footprints left to the floor, in the dust. There are different sized and shaped footprints all around the floor, leading here and there";

  property = allocate(1);
  property[0] = "no_summon";

  }

