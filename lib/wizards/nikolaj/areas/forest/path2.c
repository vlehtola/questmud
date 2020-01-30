inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("northwest",AREA+"path3.c");
  add_exit("southwest",AREA+"path1.c");
  
  /* give the description for the room (M) */
  short_desc = "On an ascending path.";
  long_desc = "This path seems to go all the way to the top of the forest. "+
              "The trees are getting fewer as the path ascends higher, "
              "showing more of the sky above.\n";
              
  items = allocate(2);              
  items[0] = "path";
  items[1] = "A narrow winding path going up to the hill";

}
