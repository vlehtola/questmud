inherit "room/room";
init() {
  ::init();
  add_action("crawl", "crawl");
}
 
crawl(str) {
  if(str != "hole") return;
  write("You crawl through the wall.\n");
  say(""+this_player()->query_name()+" crawls through the wall\n");
  move_object(this_player(),"/wizards/walla/jericho/rooms/mcellar/7");
  command("look");
  return 1;
}
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/prisoner1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/mcellar/6");
  short_desc = "A small prison cell";
  long_desc =
"You are standing in a small prison cell. The room has a horrid smell, from a mixture\n" +
"of urin, excrements, vomit and blood. The smell makes you feel nauseous, and you the\n" +
"and the only thought is how, or when you could leave this place. There is something \n" +
"peculiar about the western wall. It almost looks as if it had a hole in it.\n";
}

