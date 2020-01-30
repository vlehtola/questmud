inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/dl/monsters/wellguard");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","/wizards/walla/dl/rooms/xaktsaroth/lvl1room1");
  add_exit("east","/wizards/walla/dl/rooms/xaktsaroth/pathsofdead1");
  add_exit("west","/wizards/walla/dl/rooms/xaktsaroth/templeentrance");
  short_desc = "A great big room with a well in the middle";
  long_desc =
"This room is considerably bigger than any of the previous rooms\n" +
"which makes you feel more and more insecure about the whole place.\n" +
"In the middle stands a well, covered with dust and a strong looking\n" +
"lid. The well seems to have been forgotten for many years, and what\n" +
"makes you even more creepy is that you here noises from below it.\n";
 
  items = allocate(4);
  items[0] = "well";
  items[1] = "The lid of the well sits stuck. You could try to force it open, but beware...";
 
}
init() {
  ::init();
  add_action("force", "force");
}
 
force(str) {
  if(str != "lid") return;
 write("You pull the lid with all your strength, and just as you're about to give up the lid craks open.\n");
  say("The lid gives away after a hard struggle.\n");
  add_exit("well","/wizards/walla/dl/rooms/xaktsaroth/well1");
  return 1;
}
 
 
