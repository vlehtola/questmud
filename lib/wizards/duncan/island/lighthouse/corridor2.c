inherit "room/room";
object monster;

reset(arg) {
  if(!present("undead")) {
    move_object(clone_object("/wizards/duncan/island/lighthouse/monsters/undead"),
    this_object());
}

if(arg) return;

set_not_out(1);
set_light(1);

add_exit("north","/wizards/duncan/island/lighthouse/corridor3");
add_exit("south","/wizards/duncan/island/lighthouse/corridor1");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "The corridor is connected together with other corridors, which creates the\n"+
             "base of the lighthouse. The lighthouse is like a big labyrith, corridors\n"+
             "leading to a different directions, west, east, north and south, confusing\n"+
             "the adventurers. The corridors are all same sized and they look same, that's\n"+
             "why it's easy to get lost. The stone walls are cold and gloomy, full of\n"+
             "writings and pictures, which have worned out and therefore they are beyond\n"+
             "interpret. The ceiling is covered with spiderwebs, but spiders can't be seen\n"+
             "around. The floor is rough and dusty, so dusty that, there are footprints left\n"+
             "in the dust. There's a dim light coming from north, making shadows on the\n"+
             "walls. The corridor is located on the first floor of the lighthouse, leading\n"+
             "towards north and south.\n";

    items = allocate(6);
    items[0] = "walls";
    items[1] = "The walls are made of stone, looking cold and gloomy. There are some worned out writings and pictures on the walls, which can't be interpret";
    items[2] = "ceiling";
    items[3] = "Spiderwebs are covering the ceiling. There are no spiders around";
    items[4] = "floor";
    items[5] = "Rough and dusty floor is full of footprints, left by some big creatures";

  property = allocate(1);
  property[0] = "no_summon";

  }

