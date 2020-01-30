inherit "room/room";
object pigeon;
reset(arg)
{
if(!pigeon) {
 pigeon = clone_object("/wizards/yodin/areas/windmill/monsters/pigeon.c");
 move_object(pigeon, this_object());
 }


if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"This is a narrow path that surrounds the windmill.\n" +
"Around the windmill there are beautiful flowers and few apple\n" +
"trees. Birds are singing very beautifully and butterflies\n" +
"are flying around you.\n";
add_exit("west", "wm15.c");
add_exit("southeast", "wm17.c");


}