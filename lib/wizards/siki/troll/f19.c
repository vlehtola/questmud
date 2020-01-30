inherit "room/room";

object monster;

   reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/troll/monsters/wolf");
      move_object(monster, this_object());
      }
      if(arg) return;

      
  add_exit("west","wizards/siki/troll/f18");

  short_desc = "Great forest";
  long_desc = "A deep and sinister forest. There are different types of trees\n"+
              "in very dense, old and new, living and dead ones. Visibility is\n"+
              "extremely low cause of the trees. The ground is covered with a\n"+
              "layer of bushes. A small path leads deeper into the forest.\n";
         
   items = allocate(6);

   items[0] = "trees";
   items[1] = "Old and new, dead and living trees";
   items[2] = "bushes";
   items[3] = "Thick layers of bushes covering the whole ground making it hard to move";
   items[4] = "path";
   items[5] = "A very small path leading deeper into the forest. It is extremely hard to\n"+
              "to notice it and it looks like it has been tried to cover with leaves";
}

init() {
   add_action("enter", "enter");
   add_action("enter", "walk");
 ::init();
   }

enter(str) {
   if(str == "path" || str == "forest") {
      write("You walk the path deeper into the forest and find a small clearing.\n");
      say(this_player()->query_name()+" walks the path deeper into the forest.\n");
      move_object(this_player(), "/guilds/fighter/berserker");
      say(this_player()->query_name()+" arrives from the forest.\n");
      return 1;
      } else {
      write("What ?\n");
      return 1;
}
}
