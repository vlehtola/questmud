inherit "room/room";
inherit "/guilds/library/book_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_not_out(1);
set_light(3);

  add_exit("out","/guilds/library/mainhall");
  short_desc = "The abjuration section";
  long_desc = "A square room is the section of abjuration. Bookshelf after bookshelf is\n"+
              "placed to lean against the walls. The bookshelves are bulging with books\n"+
              "and scrolls, gathered from all around the world. Four oaken tables are in\n"+
              "centre of the room, standing on a red carpet. Three chairs, around each\n"+
              "the table, are all empty. The walls are full of torches, which are burning\n"+
              "and providing light and warmth to every corner of the room. This is a\n"+
              "perfect place for reading and studying.\n";
   items = allocate(8);
   items[0] = "torches";
   items[1] = "Torches are burning on the walls, providing light and warmth to every corner of the room";
   items[2] = "bookshelves";
   items[3] = "The bookshelves are bulging of old scrolls and books";
   items[4] = "tables";
   items[5] = "Tables are made of oak and placed in the centre of the room. Three empty chairs are around each table";
   items[6] = "carpet";
   items[7] = "A red carpet lying on the floor, under the tables";

   property = allocate(1);
   property[0] = "no_summon";

}

init() {
  ::init();
  library_init();
}
