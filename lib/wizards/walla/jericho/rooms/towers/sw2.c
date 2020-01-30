inherit "room/room";
 
void init() {
::init();
call_other("/wizards/walla/jericho/rooms/towers/explore_d.c","check_rooms",this_object());
}
 
object monster;
 
reset(arg) {
  if(arg) return;
  add_exit("down","wizards/walla/jericho/rooms/towers/sw1");
  short_desc = "in the tower";
  long_desc =
"You are standing in the southwestern guard tower. From here, you can see for\n" +
"miles and miles.\n";
}
