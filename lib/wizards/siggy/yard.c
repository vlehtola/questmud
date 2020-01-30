inherit "room/room";
object monster;
reset(arg) {
if(!monster) { 
monster = clone_object("/wizards/irmeli/castle/monsters/baby.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("north","/wizards/irmeli/castle/yard1.c");
add_exit("south","/wizards/irmeli/castle/r1.c");
add_exit("west","/wizards/irmeli/castle/yard2.c");
add_exit("east","/wizards/irmeli/castle/yard3.c");
add_exit("northwest","/wizards/irmeli/castle/yard5.c");
add_exit("northeast","/wizards/itmeli/castle/yard4.c");

short_desc = "Yard of the castle of ogres called as 'Judgement'";
long_desc = "A huge castle yard opens in front your eyes, as you step inside the gate.\n"+
            "The walls of the castle surrounds the yard, but luckily you are now inside\n"+
            "those walls. The walls looks smaller, from here, inside the castle. It's\n"+
            "dangerous to be near the walls, because they are disintegrating and some\n"+  
            "rocks are falling down. The castle lost its flourish, when the humans left\n"+
            "from here. The grass is growing everywhere, on the ground, on the walls and\n"+
            "on the houses.\n";
}
