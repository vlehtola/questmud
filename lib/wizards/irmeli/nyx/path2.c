inherit "room/room";

reset(arg) {

            add_exit("north", "/wizards/irmeli/nyx/path3");
            add_exit("east", "/wizards/irmeli/nyx/ruin1");
            add_exit("south", "/wizards/irmeli/nyx/path");

            short_desc = "Path leading up to the volcano";
long_desc = "The crossing, the path divides up to two smaller paths, another to east\n"+
            "towards old ruins, other leads up to the top of the volcano. The path is\n"+ 
            "covered on ash and hardened lava rock. The lava field has covered all the\n"
            "flowers and trees, which once grew in here.\n";

if(!present("hound")) {
move_object(clone_object("/wizards/irmeli/nyx/monsters/hound"), this_object());
}
}
