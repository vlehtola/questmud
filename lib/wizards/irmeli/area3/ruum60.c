inherit "room/room";  

reset(arg) {
  add_exit("up","/wizards/irmeli/area3/ruum60.c");
  add_exit("south","/wizards/irmeli/area3/ruum53.c");
  set_not_out(1);

  short_desc = "Small aisle in the back of the temple";
  long_desc = "This aisle is leading you to the back of the temple. Aisle was meaby used\n"+
                "by the staff who served in here because aisle is regular and there is\n"+
                "nothing unusual things like paintings on the wall. There is small\n"+
                "stairs on the easternwall leading upwards to the next floor.\n";
}

