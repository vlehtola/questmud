inherit "room/room";
object wiz;
object librarian;
reset(arg) {
    if(arg) return;
    add_exit("southeast","/wizards/siggy/area/unseen/uu1.c");
    add_exit("east","/wizards/siggy/area/unseen/uu3.c");
    set_not_out(3);
    short_desc = "Library of Unseen University";
    long_desc = 
        "You can see hundreds of thousands of books in the shelves. The library keeper\n"
        + "is a monkey. This library is magical and can't be denied as some of the\n"
        + "books are floating and there is one book with teeth. There is a huge hill of\n"
        + "bananas in front of you. There is a deep cleft in the middle of the library.\n";

   items = allocate(2);
   items[0] = "hill";
   items[1] = "Huge pile of bananas lying here";

    if(!wiz) {
    wiz = clone_object("/wizards/siggy/area/unseen/wiz.c");
    move_object(wiz, this_object());
    }
    if(!librarian) {
    librarian = clone_object("/wizards/siggy/area/unseen/librarian.c");
    move_object(librarian, this_object());
    }
}
init() {
  ::init();
  add_action("throw", "throw");
}

throw(str) {
  if(str != "banana in hole") return;
    if (ob && !ob->query_quest("banana_quest")) {
        tell_object(ob, "You have completed the quest.\n");
        ob->set_quests("banana_quest");
    }
}


