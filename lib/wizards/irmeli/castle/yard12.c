inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
if(!monster) { 
monster = clone_object("/wizards/irmeli/castle/monsters/executioner.c");
move_object(monster, this_object());
}

add_exit("north","/wizards/irmeli/castle/yard17.c");
add_exit("south","/wizards/irmeli/castle/yard1.c");
add_exit("west","/wizards/irmeli/castle/yard11.c");
add_exit("east","/wizards/irmeli/castle/yard13.c");
add_exit("northwest","/wizards/irmeli/castle/yard18.c");
add_exit("northeast","/wizards/irmeli/castle/yard16.c");
add_exit("southwest","/wizards/irmeli/castle/yard5.c");
add_exit("southeast","/wizards/irmeli/castle/yard4.c");

short_desc = "A wooden platform";
long_desc = "A wooden platform has been built in the middle of the yard. It's surrouded by the\n"+
            "long grass. The platform is made of wood. It's quite big, three metres long and two\n"+  
            "metres wide. A bloody block of wood is placed in the middle of the platform. There\n"+
            "are two ropes hanging from the plank which is above your head. There are couple fresh\n"+ 
            "and bloody heads lying on the ground. You can't see any bodies around. There are two\n"+
            "big towers rising up to the sky from the north wall.\n";

set_light(4);

   items = allocate(8);
   items[0] = "platform";
   items[1] = "It's made of wood. Covered with fresh and old blood."; 
   items[2] = "block";
   items[3] = "The block made of wood is bloody. It's placed in the middle of the platform.";
   items[4] = "ropes";
   items[5] = "Two ropes are hanging from the plank.";
   items[6] = "heads";
   items[7] = "Two heads are lying on the ground. They are fresh and bloody.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
