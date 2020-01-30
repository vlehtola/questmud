inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/roman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/gola2");
  short_desc = "Near the entrance to Golgatha";
  long_desc =
"This is a small area near the entrance to Golgatha.\n" +
"A long row of chained men are in a line, being inspected\n" +
"by a Duranghomian sergeant, who seems to be telling them\n" +           
"for what they have been sentenced and what their fate\n" +
"will be.\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/gmap");
   return 1;
}   


