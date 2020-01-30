inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard5.c");
add_exit("west","/wizards/irmeli/castle/yard6.c");
add_exit("east","/wizards/irmeli/castle/yard.c");
add_exit("northwest","/wizards/irmeli/castle/yard9.c");
add_exit("northeast","/wizards/irmeli/castle/yard1.c");
add_exit("stairs","/wizards/irmeli/castle/wall1.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "A huge yard full of green grass was once a upon time full of happy people.\n"+
            "Nowadays it's just a memory of the good old times. The yard was full of\n"+
            "wooden houses where people lived but those were recently torn down to\n"+
            "pieces. Therefore the yard is full of old decayed boards with sharp nails.\n"+
            "The yard is surrounded by the disintegrating castle walls. There are stairs\n"+
            "leading to the top of the castle walls on the south wall. The ground is\n"+
            "full of stones, probably from the castle walls. There are two big towers\n"+ 
            "rising up to the sky from the north wall.\n";

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
