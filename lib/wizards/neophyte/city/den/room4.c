inherit "room/room";
reset(arg) {
        add_exit("south","room6");
        add_exit("northeast","entrance");
short_desc = "Small cavern";
long_desc = "This part of the caverns is slighly in better condition than elsewhere\n"+
            "maybe its because of that important looking red carpet which is\n"+
            "laid on the floor. On the cave walls is two torches burning on\n"+
            "both side and giving some light to this dark cave.\n";
set_not_out(1);
set_light(2);

}


