inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/ozmala/areat/area-testi/mosut/mosa");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/ozmala/areat/area-testi/roomit/roomi2");
  short_desc = "t‰‰ on huone";
  long_desc =
"jos monsu.c toimii kunnolla\n" +
"niin se pit‰is cloonaantua t‰nne\n" +
"huoneeseen...\n";
 
}
