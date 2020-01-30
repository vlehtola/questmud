inherit "room/room";
object monster;

reset(arg) {
  add_exit("south","/wizards/rehti/dormund/m1");
  short_desc = "Head Knights chambers.";
  long_desc = "This looks like a throne room but there is no throne. Knights must have\n"+
              "turned this into a command center after their king died. There's a table in\n"+ 
              "the corner with some important papers on it. Next to table is a weapon\n"+
              "rack filled with swords and axes. Chamber is full of banners but there\n"+
              "is also some trophies from greatest battles.\n";
  items = allocate(4);  
  items[0] = "rack";
  items[1] = "This weapon rack is filled with swords and axes which are supreme quality. Too bad it's locked.";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/headknight"), this_object());
  if(arg) { return; }
}
}