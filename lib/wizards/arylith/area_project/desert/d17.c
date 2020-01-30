inherit "room/room";
object worm;

reset(arg) {
if(!worm) {
worm = clone_object("/wizards/arylith/area_project/monsters/worm");
move_object(worm, this_object());
if(arg) { return; } 
}
add_exit("southwest", "/wizards/arylith/area_project/desert/d13");
add_exit("west", "/wizards/arylith/area_project/desert/d14");
add_exit("northwest", "/wizards/arylith/area_project/desert/d15");
add_exit("north", "/wizards/arylith/area_project/desert/d18");
add_exit("northeast", "/wizards/arylith/area_project/desert/d21");
add_exit("east", "/wizards/arylith/area_project/desert/d20");
add_exit("southeast", "/wizards/arylith/area_project/desert/d19");
add_exit("south", "/wizards/arylith/area_project/desert/d16");

short_desc = "The desert.\n";
long_desc = "This is the desert, only thing you can see is sand\n"+
            "everywhere and some monsters roaming around.\n";
}
