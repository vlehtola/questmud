inherit "room/outroom";
start() {
  mapfile = "/wizards/gynter/darke/city/hall/virtual_hall_map";
  short_desc = "The Podium";
  long_desc = "This is the Podium.\n"+
              "It is about two meters in height and 1 meter wide.\n"+
              "And it is shimmering like if it is made from some kinda magic.\n";
}

init() {
  ::init();
  add_action("search_podium","search");
  add_action("get_book", "get");
}

search_podium(str) {
  if(str == "podium") {
    write("You start searching the podium and it doesn't appear to\n");
    write("be anything there. But suddenly you discover a small\n");
    write("hole in the side of the podium. And in there you can barely\n");
    write("make out the dark shape of a small book.\n");
    this_player()->set_quest("Find the book of laws");
  }
}
get_book(str) {
  if(str == "book") {
     if (this_player()->query_quests("Find the book of laws")) {
       write("You put your hands into the hole of the podium and put your\n");
       write("hands on the little book to pull it out. And when you pulled it\n");
       write("out of the hole the book grows into a thick black book.\n");
       move_object(clone_object("/wizards/gynter/darke/eq/book"),this_player());
     } else {
       write("Get what?\n");
     }
  }
}
