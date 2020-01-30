inherit "room/room";
inherit "/guilds/library/book_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_not_out(1);
set_light(3);

  add_exit("out","/guilds/library/mainhall");
  short_desc = "The channel section";
  long_desc = "In a triangular-shaped room is the channel section. The room belongs to the\n"+
              "library of Duranghom and it's located somewhere in the bowels of the library.\n"+
              "Massive bookshelves are leaning against the three walls. Scrolls and books\n"+
              "are stored in the bookshelves, offering various knowledge to the adventurers.\n"+
              "A massive oaken table is placed in the centre of the room. The table is\n"+
              "surrounded with twenty chairs, ten on both sides of the table. The room is\n"+
              "peaceful and quiet, perfect place for reading. The light comes to the room\n"+
              "from torches, which are burning on the walls.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Torches are burning on the walls, providing light to the room";
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
