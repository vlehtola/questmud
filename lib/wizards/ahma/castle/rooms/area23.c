inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area19b");
  add_exit("west", "/wizards/ahma/castle/rooms/area21");
  short_desc = "In a bedroom";
  long_desc = "In one the of servants' bedrooms.\n" + 
              "This room, just alike others, has got struck by a sneak attack by\n" + 
              "demonic creatures. The bookshelf on the southern wall has been\n" + 
              "torn apart and the small desk by the western wall misses half from\n" + 
              "one of its four legs. The wardrobe by the northern wall is left\n" + 
              "untouched. There are four beds in this room, but only three are\n" + 
              "covered with blood and torn pieces of skin. In addon, only three\n" + 
              "human bodies can be found in the beds. The southern wall has\n" + 
              "collapsed letting you enter the room south of this one.\n";

  items = allocate(4);
  items[0] = "bed";
  items[1] = "Unlike others this bed is not covered with blood. Though there is\n" + 
             "marks that the bed has been in use this night: The covering blanket\n" + 
             "has been removed and the sheet is all wrinkled";
  items[2] = "wardrobe";
  items[3] = "The wardrobe is small and conventional. It is made of some common\n" +
             "materials and is painted like all others in the castle. One of its\n" +
             "doors seems to be a bit out of place";

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster02, this_object());
    }  
  }
}

init() {
  ::init();
  add_action("open", "open"); }

open(str) {
  if(str == "wardrobe") {
    write("You try to open the wardrobe doors but notice that they are attached\n" + 
          "to each other inside. Before you have time to start thinking anything\n" + 
          "else, a quiet sobbing starts to hear inside the wardrobe.\n" + 
          "After a short moment a scary voice starts to whisper: \n" + 
          "'Go away, leave me alone, let me be.', followed with more wimpering and sobbing.\n\n" + 
          "Well, at least you know what happened to the last body.\n" + 
          "You decide not to bother poor man any more - Just leave him to his own\n" + 
          "dark world.\n");
  }
}
