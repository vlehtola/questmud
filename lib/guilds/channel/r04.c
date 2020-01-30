inherit "room/room";



reset(arg) {
        if(arg) return;


  add_exit("north","/guilds/channel/r05");
  add_exit("south","/guilds/channel/r02");
  add_exit("northeast","/guilds/paladin/baseguild");


  short_desc = "Long corridor of the church";
  long_desc = "A long and dusty corridor leading into the heart of the church. A warm feeling\n"+
              "fills you as the flames of the candles slowly move with the light breeze coming\n"+
              "from the south. Massive white marble pillars hold the ceiling firmly. The thick\n"+
              "white marble walls echo the silent prayers.\n"; 
              
  set_not_out(1);
  set_light(3);

  items = allocate(4);
  items[0] = "candles";
  items[1] = "Small white candles burning brightly";
  items[2] = "pillars";
  items[3] = "Massive white pillars made out of fine marble";


}


