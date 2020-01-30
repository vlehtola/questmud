
inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/tsea1");
   return 1;
}
object monster,monster2;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/entryguard");
    move_object(monster, this_object());
  }
 
  if(!monster2) {
     monster2 = clone_object("/wizards/walla/jericho/mobs/entryguard");
     move_object(monster2, this_object());
   }
 
  if(arg) return;
  add_exit("south","out: 83 55");
  add_exit("north","ujar5");
  short_desc = "The southern gate";
  long_desc =
"You are standing on a drawbridge, leading to the city of Jericho. Ther southern gate\n" +
"is nowadays heavily guarded, to keep unwanted people out of the city. The drawbridge has\n" +
"been lowered recently, and the city now welcomes visitors.\n";
}
