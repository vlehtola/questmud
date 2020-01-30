inherit "room/room";

reset (arg) {

    add_exit("south","temple25");
    add_exit("stairs","rest2");
        short_desc = "Stairs going in resting rooms";
        long_desc = "The stairs going in the clerics private rooms. The stairs\n"+
                    "look quite old and not that sturdy what they really are.\n"+
                    "The walls and ceiling are full of dust. A tiny footprints\n"+
                    "are going in the private rooms, at closer look they are claw\n"+
                    "prints.\n";
        set_not_out(1);
        set_light(2);
                       items = allocate(4);
                       items[0] = "footprints";
                       items[1] = "They are made by a small claw creature maybe a demon";
                       items[2] = "stairs";
                       items[3] = "They are going in the resting rooms";

}
