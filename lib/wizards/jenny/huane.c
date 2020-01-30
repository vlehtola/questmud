inherit "room/room";

  reset(arg) {
    add_exit("west", "/wizards/jenny/workroom.c");
    short_desc = "testihuane";
    long_desc = "jennyn pieni testihuone jossa on kaikkea kivaa\n"+
           "myos pieni takka on taalla\n";
set_not_out(1);
set_light(3);
}
