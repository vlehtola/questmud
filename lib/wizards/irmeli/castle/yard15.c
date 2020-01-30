inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("south","/wizards/irmeli/castle/yard14.c");
add_exit("west","/wizards/irmeli/castle/yard16.c");
add_exit("southwest","/wizards/irmeli/castle/yard13.c");
add_exit("northeast","/wizards/irmeli/castle/yard21.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "You are standing next to the north wall. The high castle walls surround the\n"+
            "grassy yard from every direction. There are old decayed boards and medium-\n"+
            "sized stones among the long grass. It's dangerous to be near the castle \n"+
            "walls because there are rocks falling down from them. In the middle of the\n"+
            "yard can be seen a wooden platform which is covered with blood. It's\n"+
            "located towards southwest. A well is towards west. There are two big towers\n"+
            "rising up to the sky. Another is towards west and the other towards\n"+
            "northeast.\n";

set_light(4);

   items = allocate(4);
   items[0] = "stones";
   items[1] = "A big pile of medium-sized stones. The stones are probably from the castle walls.";
   items[2] = "boards";
   items[3] = "The ground is covered with boards and nails. You should look where you step on.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
