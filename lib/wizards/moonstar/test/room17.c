inherit "room/room";
object monster, monster1;

reset(arg) {

     if(arg) return;
clone_object("/wizards/moonstar/areas/wasteland/monsut/skeleton");
    move_object(monster, this_object());

    monster1 = clone_object("/wizards/moonstar/areas/wasteland/monsut/snake");
    move_object(monster1, this_object());
    
    short_desc = "wasteland";
    long_desc = "^ww  People call this Wasteland.\n"+
"w*w  You see dead trees here and there. The land is\n"+
"w^^  dust, few rocks lay on the ground making it to look\n"+
"     more deserted. The everlasting darkness\n"+
"     remains here.\n";
    set_light(5);
add_exit("north" , "/wizards/moonstar/areas/wasteland/room6.c");
add_exit("northeast" , "/wizards/moonstar/areas/wasteland/room7.c");
add_exit("west" , "/wizards/moonstar/areas/wasteland/room16.c");
add_exit("east" , "/wizards/moonstar/areas/wasteland/room18.c");
add_exit("southwest" , "/wizards/moonstar/areas/wasteland/room27.c");
}

