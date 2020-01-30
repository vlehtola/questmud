inherit "room/room";

reset(arg) {

if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard18.c");
add_exit("south","/wizards/irmeli/castle/yard5.c");
add_exit("east","/wizards/irmeli/castle/yard12.c");
add_exit("west","/wizards/irmeli/castle/yard10.c");
add_exit("northeast","/wizards/irmeli/castle/yard17.c");
add_exit("northwest","/wizards/irmeli/castle/yard19.c");
add_exit("southeast","/wizards/irmeli/castle/yard1.c");
add_exit("southwest","/wizards/irmeli/castle/yard9.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "The grassy lawn which is surrounded by the castle walls is somekind of a yard,\n"+
            "or it was a castle yard long ago. Nowadays the green grass lawn has conquered\n"+
            "the yard. The grass is so long that you have to struggle to get forward. The\n"+
            "yard is full of decayed boards, probably from houses which were torn to\n"+
            "pieces. There is a wooden platform full of old blood in the middle of the\n"+
            "yard located towards east. There are two big towers rising up to the sky\n"+
            "from the north wall reaching all the way to the cloudline.\n";

set_light(4);

   items = allocate(6);
   items[0] = "stones";
   items[1] = "A big pile of medium-sized stones. The stones are probably from the castle walls.";
   items[2] = "boards";
   items[3] = "The ground is covered with boards and nails. You should look where you step on.";
   items[4] = "head";
   items[5] = "A head is lying amog the grass. How the hell it got there?";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
