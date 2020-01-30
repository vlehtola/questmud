inherit "room/room";
object deer;

reset(arg)
{
if(!deer) {
 deer = clone_object("/wizards/yodin/areas/forest/monsters/deer");
 move_object(deer, this_object());
 }

if(arg) return;


short_desc = "small odd room.";
long_desc =
"roooom \n" +
" \n" +
" \n" +
"\n";


add_exit("northeast", "vl11.c");
add_exit("southeast", "vl8.c");
add_exit("jump", "/u2/vl9.c");
add_exit("dig", "/wizards/yodin/areas/weird_land/vl9.c");
items = allocate (4);
items[0] = "emt";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bushes";
items[3] = "These bushes are some short of berrybushes.\n";




 }
