inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!monster) {
     monster = clone_object("/wizards/kaappi/mine/mosat/guard.c");
    move_object(monster, this_object()); }
  if(!monster2) {
     monster2 = clone_object("/wizards/kaappi/mine/mosat/guard.c");
     move_object(monster2, this_object()); }
if(arg) return;
   add_exit("mine", "r1.c");
  add_exit("south", "out: 190 44");
  add_exit("west", "out: 190 44");
  add_exit("southwest", "out: 190 44");
  add_exit("southeast", "out: 190 44");
  short_desc = "Entrance to the Dwarf Mines";
  long_desc =
    "Hills of a great height dominate the area as far as an eye can see.\n"+
    "There is a huge open gate in front of you. As you look at the gate closer \n"+
     "you notice it's fine craftmanship and some runes are written on it. A quite dark tunnel \n"+
   "begins behind the gates. There is also a small sign standing on the ground.\n";
items = allocate(4);
   items[0] = "sign";
  items[1] = "The Dwarven Mines";
   items[2] = "runes";
  items[3] = "Very old runic writing, that you can't understand.";
}
