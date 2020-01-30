inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area/monsters/quest_redrobe");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("down","wizards/nalle/area/tower2");
  add_exit("west","/guilds/mage/illusionists");
  short_desc = "The third floor library.";
  long_desc =
"This library is open to all the occupants of the tower. There are long\n" +
"shelves filled with books from wall to wall, and the flurrying of robes\n" +
"is clearly audible as the young mages hurry from book to book attempting\n" +
"to learn as much as possible. There is a staircase leading down and an\n"+
"open door leading west.\n";
}

init() {
    ::init();
   add_action("read", "read");
}

read(arg) {
    if (!arg) {
        return 0;
    }
   write("You open the book and try to read it but it seems to make no sense.\n");
   return 1;
}
