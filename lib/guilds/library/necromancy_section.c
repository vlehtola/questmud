#define SECTION "essence"

inherit "room/room";
inherit "/guilds/library/book_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_not_out(1);
set_light(3);

  add_exit("out","/guilds/library/mainhall");
  short_desc = "The necromancy section";
  long_desc = "The necromancy section is built in a circular-shaped room. Old bookshelves\n"+
              "are leaning against the walls, forming a circle in the room. Old scrolls\n"+
              "and books are stored in the bookshelves. A massive table made of oak is\n"+
              "in the centre of the room. Twenty chairs, on the both sides of the table,\n"+
              "are all empty and waiting for readers. The floor is clean from dust, but\n"+
              "there are some papers from books, scattered all over the place. The room is\n"+
              "lit up with torches, which are burning on the walls, between the bookshelves.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Torches are burning on the walls, between the bookshelves";
   items[2] = "bookshelves";
   items[3] = "The bookshelves are full of old scrolls and books";
   items[4] = "table";
   items[5] = "Table made of oak is in the centre of the room. Twenty chairs are placed on the both sides of the table";

   property = allocate(1);
   property[0] = "no_summon";

}

init() {
  ::init();
  library_init();
}
