inherit "room/room";
object monster;

reset(arg) {
  if(!present("judah")) { 
    move_object(clone_object("/wizards/irmeli/pena/judah3.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum31.c");
  set_not_out(1);

  short_desc = "Great room of Emperor";
  long_desc = "You have entered the wrong room. This is the room where Emperor of the angels\n"+
                "lives. Here is lots of things what belongs to Emperor of the angels.\n"+
                "Someone might call this room to the morque.\n";
}


