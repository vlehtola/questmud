inherit "room/room";  
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/wife");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/walla/peepseye/kitty/m2");
  short_desc = "In a normal city house.";
  long_desc =
"The house that you have entered contains nothing but a large room,\n" +
"in which there is a bed in one corner, and a fireplace and a table in \n" +
"the other. There is a busy housewife here, but she seems much too\n" +           
"stressed to talk to you.\n";

}
 


