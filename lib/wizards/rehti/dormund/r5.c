inherit "room/room";

reset(arg) {
  add_exit("north","/wizards/rehti/dormund/r4");  
  add_exit("south","/wizards/rehti/dormund/r6");
  short_desc = "At the walls.";
  long_desc = "These walls are perfect place for dropping something over attackers.\n"+
              "You can't see any monsters tho. Landscape is beautiful and you wonder\n"+
              "if there is any evil there anyway. Brisk wind makes this place very cold\n"+
              "during night. Hope defenders won't freeze to death before anything happens.\n"+
              "To east is the outworld and to west is inner city.\n";
}