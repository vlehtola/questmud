inherit "room/room";


reset(arg) {

  add_exit("north","/guilds/channel/r02");
  add_exit("south","/world/city/mainstr4");



  short_desc = "Huge hall of the church";
  long_desc = "The entrance of the Duranghom's church of Cyral. The ceiling raises high\n"+
              "above your head and it is full of religious paintings. Massive white marble\n"+
              "pillars hold the ceiling firmly. The holy candles all around the hall lights\n"+
              "the room perfectly leaving no shadows on the walls. Huge double doors open to\n"+
              "the south revealing the ordinary life of Duranghom.\n";
              
  set_not_out(1);
  set_light(3);

  items = allocate(8);
  items[0] = "candles";
  items[1] = "Small white candles burning brightly";
  items[2] = "pillars";
  items[3] = "Massive white pillars made out of fine marble";
  items[4] = "paintings";
  items[5] = "Colourful paintings of different religious heroes of the realm";
  items[6] = "doors";
  items[7] = "Large oaken double doors";
}


