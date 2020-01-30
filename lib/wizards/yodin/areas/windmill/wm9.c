inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"This is the mill's machinery room. The paddles\n" +
"of the windmill are all attached to several feet length\n" +
"pole powering the mill mechanism which is crumbling the\n" +
"seeds into a flour. The light is able to shine here from\n" +
"few small windows.\n";

add_exit("south", "wm8.c");

move_object(clone_object("/wizards/yodin/areas/windmill/monsters/man.c"), this_object());

}