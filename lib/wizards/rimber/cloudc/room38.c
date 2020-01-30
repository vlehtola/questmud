inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "In a white room";
 long_desc = "White walls and a silver table. Strange looking bookcase lays near the wall.\n";
 items = allocate(6);
 items[0] = "table";
 items[1] = "The table is made of pure silver and in the middle of it is some carvings.";
 items[2] = "bookcase";
 items[3] = "The bookcase is made of ivory. There is a black book amone the white books.";
 items[4] = "book";
 items[5] = "The book is totally black and it's only black book in the bookcase.";
 add_exit("west", "/wizards/rimber/cloudc/room36.c");
}

init() {
 ::init();
 add_action("pull", "pull");
}

pull(str) {
 if(str == "lever") {
  write("You pull the lever and the mechanism starts moving.\n");
  say(this_player()->query_name()+" pulls the lever and the mechanism starts moving.\n");
  call_out("start", 1);
  return 1;
 }
 else { write("Pull what?\n"); }
 return 1;
}

int start() {
 "/wizards/rimber/cloudc/room44.c"->seina();
}
