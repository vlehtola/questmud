inherit "room/room";
object monster;
reset(arg) {
  if(!present("man")) { 
    move_object(clone_object("/wizards/irmeli/castle/monsters/man.c"),
    this_object());
}

if(arg) return;

add_exit("south","/wizards/irmeli/castle/yard12.c");
add_exit("west","/wizards/irmeli/castle/yard18.c");
add_exit("east","/wizards/irmeli/castle/yard16.c");
add_exit("southwest","/wizards/irmeli/castle/yard11.c");
add_exit("southeast","/wizards/irmeli/castle/yard13.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "A deep well is built here. There are no water in the well. You can't see the\n"+
            "bottom of the well. The high castle walls are surrounding the grassy yard from\n"+
            "every direction. It's dangerous to be near the castle walls because there are\n"+
            "rocks falling down from the castle walls. Among the grass is old decayed boards\n"+
            "and medium-sized stones. In the middle of the yard can be seen a wooden platform\n"+
            "covered with old blood. It's located towards south. There are two big towers\n"+
            "rising up to the sky. Another is towards west and the other towards east.\n";

set_light(4);

   items = allocate(8);
   items[0] = "stones";
   items[1] = "A big pile of medium-sized stones. The stones are probably from the castle walls.";
   items[2] = "boards";
   items[3] = "The ground is covered with boards and nails. You should look where you step on.";
   items[4] = "well";
   items[5] = "The well is drained. A rope is hanging in the well.";
   items[6] = "rope";
   items[7] = "A rope is hanging in the well. You can't see its head.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
init() {
  ::init();
  add_action("climb", "climb");
}

climb(str) {
  if(str != "down") return;
  write("You grab from the rope and slide down to the bottom of the well.\n");
    move_object(this_player(),"/wizards/irmeli/castle/well.c");
    this_player()->look(); 
 return 1;
}