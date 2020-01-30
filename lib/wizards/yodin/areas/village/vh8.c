inherit "room/room";
object mob,mob2;
reset(arg)
{
if(!mob) {
 mob = clone_object("/wizards/yodin/areas/village/monsters/boy");
 move_object(mob, this_object());
 }
if(!mob2) {
 mob2 = clone_object("/wizards/yodin/areas/village/monsters/woman");
 move_object(mob2, this_object());
 }

if(arg) return;


short_desc = "Village of happiness.";
long_desc =
"You are walking in beautifully made stone street. \n" +
"There are few small houses around you and some \n" +
"happy looking people are walking all around you.\n" +
"You start to feel very happy too just being in this\n" +
"cosy village.\n";

add_exit("north", "vh12.c");
add_exit("northeast", "vh9.c");
add_exit("northwest", "vh7.c");
add_exit("south", "vh20.c");



}
