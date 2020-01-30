inherit "room/room";
object monster;

reset(arg) {
  if(!present("undead")) {
    move_object(clone_object("/wizards/duncan/island/lighthouse/monsters/undead"),
    this_object());
}

if(arg) return;

set_not_out(1);
set_light(3);

add_exit("south","/wizards/duncan/island/lighthouse/corridor2");
add_exit("west","/wizards/duncan/island/lighthouse/corridor4");
add_exit("east","/wizards/duncan/island/lighthouse/corridor5");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A gloomy corridor inside the ancient lighthouse, built to warn ships from\n"+
             "range of rocks, which are skulking around the island. The corridor is dusty\n"+
             "and gloomy, but still in good condition. The stone walls are cold and gloomy,\n"+
             "full of writings and pictures, which have worned out and therefore they are\n"+
             "beyond interpret. Spiderwebs are covering the rough ceiling. The floor is\n"+
             "rough and dusty, full of different sized footprints. The corridor is lit up\n"+
             "with torches, which are burning with everlasting flames. It's rumoured, that\n"+
             "the lighthouse is home for dead sailors and pirates. The corridor is located\n"+
             "on the first floor of the lighthouse.\n";

    items = allocate(8);
    items[0] = "walls";
    items[1] = "The walls are made of stone, looking cold and gloomy. There are some worned out writings and pictures on the walls, which can't be interpret. Five torches are placed on the walls, on both sides of the corridor";
    items[2] = "ceiling";
    items[3] = "Spiderwebs are covering the ceiling. There are no spiders around";
    items[4] = "floor";
    items[5] = "Rough and dusty floor is full of footprints, left by some big creatures";
    items[6] = "torches";
    items[7] = "Five torches are placed on the gloomy walls. They are burning with everlasting flames, bringing light and warmth in the corridor";

  property = allocate(1);
  property[0] = "no_summon";

  }

