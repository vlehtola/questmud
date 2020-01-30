inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("south","/wizards/irmeli/castle/yard13.c");
add_exit("west","/wizards/irmeli/castle/yard17.c");
add_exit("east","/wizards/irmeli/castle/yard15.c");
add_exit("southwest","/wizards/irmeli/castle/yard12.c");
add_exit("southeast","/wizards/irmeli/castle/yard14.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "The yard ends suddenly. The high castle walls are surrounding the grassy yard\n"+
            "from every direction. It's dangerous to be near the castle walls because there\n"+
            "are rocks falling down from them. Among the grass, there are old decayed boards\n"+
            "and medium-sized stones. In the middle of the yard can be seen a wooden platform\n"+
            "covered with old blood. It's located towards southwest. A well can be seen\n"+
            "couple meters ahead in west. There are two big towers rising up to the sky.\n"+
            "Another is towards west and the other towards northeast.\n";

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
