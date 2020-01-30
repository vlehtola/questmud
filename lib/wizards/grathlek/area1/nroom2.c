inherit "room/room";
object monster; 
 
 
reset(arg) {
  if(!monster) { 
    if(arg) return;
  monster = clone_object("/wizards/grathlek/area1/monsies/mastl.c");
  move_object(monster, this_object());
  }
  add_exit("out","/wizards/grathlek/area1/nroom1.c");
  
  short_desc = "Master Leornics library room";
  long_desc = "This is Master Leornic's library room. There are books everywhere.\n"+
              "On Master Leornic's table there is a picture of himself. The floor\n"+
              "is red and very warm.\n"; 
              
  items = allocate(2);
  items[0] = "books";
  items[1] = "You take one of the books and start reading it. There is a\n"+
"spell described in it:\n"+
"   fire storm: 'exs fla strm'";
}

long(str) {
    ::long(str);
    if (str == "books") {
         if (present("spellbook", this_player())) {
             present("spellbook", this_player())->add_spell("fire storm", "exs fla strm");
         }
    }
}
