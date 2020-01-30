inherit "room/room";

object monster;

reset(arg) {
 
        if(!monster) {
        monster = clone_object("guilds/channel/monsters/priest2");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("west","/guilds/channel/r13");
  add_exit("south","/guilds/channel/r15");



  short_desc = "Office";
  long_desc = "An office room with a small wooden table. The table is full of\n"+
              "old scrolls, books and papers. There is also a iron lantern on\n"+
              "the table giving enough light to light the whole room.\n";

              
  set_not_out(1);
  set_light(3);

  items = allocate(8);
  items[0] = "lantern";
  items[1] = "Iron lantern lighting the whole room";
  items[2] = "scrolls";
  items[3] = "Old dusty scrolls lying on the table";
  items[4] = "books";
  items[5] = "Holy books lying on the table";
  items[6] = "papers";
  items[7] = "Papers used for writing scripts and notes";


}


