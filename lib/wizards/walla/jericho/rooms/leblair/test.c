inherit "room/room";
int i;
 
reset(arg) {
 
  add_exit("east","/wizards/walla/workroom");
  short_desc = "testihuone";
  long_desc = "The room, that you have just entered, is surely one of the more frightening\n"+
              "places you've ever seen. The ground is covered with blood, and remainders of\n"+
              "brave adventurers can bee seen in heaps. On the walls, you can see chandeliers\n"+
              "that give some light to this room.\n";
}
init()
{
 
 
::init();
add_action("north","north");
add_action("place","place");
}
place(string str) {
if(!str) {
  write("Place what?\n");
   return;
}
if(!present("necklace",this_player())) {
write("You don't have the right stuff to push the wall.\n");
return;
}
 write("You push the wall and silent click can be heard.\n"+
       "But just when you're about to take the necklace back, it slips\n"+
       "from your fingers, and falls to the ground, shattering to millions\n"+
      "of pieces.\n"); 
 destruct(present("necklace",this_player()));
 add_exit("north","/wizards/walla/jericho/rooms/leblair/leblair1");
 i = 1;
 return 1;
}
north() {
if(!i) {
write("There is a huge wall in front of you, which you cannot pass.\n");
return;
}
call_other("/wizards/walla/jericho/rooms/leblair/leblair1","joku_tuli",this_player()->query_name());
}
 

