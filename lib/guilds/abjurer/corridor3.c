inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(2);

add_exit("north","/guilds/abjurer/stairs1.c");
add_exit("south","/guilds/abjurer/stairs2.c");

short_desc = "A corridor lit up with torches on the first floor of the tower";
long_desc =
"A corridor lit up with burning torches, connects the main rooms on the first\n"+
"floor of the tower. The corridor is quite simple looking, the rocky walls,\n"+
"rough floor and low roof, gives the hole describe to the corridor. The rocky\n"+
"walls are full of burning torches, four on each wall. The cold and dusty\n"+
"floor is rough.\n";

   items = allocate(4);
   items[0] = "torches";
   items[1] = "The torches are burning everywhere around you, on the walls of the corridor";
   items[2] = "torch";
   items[3] = "The torch is burning on the wall";
}
