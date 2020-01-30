inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(3);

add_exit("down","/guilds/abjurer/stairs4.c");
add_exit("up","/guilds/abjurer/masters_of_sorcery.c");

short_desc = "Silver stairs leading into the tower";
long_desc =
"The silver spiral stairs continue rising upwards towards the\n"+
"top of the tower. The spiral stairs and the high tower are both\n"+
"extremely narrow. The brightly burning torches on the grey stone\n"+
"walls light the stairs and the walls perfectly.\n";


   items = allocate(6);
   items[0] = "torches";
   items[1] = "The torches are burning everywhere around you, on the walls of the hall";
   items[2] = "torch";
   items[3] = "The torch is burning on the wall";
   items[4] = "stairs";
   items[5] = "The silver spiral stairs are rising from the ground, upwards the top of the tower";

}
