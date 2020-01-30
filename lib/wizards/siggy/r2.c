inherit "room/room";
object monster;
if(!monster) { 
move_object(monster, this_object());
}
if(arg) return;
add_exit("south","/wizards/trooper/areas/muhoscity/r1.c");
add_exit("west","/wizards/trooper/areas/muhoscity/r3.c");
add_exit("north","/wizards/trooper/areas/necropolis/r1.c");

short_desc = " First crossroad";
long_desc = "Dense fog surrounds this road and you hear wolves howling somewhere,\n"+
            "scary. This road is really used. You can see it from footsteps, from many footsteps.\n"+
            "Sign is at center of this crossroad.\n";
            
items = allocate(2);
items[0] = "sign";
items[1] = "sign reads: West, sacred lands. North, inner city.";
}

