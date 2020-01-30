inherit "room/room";
init() {
  ::init();
  add_action("insert", "insert");
}

insert(str) {
  if(str != "railing") return;
  if(!present("pala0503246921",this_player()))
    return 0;
    destruct(present("pala0503246921",this_player())); 
    write("You insert the piece of the railing in the wall, and it starts opening.\n");
    say(""+this_player()->query_name()+" fumbles with a strange piece of metal.\n");
    add_exit("east","/wizards/walla/northern/rooms/lvl-1/17");
    command("look");
    return 1;
}

 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/helof");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","15");
  short_desc = "In a dark passage under the mountain";
  long_desc =
"The passage that you see before you, reminds you oddly of a prison. There are bars\n" +
"and chains hanging of the wall. The paraphernalia on the walls seem to have been\n" +
"abandoned for quite some time now. Still, voices can be heard from the depths of\n" +
"the mountain. The wall has some sort of hole in it, where you could insert something.\n";
 
 
}


