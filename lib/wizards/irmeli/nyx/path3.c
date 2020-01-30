inherit "room/room";

reset(arg) {

            add_exit("north", "/wizards/irmeli/nyx/path4");
            add_exit("south", "/wizards/irmeli/nyx/path2");

short_desc = "Path to the volcano";
long_desc = "The path covered on ash and lava rock gets sharper. The ground is rough,\n"
            "full of lava rock and ash. The soil is not fertile or it seems so, because\n"
            "there are no trees or flowers growing in here. The scene is barren and\n"+
            "dull everywhere around you.\n";

if(!present("hound")) {
move_object(clone_object("/wizards/irmeli/nyx/monsters/hound"),
this_object());
}
}

