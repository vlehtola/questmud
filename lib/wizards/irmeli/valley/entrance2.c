inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/irmeli/valley/virtual_map: 26 21");
  add_exit("out", "/wizards/irmeli/valley/entrance.c");

  short_desc = "A narrow defile";
  long_desc = "A narrow defile leading to a huge valley. The valley is surrounded\n"+
              "by the massive rocky mountains. The ground is covered with tall,\n"+
              "green grass and multicolored flowers here and there. A small river\n"+
              "flows through the valley.\n";
}
