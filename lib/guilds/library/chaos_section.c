inherit "room/room";
inherit "/guilds/library/book_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_not_out(1);
set_light(3);

  add_exit("out","/guilds/library/mainhall");
  short_desc = "The chaos section";
  long_desc = "This part of the library looks quite chaotic. Center of this little darknish room is a table with seven chairs next to it "+
             "On the table are books what are decorated with demonic skulls and even the paper used most of the books is made from human skin. "+
             "A large bone chandelier is placed hangling on the ceiling with three skulls which are burning is giving light to this dark place.\n";
   property = allocate(1);
   property[0] = "no_summon";

}

init() {
  ::init();
  library_init();
}
