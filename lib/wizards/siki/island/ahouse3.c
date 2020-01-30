inherit "room/room";

object monster;

   reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/spider");
      move_object(monster, this_object());
      }
      if(arg) return;

  add_exit("north","/wizards/siki/island/ahouse2");



  short_desc = "A small room";
  long_desc = "A small room full of shelves. Seems like this is a storeroom, but\n"+
              "the shelves are empty and the floor is dusty and dirty. Spiderwebs\n"+
              "in the corner of the room give it a creepy feeling.\n";
         
  items = allocate(4);
  items[0] = "spiderwebs";
  items[1] = "Huge spiderwebs in the corner of the room";
  items[2] = "shelves";
  items[3] = "Empty wooden shelves";

  set_not_out(1);

}
