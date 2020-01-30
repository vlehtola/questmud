inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/crow");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/dav1c1");
  add_exit("enter","wizards/nalle/jerusalem/dav2a");
  short_desc = "North from David's Tower";
  long_desc =
"You are now in the north part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. As you expected the entry to the tower\n" +
"is here, but what suprises you is that the door is not locked,\n" +
"it has been left slightly open. \n";
}

