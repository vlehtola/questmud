You are now in the second floor of the tower.
On the floor there is huge blue carpet which fills
almoust the whole room. Many candles are burning on the
north wall and there are no roof anymore or somehow
sky is now over you. It's very cold and water is dropping
everywhere. Strong wind has broken all the windows.

You are now in the second floor of the tower.
On the floor there is huge blue carpet which fills
almoust the whole room. Many candles are burning on the
north wall and there are no roof anymore or somehow.
sky is now over you. It's very cold now and water is dropping
everywhere. Strong wind has broke all the windows.

inherit "room/room";
object monster;

reset(arg) {

if(!monster)   {

  monster = clone_object("/wizards/moonstar/areas/wasteland/monsut/watere");
  move_object(monster, this_object());
}
if(arg) return;

add_exit("north","/wizards/moonstar/areas/wasteland/torni/room11");
add_exit("east","/wizards/moonstar/areas/wasteland/torni/room14.c");
add_exit("west","/wizards/moonstar/areas/wasteland/torni/room12");

short_desc = "In the tower of blue light";
long_desc = "You are now in the third floor of the tower.\n"+
    "This floor seems to be much smaller one then the second floor.\n"+
    "On the floor there is huge blue carpet which fills\n"+
    "almoust the whole room. Many candles are burning on the\n"+
    "north wall and there are no roof anymore or somehow\n"+
    "sky is now over you. It's very cold and water is dropping\n"+
    "everywhere. Strong wind has broken all the windows.\n"+
    "The whole place seems to be shaking. something big is\n"+
    "moving really near.\n";

items = allocate(4);
items[0] = "sky";
items[1] = "There are very dark clouds on the sky";
items[2] = "carpet";
items[3] = "Carpet is totally blue and it is very wet";


set_light(3);
}


inherit "room/room";
object monster;

reset(arg) {

if(!monster)   {

  monster = clone_object("/wizards/moonstar/areas/wasteland/monsut/watere");
  move_object(monster, this_object());
}
if(arg) return;

add_exit("northeast","/wizards/moonstar/areas/wasteland/torni/room11");
add_exit("east","/wizards/moonstar/areas/wasteland/torni/room13.c");

short_desc = "In the tower of blue light";
More: (line 17)
long_desc = "You are now in the third floor of the tower.\n"+
    "This floor seems to be much smaller one then the second floor.\n"+
    "On the floor there is huge blue carpet which fills\n"+
    "almoust the whole room. Many candles are burning on the\n"+
    "north wall and there are no roof anymore or somehow.\n"+
    "sky is now over you. It's very cold now and water is dropping\n"+
    "everywhere. Strong wind has broke all the windows.\n"+
    "The whole place seems to be shaking now. something big is\n"+
    "moving really near.\n";

items = allocate(4);
items[0] = "sky";
items[1] = "There are very dark clouds on the sky";
items[2] = "carpet";
items[3] = "Carpet is totally blue. It is very wet";

More: (line 33)

set_light(3);
}
