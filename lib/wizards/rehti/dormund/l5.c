inherit "room/room";

reset(arg) {
  add_exit("north","/wizards/rehti/dormund/l4");  
  add_exit("south","/wizards/rehti/dormund/l6"); 
  short_desc = "At the walls.";
  long_desc = "These walls are perfect place for dropping something over attackers.\n"+
              "You can't see any monsters tho. Landscape is beautiful and you wonder\n"+
              "if there is any evil there anyway. Brisk wind makes this place very cold\n"+
              "during night. Hope defenders won't freeze to death before anything happens.\n"+
              "To west is the outworld and to east is inner city.\n";
}