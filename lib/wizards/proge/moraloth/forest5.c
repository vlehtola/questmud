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

  add_exit("west", "/wizards/proge/moraloth/forest10");
  add_exit("north","/wizards/proge/moraloth/forest6");
  add_exit("east","/wizards/proge/moraloth/forest7");
  add_exit("south","/wizards/proge/moraloth/forest3");

  short_desc =
"Deep in the damned forest of Moraloth";

  long_desc = 

"You've come deeper in to the forest. The sky is not visible\n"+
"through the big ancient trees. They seem to get bigger and\n"+
"older. Behind the trees and bushes, there seems to be somekind\n"+
"path, covered under the thick layer of dead leaves.\n";

}

init() {
  add_action("path", "path");
  add_action("look", "look");
  ::init();
}

look(str) {
  if(str == "at path") {
    write("This is a small path leading deeper in to the forest.\n");
    return 1;
  }
  if(str == "at bushes" || str = "at trees") {
    write("There is somekind of path going behind these trees and bushes.\n");
    return 1;
  }
  return;
}

path(str) {
   write("You start to clear your way through the bushes.\n");
   call_out("path_loytyy", 3);
   return 1;
}

path_loytyy(str) {
   write("You found a path!\n");
   if (this_player()->query_quests("Moraloth path") == 0) {
     //write("You receive 3 quest points.\n");
     //this_player()->set_quest("Moraloth path", 3);
     this_player()->set_quest("Moraloth path", 0);
   }
   this_player()->move_player("path#/wizards/proge/moraloth/path");
   return 1;
}
