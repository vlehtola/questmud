inherit "room/room";
object monster;
reset(arg) {
if(arg) return;
add_exit("south","/wizards/trooper/areas/muhoscity/r13.c");

short_desc = "Second corner";
long_desc = "Now fog has disappeared fully and you can see very well.\n"+
             "Someone have left this place fast, his equipment and huge bottle of  \n"+
             "rum.\n";
             items = allocate(4);
items[0] = "equipment";
items[1] = "Holy cow a full set of equipment. Helms and all. Too bad its all broken. ";
items[2] = "bottle";
items[3] = "Huge bottle which reads 'Jellona viina'. It smells terrible and theres a gas in it.";
}

init() {
  ::init();
  add_action("rub", "rub");
}
rub(str) {
  if(str != "bottle") return;
  write("You rub the bottle in passion and at last. It comes... a TERRIBLE GHOST! \n");
  say("Ghost says: Ah at last someone let me out of that smelly bottle... im hungry... i need flesh... your flesh!\n");
  return 1;
monster = clone_object("/wizards/trooper/areas/muhoscity/monsters/ghost.c");
move_object(monster, this_object());
}
}

