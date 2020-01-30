inherit "room/room";
init() {
  ::init();
  add_action("knock", "knock");
}
 
knock(str) {
  if(str != "panel") return;
  write("You knock on the panel, and get let in.\n");
  say(""+this_player()->query_name()+" suddenly gets dragged through a crack in the wall.\n");
  move_object(this_player(),"/wizards/walla/jericho/rooms/mcellar/2");
  command("look");
  return 1;
}
 
 
reset(arg) {
  if(arg) return;
  add_exit("up","wizards/walla/jericho/rooms/mosque2");
  short_desc = "In the cellar";
  long_desc =
"You are standing in the cellar of the mosque. It seems like\n" +
"a completely normal cellar, although you have to wonder why\n" +
"it was so heavilyy guarded. The wall on the north face has a\n" +
"panel on it, which one could perhaps use.\n";
}
