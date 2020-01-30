inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("stairs", "r7.c");
  add_exit("west", "b2.c");

  short_desc = "The Library";
  long_desc = "This is a huge room full of bookshelves.\n"+
              "There is a table placed on the northern corner\n"+
              "and many books are piled on it. There is one \n"+
              "book laying on the floor. A huge and beautiful\n"+
              "chandelier is hanging from the ceiling.\n";              
  set_light(1);

items = allocate(2);
  items[0] = "book";
  items[1] = "You take a closer look at the text and read it.\n"+
             "You notice that it is a guide to open the portal\n"+
             "to the another dimension where the evil God of \n"+
             "drows, Lloth, is living. The one line tells \n"+
             "everything what it needs. 'Sacrifice 10 animal\n"+
             "hearts on the altar in the Temple of Lloth and \n"+
             "the God will be satisfied.'\n";
}

