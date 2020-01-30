inherit "room/room";
int luettu,tsaga;

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/bookseller");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","wizards/nalle/jerusalem/arma3");
  property = allocate(3);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";

  short_desc = "A small bookstore";
  long_desc =
"You have entered a small bookstore with long shelves full of\n" +
"of books filling the room. There is also a small counter behind\n" +
"which the bookseller is sitting, looking at your clothing and \n" +
"equipment with obvious interest. There are truly lots of books\n" +
"here, of which some seem quite sinister and perhaps even magical.\n" +
"There seem to be no other exits here then the door leading out.\n";
}

init() {
    ::init();
   add_action("read", "read");
   add_action("look", "look");
}

look(str) {
   if(str == "at shelf" || str == "at shelves") { 
   write("The seller might allow you to have a look at one or two of the books.\n");
   return 1;
    }
  if(str == "at book") {
  say(this_player()->query_name()+" looks at one of the books.\n");
  write("You randomly pick a book out of the shelf and have a look at it.\n");
  call_out("lue", 2);
  return 1;
  }
}

read(str) {
  if (str == "book") {
  say(this_player()->query_name()+" looks at one of the books.\n");
  write("You randomly pick a book out of the shelf and have a look at it.\n");
  call_out("lue", 2);
  return 1;
  }
}

lue() {
  luettu = luettu+1;
  if (luettu > 3) {
  write("As you reach for the book the bookseller grabs you by the neck and guides\n");
  write("you out muttering about the store not being a bloody library.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/arma3.c");
  say("The bookseller throws" + this_player()->query_name() + " out of the store, muttering something about the shop not being a bloody library.\n");
  return 1;
  }
  tsaga = random(6)+1;
  if (tsaga == 1) {
   write("A book marked 'Magnum Opus'.\n");
   write("The book you happen to take from the bookshelf seems to contain\n");  
   write("solely maps, and sketchings of exotic plants and creatures. On\n");
   write("the first page however you see a familiar map.\n");
   cat("/wizards/nalle/jerusalem/bookmap");
   return 1;
  }
  if (tsaga == 2) {
   write("A book marked 'Infernis ad infinitum'.\n");
   write("This book you took from the shelves seems pretty sinister.\n");
   write("The book is completely black, but the text is in gold. There are\n");
   write("occasional illustrations of burning children, charred or impaled\n");
   write("corpses or other equally disgusting pictures, carefully painted\n");
   write("with various different colours. You promptly replace the book.\n");
   return 1;
  }
  if (tsaga == 3) {
   write("A book marked 'Bellum ad Nauseam'.\n");
   write("This book seems slightly less elegant as the others, the\n");
   write("handwriting of the scribe is not very good, which would\n");
   write("indicate that it could well have been the author himself who\n");
   write("wrote the book. The illustrations are limited to a few flowers\n");
   write("here and there, made with the same ink as the writing.\n");
   write("You return the book to the shelf, back into its original position.\n");
   return 1;
  }
  if (tsaga == 4) {
   write("A book marked 'Ars longa, Vita brevis'.\n");
   write("This book seems to be full of copies of paintings of all\n");
   write("kinds. There are quite a few colours that have been used,\n");
   write("even blue, which must make this quite a valuable book.\n");
   write("You replace the book on the shelf, as you notice the bookseller\n");
   write("eyeing you impatiently.\n");
   return 1;
  }
  if (tsaga == 5) {
   write("A book marked 'Aqua Gratiae'.\n");
   write("This book is quite thin and well kept. It has pictures of\n");
   write("what you notice to be the Armenian quarter of Jerusalem\n");
   write("and a fountain. There are signs on the picture with the fountain\n");
   write("indicating that something would happen if you would move the\n");
   write("pedestal on which the fountain is on. There is also some mumbo\n");
   write("jumbo reading something like 'terra firma mobile' under the\n");
   write("picture.\n");
   return 1;
  }
  if (tsaga == 6) {
   write("This book is written in some foreign tongue you can make no sense of.\n");
   write("Disappointed, you put the book back where you took it from.\n");
   return 1;
  }
}

