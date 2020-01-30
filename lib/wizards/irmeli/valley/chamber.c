inherit "room/room";

reset(arg) {
 if (arg) { return; }
 short_desc = "A dusty chamber";
 long_desc = "A dusty chamber deep inside a huge mountain. The walls and the\n"+
             "ceiling are covered with cobwebs. You must wade in here, because\n"+
             "the water is swelling high in the chamber. Around the chamber\n"+
             "can be heard the sound of the waterfall echoing.\n";

    add_exit("north", "/wizards/irmeli/valley/tunnel.c");
}
