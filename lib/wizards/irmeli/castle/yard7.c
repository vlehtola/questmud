inherit "room/room";
object monster;
reset(arg) {
if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard8.c");
add_exit("west","/wizards/irmeli/castle/yard3.c");
add_exit("northwest","/wizards/irmeli/castle/yard4.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "A beautiful green grass lawn has conquered the castle yard and even the castle\n"+
            "walls in some spots. The high castle walls are surrounding the grassy yard from\n"+
            "every direction. It's dangerous to be near the castle walls because there are\n"+
            "rocks falling down from them. Among the grass there are old decayed boards\n"+
            "and medium-sized stones. In the middle of the yard can be seen a wooden platform\n"+
            "covered with old blood. The platform is located towards northwest. There are two\n"+
            "big towers rising up to the sky from the north wall reaching all the way to the\n"+
            "cloudline.\n";
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
