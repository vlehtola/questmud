inherit "room/room";

reset(arg) {

add_exit("north", "/wizards/irmeli/nyx/path2");
add_exit("south", "/wizards/irmeli/nyx/entrance");

short_desc = "Path leading up to the volcano";
long_desc = "A path covered on ash and lava rock leads up, trying to reach the top\n"+
            "of the volcano. The ground on the path is rough and there are some\n"+
            "hardened footprints on the lava rock.\n";

if(!present("hound")) {
move_object(clone_object("/wizards/irmeli/nyx/monsters/hound"), this_object());
}
}
