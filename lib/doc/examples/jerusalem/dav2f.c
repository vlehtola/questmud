inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/davguard3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/dav2e");
  add_exit("east","wizards/nalle/jerusalem/dav2g");
  short_desc = " Inside David's Tower, Main Bedroom";
  long_desc =
"You have entered a large room, a bit more luxurious\n" +
"one than the others at this level, that looks like a\n" +
"bedroom. A large double bed is situated in the middle\n" +
"room. You can hardly refrain from jumping into it\n"+
"and taking a short nap.\n";
}

