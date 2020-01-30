inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Village of happiness.";
long_desc =
"You are wandering in a small street made out of stone.\n" +
"Some kids are playing on the roadside and people are\n" +
"doing their daily taks. You see small houses everywhere\n" +
"and in the distance there are few small shops. being over\n" +
"here makes you feel home sickness.\n";


add_exit("southwest", "vh10.c");
add_exit("northeast", "/wizards/yodin/areas/village/field/entrance.c");



}
