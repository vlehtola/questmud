inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "katu22.c");

  short_desc = "A house";
  long_desc = "A small and nicely furnished house.\n"+
              "Some beautiful flowers are placed on the\n"+
              "window board. A big bed is on the corner\n"+
              "and it looks very soft. There is a small\n"+
              "desk next to bed and couple of books are\n"+
              "on it.\n";

  set_light(2);
}
