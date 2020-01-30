inherit "room/room";
object worm;

reset(arg) {
if(!worm) {
worm = clone_object("/wizards/arylith/area_project/monsters/worm");
move_object(worm, this_object());
if(arg) { return; } 
}
add_exit("west", "/wizards/arylith/area_project/desert/d12");
add_exit("southwest", "/wizards/arylith/area_project/desert/d11");
add_exit("south", "/wizards/arylith/area_project/desert/d14");
add_exit("southeast", "/wizards/arylith/area_project/desert/d17");
add_exit("east", "/wizards/arylith/area_project/desert/d18");

short_desc = "The desert.\n";
long_desc = "This is the desert, only thing you can see is sand\n"+
            "everywhere and some monsters roaming around.\n";
}
