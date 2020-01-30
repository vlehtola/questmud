inherit "room/room";
inherit "room/door";
int door_number;
reset(arg) {
          if(!present("undead")) {
            move_object(clone_object("/wizards/neophyte/city/monst/undead"), this_object());
}
if(arg) return;

set_not_out(1);
set_light(1);

add_exit("south","corridor5");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A corridor is curving inside the ancient lighthouse, the walls of corridor\n"+
             "are dusty and full of spider webs. A couple of former lighthouse keeper\n"+
             "pictures are hanging on the walls. An elegant looking old chandelier is hanging\n"+
             "from the ceiling making shadows on the floor.\n";

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
door_reset();
door_number = 1;
set_door_label("oak door", 1);
set_door_dir("west", "/wizards/neophyte/city/lighthouse/corridor7", 1);
set_door_link("/wizards/neophyte/city/lighthouse/corridor7", 1);
set_door_code(1, 1);
set_locked(0,1);
  }

init() {
  ::init();
  door_init();
}
