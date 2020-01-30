inherit "room/room";

reset(arg) {
if(arg) return;
add_exit("trail","/wizards/irmeli/ff/r1.c.c");
add_exit("north", "out:");
add_exit("south", "out:");
add_exit("west", "out:");
add_exit("east", "out:");
short_desc = "Trail leading into a huge frozen forest";
long_desc = "Small trail leads deeper into the frozen forest. Everything is frozen, covered\n"+ 
            "with thick layer of ice, in this forest. The trees, bushes, grass and even the\n"+
            "ground is frozen, but the air is not cold, on the contrary it's quite warm. The\n"+
            "standing crop consist mostly of birches and oaks, some of them are surrounding\n"+
            "the path. It must be hard for the animals to get food from this forest, because\n"+
            "everything is frozen, except not for the beasts. There is thin layer of snow on\n"+
            "the ground and on the branches of trees. Your footprints are the only\n"+
            "footprints in here.\n";
}
