inherit "room/room";                  
object monster,monster2;
reset(arg) {
  if (!monster) {
  monster = clone_object("/wizards/walla/area/monsters/privateer");
  move_object(monster, this_object());
}
  if (!monster2) {
  monster2 = clone_object("/wizards/walla/area/monsters/lebkamar");
  move_object(monster2, this_object());
 }
 if(arg) return;

add_exit("out","/wizards/walla/area/cs");
add_exit("maze","/wizards/walla/area/wrongway4");
short_desc = "This is Leb-Kamars secret chambers",
long_desc =  "You are in a great hall, covered with paintings and plans. Leb-Kamar seems to\n"+
             "be working on something, so he doesn't like your presence. \n";
}

