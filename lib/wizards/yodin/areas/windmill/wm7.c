inherit "room/room";
object peacock;
reset(arg)
{
if(!peacock) {
 peacock = clone_object("/wizards/yodin/areas/windmill/monsters/peacock.c");
 move_object(peacock, this_object());
 }

if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"You are standing in front of a huge windmill.\n" +
"The windmill has been painted with red and white and \n" +
"there are large paddles on the side of it. Open \n" +
"door leads in to the windmill.\n";
add_exit("east", "wm20.c");
add_exit("west", "wm10.c");
add_exit("enter", "wm8.c");
add_exit("south", "wm6.c");

}