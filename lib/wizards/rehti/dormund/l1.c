inherit "room/room";
object monster;

reset(arg) {
  add_exit("west","/wizards/rehti/dormund/l2");  
  add_exit("down","/wizards/rehti/dormund/leftmuuri");
  short_desc = "At the walls.";
  long_desc = "These walls are perfect place for dropping something over attackers.\n"+
              "You can't see any monsters tho. Landscape is beautiful and you wonder\n"+
              "if there is any evil there anyway. Brisk wind makes this place very cold\n"+
              "during night. Hope defenders won't freeze to death before anything happens.\n"+
              "To west is the outworld and to east is ladder back to inside.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/wallguard"), this_object());
  if(arg) { return; }
}
}