inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(3);

add_exit("north","/guilds/abjurer/corridor4.c");
add_exit("east","/guilds/abjurer/corridor1.c");
add_exit("up","/guilds/abjurer/stairs7.c");

short_desc = "A small hall on the first floor of the tower";
long_desc =
"Golden spiral stairs are in the middle of this small hall, which is located\n"+
"on the first floor of the tower. The spiral stairs are rising upwards through\n"+
"the ceiling, towards the top of the tower. A huge hole can be spotted in the\n"+
"ceiling, where the spiral stairs goes through. Light and warmth comes from\n"+
"the torches, which are burning on the grey stone walls. As you walk in the\n"+
"hall, you can hear your own footsteps echoing around the hall.\n";

   items = allocate(8);
   items[0] = "torches";
   items[1] = "The torches are burning everywhere around you, on the walls of the hall";
   items[2] = "torch";
   items[3] = "The torch is burning on the wall";
   items[4] = "stairs";
   items[5] = "The golden spiral stairs are rising from the ground, upwards the top of the tower";
   items[6] = "hole";
   items[7] = "A big hole in the ceiling, where the spiral stairs goes through";
}
