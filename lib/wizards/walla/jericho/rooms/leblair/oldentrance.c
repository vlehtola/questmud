inherit "room/room";
int i;
int uhrac=0,kelju=0;
object boretus;
 
reset(arg) {
 
  add_exit("south","/wizards/walla/jericho/rooms/tneb1");
  short_desc = "At a dead end";
  long_desc = "You are standing on a small gravel path that leads nowhere. Up ahead lies a \n"+
              "huge limestone wall, that blocks your way further. A strange symbol can be spotted\n"+
              "on the wall though. If you look closer, it seems to represent a 5-pointed star.\n"+
              "Besides, an eerie feeling creeps up on you, as you stand here.\n";
}
init()
{
 
 
::init();
add_action("north","north");
add_action("place","place");
}
place(string str) {
if(!str) { write("Place what?\n"); return; }

boretus=present("necklace0407432002",this_player());

if(!boretus) {
write("You don't have the right stuff to push the wall.\n");
return;
}

/*

 if(!(uhrac && kelju))  {
  write("The necklace fits, but it seems you've forgotten to do something.\n");  
  return;
                        }

 */

 write("You push the wall and silent click can be heard.\n"+
       "But just when you're about to take the necklace back, it slips\n"+
       "from your fingers, and falls to the ground, shattering to millions\n"+
      "of pieces.\n");
 destruct(boretus);
 add_exit("north","/wizards/walla/jericho/rooms/leblair/leblair1");
 i = 1;
 return 1;
}

north() {
if(!i) {
write("There is a huge wall in front of you, which you cannot pass.\n");
return 1;
}
call_other("/wizards/walla/jericho/rooms/leblair/leblair1","joku_tuli",this_player()->query_name());
}

set_done(string str) {
if(str=="uhrac") uhrac=1;
if(str=="kelju") kelju=1;
return;
}

