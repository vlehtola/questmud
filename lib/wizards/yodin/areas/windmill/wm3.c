inherit "room/room";
object bunny, bunny2, bunny3;
reset(arg)
{
if(!bunny) {
 bunny = clone_object("/wizards/yodin/areas/windmill/monsters/bunny.c");
 move_object(bunny, this_object());
 }

if(!bunny2) {
 bunny2 = clone_object("/wizards/yodin/areas/windmill/monsters/bunny.c");
 move_object(bunny2, this_object());
 }
if(!bunny3) {
 bunny3 = clone_object("/wizards/yodin/areas/windmill/monsters/bunny.c");
 move_object(bunny3, this_object());
 }


if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"You are walking on the path that lead to the\n" +
"Duranghom's windmill. Path is of bumpy rocks.\n" +
"Far ahead you see beautiful windmill. Windmill is \n" +
"made out of wood and it is painted with red and white\n" +
"paint. The path crosses to east and west from here.\n";

add_exit("north", "wm6.c");
add_exit("south", "wm2.c");
add_exit("west", "wm4.c");
add_exit("east", "wm5.c");





}