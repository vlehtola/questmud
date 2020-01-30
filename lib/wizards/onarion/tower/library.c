inherit "room/room";

int books;

init() {
  ::init();
  add_action("browse", "browse");
}

browse(str) {
  int i;
  if (!str) { write("Usage: 'browse <num>'\n"); return 1; }
  if (sscanf(str, "%d", i) != 1) { return 0; }
  if (i > sizeof(books) || i < 1) { write("No such book.\n"); return 1; }
  write(call_other("/wizards/onarion/library_fun","get_long",books[i-1]));
  return 1;
}

random_books() {
   int i;
   books = allocate(random(5)+1);
   long_desc += "There are some books in the shelves:\n";
   while(i<sizeof(books)) {
	books[i] = random(call_other("/wizards/onarion/tower/library_fun","number_of_books",1))+1;
	long_desc += "   "+call_other("/wizards/onarion/tower/library_fun","get_short",books[i])+"\n";
	i += 1;
   }
}
