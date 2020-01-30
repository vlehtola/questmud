inherit "room/room";

object monster,monster2;
int q;

reset(arg) {
    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/drunk_monk");
        move_object(monster, this_object());
        }
    if(!monster2) {
        monster2 = clone_object("/guilds/channel/monsters/monk2");
        move_object(monster2, this_object());
        }
/*
    if(!booze) {
        booze = clone_object("/guilds/channel/obj/booze");
        move_object(booze, this_object());
        }
*/
        if(arg) return;

  short_desc = "Secret room";
  long_desc = "A dusty room built many years after the rest of the church. This\n"+
              "place is a hide out of the monks. On the table in the middle of the\n"+
              "room are bottles of booze and ale mugs. A wooden bookshelf is located\n"+
              "on the northern wall. A small torch hanging on the wall lights the room\n"+
              "giving it a mystical feeling.\n"; 
              
  set_not_out(1);
  set_light(1);

  items = allocate(8);
  items[0] = "floor";
  items[1] = "The floor is extremely dusty, but infront of the bookshelf is a clean spot";
  items[2] = "bookshelf";
  items[3] = "A wooden bookshelf with only one book in it";
  items[4] = "book";
  items[5] = "A book labelled 'How to make beer'";
  items[6] = "torch";
  items[7] = "A lit torch hanging on the wall";


}

  init() {
  add_action("pull", "pull");
  ::init();
}


pull(str) {
    if(str == "book") {
    write("As you pull the book the bookshelf rotates.\n");
    say(this_player()->query_name()+" touches the book and the bookshelf rotates. "+this_player()->query_name()+" is gone.\n");
    move_object(this_player(), "/guilds/channel/r16");
    say("The bookshelf rotates and "+this_player()->query_name()+" arrives.\n");
    return 1; 
    } 
    if(str == "torch") {
    if(!q) {
    write("As you pull the torch, a secret passage on the eastern wall opens.\n");
    say(this_player()->query_name()+" pulls the torch and a secret passage opens.\n");
    add_exit("east","/guilds/channel/r18");
    q = 1;
    this_player()->set_quest("Find the secret hideout in the Church");
    return 1;

    } else {
    write("What ?\n");
    return 1;
}
}
}
id(str) {
  if(str == "book") { return 1; }
  if(str == "torch") { return 1; }
}


