inherit "room/room"; 
reset(arg) {
 
  add_exit("out","/wizards/morgoth/forest/room/forest21");
short_desc = "Inside of sorcerers hut.";
long_desc = "You are standing inside of a small hut. Walls of this hut\n"+
              "are made of some ancient looking oak. There are some\n"+
              "bookshelves containing magical scrolls and spellbooks.\n"+
              "You can easily sense evil magic inside this hut.\n";

items = allocate(4);
items[0] = "bookshelf";
items[1] = "This bookshelf contains magical scrolls and spellbooks";

init() {
  add_action("move", "move");
  ::init();

move(str) {
    write("You crawl down the tunnel and close the panel behind you.\n");
    say(this_player()->query_name()+" moves the bookshelf.\n");
    move_object(this_player(), "/world/fighter/barbaria");
    say(this_player()->query_name()+" moves the bookshelf.\n");
    return 1;
  }
}
