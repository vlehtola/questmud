inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(2);

add_exit("north","/guilds/abjurer/corridor1.c");
add_exit("out","/guilds/abjurer/entrance.c");

short_desc = "A narrow corridor on the first floor of the tower";
long_desc =
"A narrow, rough looking corridor, leading into the main rooms on the\n"+
"first floor of the tower. Burning torches, placed symmentrically on the\n"+
"grey walls, brings the shape changing shadows on the floor and on the\n"+ 
"walls. The rocky floor is cold and dusty, but the air is warm in here.\n"+ 
"Huge stone doubledoors are open and firmly attached to the walls, they\n"+
"are always open for adventurers who seek for knowledge.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "The torches are burning everywhere around you, on the walls of the corridor";
   items[2] = "torch";
   items[3] = "The torch is burning on the wall";
   items[4] = "door";
   items[5] = "Huge grey stone doubledoor firmly attached to the stone walls";
}
