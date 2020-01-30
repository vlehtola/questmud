inherit "room/room";

object monster;

reset(arg) {
    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/drunk_monk");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("north","/guilds/channel/r07");

  short_desc = "Library";
  long_desc = "The small library of the church. A round table in the middle of\n"+
              "the room takes almost all the space in the room. A wooden bookshelf\n"+
              "on the southern wall has only one book in it. The floor is extremely\n"+
              "dusty. A dim light from the north slightly lights the room.\n"; 
              
  set_not_out(1);
  set_light(1);

  items = allocate(6);
  items[0] = "floor";
  items[1] = "The floor is extremely dusty, but infront of the bookshelf is a clean spot";
  items[2] = "bookshelf";
  items[3] = "A wooden bookshelf with only one book in it";
  items[4] = "book";
  items[5] = "A book labelled 'Secrets of the path'";

}

init() {
  add_action("pull", "take");
  add_action("pull", "pull");
  ::init();
}


pull(str) {
    if(str == "book") {
    write("As you pull the book the bookshelf rotates.\n");
    say(this_player()->query_name()+" touches the book and the bookshelf rotates. "+this_player()->query_name()+" is gone.\n");
    move_object(this_player(), "/guilds/channel/r17");
    say("The bookshelf rotates and "+this_player()->query_name()+" arrives.\n");
    return 1; 
    } else {
    write("What ?\n");
    return 1;
}
}
id(str) {
  if(str == "book") { return 1; }
}

