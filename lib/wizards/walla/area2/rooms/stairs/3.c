inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/area2/mobs/cat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("down","wizards/walla/area2/rooms/stairs/2");
  add_exit("up","wizards/walla/area2/rooms/stairs/4");
  short_desc = "A good way up on the stairs";
  long_desc =
"You are a good way up on the stirs. The grounds below you start\n" +
"to disappear, although ahead of you, mountains still stand very\n" +
"high above you. A frisk mountain breeze has caught up with you,\n" +
"and blows gently in your hair. The low hanging clouds are ever \n" +
"closer to you.\n";
 
}
