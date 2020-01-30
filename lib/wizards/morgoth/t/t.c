inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/forest/npc/cat");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("hut","/wizards/morgoth/forest/room/sorhut");
  add_exit("north","/wizards/morgoth/forest/room/forest11");
  add_exit("south","/wizards/morgoth/forest/room/forest28");
  add_exit("west","/wizards/morgoth/forest/room/forest20");
  add_exit("east","/wizards/morgoth/forest/room/forest22");
  add_exit("northwest","/wizards/morgoth/forest/room/forest10");
  add_exit("northeast","/wizards/morgoth/forest/room/forest12");
  add_exit("southeast","/wizards/morgoth/forest/room/forest29");
  short_desc = "Front of sorcerers hut.";
  long_desc = "You are standing in front of the sorcerers hut.\n"+
              "You can hear spells being chanted from the inside.\n"+
              "The Whole place is filled with smoke.\n"+
              "There is a sign before the door.\n";

 items = allocate(4);
  items[0] = "sign";
  items[1] = "It clearly says: Stay Out!";


}

