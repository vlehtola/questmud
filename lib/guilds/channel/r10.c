inherit "room/room";

reset(arg) {

        if(arg) return;

  add_exit("west","/guilds/channel/r09");



  short_desc = "Storeroom";
  long_desc = "A small room used for item storage. The floor is full of all kinds\n"+
              "of things like holy symbols, holy books, scrolls, papers and sandals.\n";
              
  set_not_out(1);

  items = allocate(8);
  items[0] = "symbols";
  items[1] = "Holy symbols of Cyral";
  items[2] = "books";
  items[3] = "Holy books of Cyral";
  items[4] = "scrolls";
  items[5] = "Old dusty scrolls lying around the floor";
  items[6] = "sandals";
  items[7] = "Few pairs of leather sandals";

  

}


