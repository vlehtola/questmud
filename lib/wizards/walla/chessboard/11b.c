inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/chessboard/monsters/wtower");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","/wizards/walla/chessboard/12");
  add_exit("south","/wizards/walla/chessboard/21");
  add_exit("southeast","/wizards/walla/chessboard/22");
    short_desc = "On a white square on the chessboard";
  long_desc =
"You are on a white square on the chessboard\n" +
"This is the place of the white tower.\n";
 
 
}
