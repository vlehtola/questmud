inherit "room/room";
object monster;

reset(arg) {
  add_exit("south","/wizards/rehti/dormund/hall");
  add_exit("north","/wizards/rehti/dormund/headknight");
  short_desc = "Castle hallway";
  long_desc = "Huge hallway with many ornaments and banners, candeliers and tables\n"+
              "which create massive combinations, make this room so luxurious that a king\n"+
              "could live here. Everything seems to have its place and there seems\n"+
              "to be somekind of throne room to the north. Main hall is to south.\n";
  items = allocate(4);
  items[0] = "banners";
  items[1] = "These banners are part of knighthood, and every real knight should have one.";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/entknight"), this_object());
  if(arg) { return; }
}
}