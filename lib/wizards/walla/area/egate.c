inherit "room/room";
 
object monster,monster2;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area/monsters/gguard");
    move_object(monster, this_object());
  }
  if(!monster2) {
    monster2 = clone_object("/wizards/walla/area/monsters/gguard2");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/area/estreet1");
  short_desc = "The drawbridge";
  long_desc =
"You are now on a the drawbridge to Jericho. It is has been built\n" +
"to prevent any enemies getting into the city.\n" +
"To the west, lies the city built by Leb-Kamar and his men.\n";
 
}

