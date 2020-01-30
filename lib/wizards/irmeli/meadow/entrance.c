inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("south", "/wizards/irmeli/meadow/virtual_map: 35 5");
  add_exit("out", "/wizards/irmeli/meadow/virtual_map: 35 5");

  short_desc = "A narrow defile";
  long_desc = "A narrow defile leading to a huge valley. The valley is surrounded\n"+
              "by the massive rocky mountains. The ground is covered with tall,\n"+
              "green grass and multicolored flowers here and there. A small river\n"+
              "flows through the valley.\n";
}
