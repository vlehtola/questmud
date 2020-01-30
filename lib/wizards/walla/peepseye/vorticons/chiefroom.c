inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/chief");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("portal","wizards/walla/peepseye/tree/1");
  add_exit("out","wizards/walla/peepseye/vorticons/d9");
  short_desc = "The room of the Grand Intellect";
  long_desc =
 "Having escaped the maze of the Caves of Oblivion\n" +
 "you find yourself in a simple room. One which is not\n" +
 "big in size, nor in decoration. This is the room where the\n" +
 "Grand Intellect dispenses galactic justice with an iron hand.\n" +
 "The Grand Intellect seems to ponder a further use for your mortal soul.\n";
}
 
