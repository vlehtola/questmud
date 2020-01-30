inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("southeast",AREA+"r4.c");
  add_exit("south",AREA+"r5.c");
  add_exit("southwest",AREA+"r6.c");
  
  /* give the description for the room (M) */
  short_desc = "On a cliff of a hill.";
  long_desc = "From this cliff, the vastness of the Ocean "+
              "of Deleria can truly be seen. "+
              "The sea goes further than an eye can see. "+
              "A shape of the island can be seen "+
              "on the sea northeast from here, "+
              "but some strange mist surrounds it "+
              "preventing to see clearly. "+
              "Down on the beach, "+
              "there seems to be some small village in west.\n";
              

  items = allocate(12);
  items[0] = "ocean";
  items[1] = "The Great Sea of Deleria looks infinite. "+
             "No matter how much you try, the sea goes further than you can see";
  items[2] = "sea";
  items[3] = "The Great Sea of Deleria looks infinite. "+
             "No matter how much you try, the sea goes further than you can see";
  items[4] = "island";
  items[5] = "The island seems to be over 300 meters away here on the sea. "+
             "Some strange mist from unknown source surrounds the island, "+
             "veiling it from the outside world. "+
             "It even seems impossible to go ashore there "+
             "because of the cliffy shores. "+
             "Only way to get there seems to be by flying";
  items[6] = "village";
  items[7] = "Some shacks and houses are west from forest, "+
             "there's a village of some kind";
  items[8] = "mist";
  items[9] = "Strange mist surrounds the island, "+
             "blocking almost totally the view there";
  items[10] = "beach";
  items[11] = "Jumping down from here would be bad for health, "+
              "it's a long way down to beach";

}
