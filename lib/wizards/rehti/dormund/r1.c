inherit "room/room";
object monster;

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/r2");  
  add_exit("down","/wizards/rehti/dormund/rightmuuri");
  short_desc = "At the walls.";
  long_desc = "These walls are perfect place for dropping something over attackers.\n"+
              "You can't see any monsters tho. Landscape is beautiful and you wonder\n"+
              "if there is any evil there anyway. Brisk wind makes this place very cold\n"+
              "during night. Hope defenders won't freeze to death before anything happens.\n"+
              "To east is the outworld and to west is the ladder to back inside.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/wallguard"), this_object());
  if(arg) { return; }
}
}