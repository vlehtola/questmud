inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/gheldor/castle/vmap: 26 21");
  add_exit("west", "/wizards/gheldor/workroom.c");
  call_other("/wizards/gheldor/castle/vmap.c", "start_map");
  short_desc = "An entrance to the castle area";
  long_desc = "A narrow defile leading to a huge valley. The valley is surrounded\n"+
              "by the massive rocky mountains. The ground is covered with tall,\n"+
              "green grass and multicolored flowers here and there. A small river\n"+
              "flows through the valley.\n";
}
