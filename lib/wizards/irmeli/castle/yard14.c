inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/citizen.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard15.c");
add_exit("south","/wizards/irmeli/castle/yard8.c");
add_exit("west","/wizards/irmeli/castle/yard13.c");
add_exit("northwest","/wizards/irmeli/castle/yard16.c");
add_exit("southwest","/wizards/irmeli/castle/yard4.c");

short_desc = "A grass covered yard in a dilapidated castle of Asgroth";
long_desc = "The grassy lawn is restricted by the high castle walls. The castle is\n"+
            "dilapidated quite badly because the walls are near to tumbling down and\n"+
            "the yard is covered with thick and long grass. If the humans don't repair\n"+
            "the castle soon, they will have to move. When the north wall collapses, water\n"+
            "will flood to the yard and destroy everything. Rocks and decayed pieces of\n"+
            "old boards are among the long grass. A wooden platform is in the middle of the\n"+
            "yard towards west. It rises among the long grass. There are two big towers\n"+
            "rising up to the sky from the north wall reaching all the way to the cloudline.\n";

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
