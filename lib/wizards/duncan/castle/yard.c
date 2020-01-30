inherit "room/room";
object monster;
reset(arg) {
if(!monster) { 
monster = clone_object("/wizards/duncan/castle/monsters/citizen.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("north","/wizards/duncan/castle/yard1.c");
add_exit("south","/wizards/duncan/castle/r1.c");
add_exit("west","/wizards/duncan/castle/yard2.c");
add_exit("east","/wizards/duncan/castle/yard3.c");
add_exit("northwest","/wizards/duncan/castle/yard5.c");
add_exit("northeast","/wizards/duncan/castle/yard4.c");

short_desc = "A grassy yard inside the castle of 'Thousand Storms'";
long_desc = "A huge castle yard full of grass opens in front of your eyes. There is long\n"+
            "grass growing all around the yard and even on the walls. Somebody should cut\n"+     
            "the grass before it grows too long and makes the moving here impossible. The\n"+ 
            "walls of the castle surround the yard. The walls look smaller from here,\n"+
            "inside the castle. It's dangerous to be near the walls because they are\n"+ 
            "disintegrating and some rocks are falling down with an incredible speed. It\n"+
            "would be a mess if the rock would hit you in the head. The castle has lost\n"+  
            "its flourish recently. There are two big towers rising up to the sky from\n"+ 
            "the north wall. The towers are about fifty meters high.\n";

set_light(4); 

 property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
