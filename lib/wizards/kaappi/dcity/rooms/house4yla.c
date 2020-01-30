inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("down", "house4.c");

  short_desc = "A house";
  long_desc = "There is a bookshelf on the northern\n"+
              "wall. It is full of different kind of\n"+
              "books. There is one bigger and four\n"+
              "smaller beds. Nice looking chandelier\n"+
              "is hanging from the ceiling.\n";
  set_light(3);
}
