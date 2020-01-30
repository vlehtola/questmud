inherit "room/room";
object mob,mob2;
reset(arg)
{

if(!mob) {
 mob = clone_object("/wizards/yodin/areas/village/monsters/man");
 move_object(mob, this_object());
 }
if(!mob2) {
 mob2 = clone_object("/wizards/yodin/areas/village/monsters/woman");
 move_object(mob2, this_object());
 }
if(arg) return;


short_desc = "Village of happiness.";
long_desc =
"You are wandering in a small street made out of stone.\n" +
"Some kids are playing on the roadside and people are\n" +
"doing their daily taks. You see small houses everywhere\n" +
"and in the distance there are few small shops. being over\n" +
"here makes you feel home sickness.\n";

add_exit("east", "vh20.c");
add_exit("west", "vh22.c");



}
