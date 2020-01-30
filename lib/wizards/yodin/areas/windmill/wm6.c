inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"You are walking in the path that leads to the windmill.\n" +
"Path is made of stones and it is easy to walk. In front \n" +
"of you is a large windmill. Few trees can be seen in distance.\n";
add_exit("south", "wm3.c");
add_exit("north", "wm7.c");

}