inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/lookout");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("down","rampart_5");
  short_desc = "In the southwestern tower";
  long_desc =
  long_desc =
"You are standing in one of the guardtowers, used to look out for people in the valley below.\n" +
"The tower is manned by a lookout, that is to be present at all times. The tower has several\n" +
"windows in many directions, from which the lookout can keep a good view of the surrounding\n" +
"areas.\n";
 
}
