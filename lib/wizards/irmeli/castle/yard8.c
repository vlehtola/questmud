inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/citizen.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("north","/wizards/irmeli/castle/yard14.c");
add_exit("south","/wizards/irmeli/castle/yard7.c");
add_exit("west","/wizards/irmeli/castle/yard4.c");
add_exit("northwest","/wizards/irmeli/castle/yard13.c");
add_exit("southwest","/wizards/irmeli/castle/yard3.c");

short_desc = "A grassy yard inside the castle of Asgroth";
long_desc = "A far-reaching castle yard is covered with green grass. The grass is growing\n"+
            "everywhere even on the walls. You can see old decayed boards and small piles\n"+
            "of rocks all around the yard on spots where the grass is not long. The castle\n"+
            "walls are disintegrating, causing dangerous situations when the rocks drop down\n"+
            "to the yard from them. You can see one rock loosening from the north wall and\n"+
            "smashing down to the yard ten meters from you. The rock rises a huge cloud of\n"+
            "dust. A wooden platform which is covered with old blood has been built in the\n"+
            "the middle of the grassy yard northwest from here. There are two big towers\n"+
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
