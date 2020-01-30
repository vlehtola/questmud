inherit "room/room";

object monster;
object monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/proge/moraloth/soul");
    move_object(monster, this_object());
  }
  if(!monster2) { 
    monster2 = clone_object("/wizards/proge/moraloth/ghoul");
    move_object(monster2, this_object());
  }

  if(arg) return;

  add_exit("west", "/wizards/proge/moraloth/forest2");
  add_exit("north","/wizards/proge/moraloth/forest7");
  add_exit("east","/wizards/proge/moraloth/forest8");
  add_exit("south","/wizards/proge/moraloth/forest9");

  short_desc =
"In the damned forest of Moraloth";

  long_desc = 
  
"You're standing in the woods or Moraloth, also known as the\n"+
"haunted forest. It has been said these woods have been damned\n"+
"from the beginning of time. There is only faint light coming\n"+
"through the branches. It would be easy to get lost in this\n"+
"kind of place. The ancient trees seem older than anything\n"+
"you've seen before. There is absolutely no voice.\n";


}


