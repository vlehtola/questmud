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
"You have arrived to a cosy and comfortable small village.\n" +
"The road is made out of white stones and you can't see any\n" +
"trash on the ground. Some people are walking by and they\n" +
"seem to be very happy to see you coming towards.\n";

add_exit("northwest", "vh1.c");
add_exit("south", "vh23.c");



}
