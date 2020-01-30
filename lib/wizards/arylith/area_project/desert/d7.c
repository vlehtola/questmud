inherit "room/room";
object worm;

reset(arg) {
if(!worm) {
worm = clone_object("/wizards/arylith/area_project/monsters/worm");
move_object(worm, this_object());
if(arg) { return; } 
}
add_exit("west", "/wizards/arylith/area_project/desert/d4");
add_exit("northwest", "/wizards/arylith/area_project/desert/d5");
add_exit("north", "/wizards/arylith/area_project/desert/d8");
add_exit("northeast", "/wizards/arylith/area_project/desert/d11");
add_exit("east", "/wizards/arylith/area_project/desert/d10");

short_desc = "The desert.\n";
long_desc = "This is the desert, only thing you can see is sand\n"+
            "everywhere and some monsters roaming around.\n";
}
