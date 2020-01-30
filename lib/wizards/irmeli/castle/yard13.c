inherit "room/room";

reset(arg) {

if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard16.c");
add_exit("south","/wizards/irmeli/castle/yard4.c");
add_exit("east","/wizards/irmeli/castle/yard14.c");
add_exit("west","/wizards/irmeli/castle/yard12.c");
add_exit("northeast","/wizards/irmeli/castle/yard15.c");
add_exit("northwest","/wizards/irmeli/castle/yard17.c");
add_exit("southeast","/wizards/irmeli/castle/yard8.c");
add_exit("southwest","/wizards/irmeli/castle/yard1.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "A grassy lawn which is surrounded by the castle walls is somekind of yard or it was\n"+
            "ago a castle yard. Nowadays the green grass lawn has conquered the yard. The grass\n"+
            "is so long that you have to struggle to get ahead. The yard is full of decayed\n"+
            "boards probably from houses which were teared to pieces. Ground is also covered with\n"+ 
            "old bloodstains. A head is lying among the long grass. There is a wooden platform\n"+ 
            "full of old blood in the middle of the yard located towards west. There are two\n"+ 
            "big towers rising up to the sky from the north wall reaching all the way to the\n"+
            "cloudline.\n";

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
