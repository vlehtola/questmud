inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(2);

add_exit("south","/guilds/abjurer/abjurers.c");
add_exit("east","/guilds/abjurer/stairs1.c");
add_exit("west","/guilds/abjurer/stairs4.c");

short_desc = "A narrow corridor on the first floor of the tower";
long_desc =
"A narrow, rough looking corridor, connects the main rooms on the first\n"+
"floor of the tower. Burning torches, placed symmentrically on the grey\n"+
"walls, brings the shape changing shadows on the floor and on the walls.\n"+
"The rocky floor is cold and dusty, but the air is warm in here. A huge\n"+
"marble hall is in the centre of the tower, towards south.\n";

   items = allocate(4);
   items[0] = "torches";
   items[1] = "The torches are burning everywhere around you, on the walls of the corridor";
   items[2] = "torch";
   items[3] = "The torch is burning on the wall";
}
