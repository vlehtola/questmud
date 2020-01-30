inherit "room/room";
object bunny;
reset(arg)
{
if(!bunny) {
 bunny = clone_object("/wizards/yodin/areas/windmill/monsters/bunny.c");
 move_object(bunny, this_object());
 }

if(arg) return;


short_desc = "Duranghom's windmill.";
long_desc =
"This must be the resting place for travellers.\n" +
"There is red bench under a large tree. Far ahead\n" +
"you see a large windmill.\n";

add_exit("east", "wm3.c");


}