inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("east",AREA+"r3.c");
  
  /* give the description for the room (M) */
  short_desc = "In front of large bushes.";
  long_desc = "This place is surrounded by thick, "+
              "ridiculously large bushes which seem to be totally impassable. "+
              "Air is filled with animal sounds, although few of them can actually be seen. "+
              "Only way out of here, back the forest seems to be east. \n";
              

  items = allocate(6);
  items[0] = "bushes";
  items[1] = "These bushes are ridiculously overgrown, and any "+
             "attempts to go through them more likely ends up in failure. "+
             "However, searching in one of the lighter bushes "+
             "reveals a small hole";
  items[2] = "hole";
  items[3] = "It seems to be a rabbit hole, only creatures small as rabbits "+
             "would be able to crawl into that hole";
  items[4] = "animals";
  items[5] = "They cannot actually be seen, "+
             "but all those noises around tell that "+
             "lots of animals are hiding somewhere here";


}
