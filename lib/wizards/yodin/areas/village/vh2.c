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
"You are walking on small road made of stones. Road leads to\n" +
"the village. There are few houses in horizon. Few townsman \n" +
"are walking here and people looks very happy and friendly.\n";

add_exit("northeast", "vh3.c");
add_exit("southwest", "vh1.c");




}
