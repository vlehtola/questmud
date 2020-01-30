inherit "room/room";
object monster,monster2;


reset(arg) {

  if(!present("mummy")) {
    move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
}

  if(arg) return;

  add_exit("west","/wizards/devil/area/huoneet/r54.c");
  add_exit("east","/wizards/devil/area/huoneet/r60.c");
  add_exit("north","/wizards/devil/area/huoneet/r58.c");
  add_exit("down","/wizards/devil/area/huoneet/r52.c");

  short_desc = "Central hall in the huge temple";
  long_desc = "This is the central hall in this huge and beautiful temple. This temple\n"+
           "was made hundreds years ago in an old-fashion way. There is a big cross\n"+
           "on the wall reminding you of the sufferings of Jesus.\n";

}
