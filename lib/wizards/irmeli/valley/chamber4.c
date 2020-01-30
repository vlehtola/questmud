inherit "room/room";
object monster;

reset(arg) {
  if(!present("spider")) { 
    move_object(clone_object("/wizards/irmeli/valley/monsters/spider"),
    this_object());
 }

 if (arg) { return; }

 set_not_out(1);

 short_desc = "An old chamber";
 long_desc = "An old chamber driven inside a huge mountain. The ceiling, ground and\n"+
             "walls are rough and covered with cobwebs and dust. A huge cleft is in\n"+
             "the ground at the far end of the chamber. The sound of waterfall\n"+
             "echoes all around the chamber.\n";

    add_exit("south", "/wizards/irmeli/valley/tunnel2.c");

  items = allocate(2);
  items[0] = "cleft";
  items[1] = "A huge cleft, in the ground, is full of translucid water"; 
}
