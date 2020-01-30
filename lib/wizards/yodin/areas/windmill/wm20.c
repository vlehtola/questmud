inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"This is a narrow path that surrounds the windmill.\n" +
"Around the windmill there are beautiful flowers and few apple\n" +
"trees. Birds are singing very beautifully and butterflies\n" +
"are flying around you.\n";
add_exit("west", "wm7.c");
add_exit("northeast", "wm19.c");

}