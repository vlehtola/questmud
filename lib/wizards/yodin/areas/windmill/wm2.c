inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"You are walking on the path that lead to the\n" +
"Duranghom's windmill. Path is of bumpy rocks.\n" +
"Far ahead you see beautiful windmill. Windmill is \n" +
"made out of wood and it is painted with red and white\n" +
"paint.\n";

add_exit("north", "wm3.c");
add_exit("south", "wm1.c");


}