inherit "room/room";
object monster;
reset(arg) {
if(!monster) { 
monster = clone_object("/wizards/irmeli/castle/monsters/citizen.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("north","/wizards/irmeli/castle/yard12.c");
add_exit("south","/wizards/irmeli/castle/yard.c");
add_exit("west","/wizards/irmeli/castle/yard5.c");
add_exit("east","/wizards/irmeli/castle/yard4.c");
add_exit("northwest","/wizards/irmeli/castle/yard11.c");
add_exit("northeast","/wizards/irmeli/castle/yard13.c");
add_exit("southwest","/wizards/irmeli/castle/yard2.c");
add_exit("southeast","/wizards/irmeli/castle/yard3.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "The yard is huge. There is long grass growing all around the yard and even on\n"+
            "the walls. Somebody should cut the grass before it grows too long and makes the\n"+  
            "moving here impossible. The grass smells good. It reminds you from your youth.\n"+
            "The walls of the castle surround the yard. It's dangerous to be near the walls\n"+ 
            "because they are disintegrating and some rocks are falling down with an\n"+
            "incredible speed. It would be a mess if the rock would hit you in the head.\n"+  
            "The castle has lost its flourish recently. A wooden platform which is covered\n"+
            "with old blood has been built in the middle of the grassy yard towards north\n"+
            "from here. There are two big towers rising up to the sky from the north wall.\n";

set_light(4);

   items = allocate(2);
   items[0] = "stones";
   items[1] = "A big pile of medium-sized stones. The stones are probably from the castle walls."; 

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
