inherit "room/room";
object historian;

reset(arg) {

if(arg) return;

if(!historian) {
  historian = clone_object("/wizards/kaappi/dcity/mobs/historian.c");
  move_object(historian, this_object()); }

  add_exit("south", "katu8.c");

  short_desc = "A house";
  long_desc = "A small house. There is only a table\n"+
              "in the middle of the room. One half burned\n"+
              "candle is placed on it. Also a closed book\n"+
              "is on the table. Eastern wall is empty excluding\n"+
              "one window.\n";

  set_light(1);

  items = allocate(2);
       items[0] = "book";
       items[1] = "The history of Amaranthgard";
}
