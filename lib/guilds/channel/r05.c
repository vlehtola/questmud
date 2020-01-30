inherit "room/room";

object monster;

reset(arg) {
    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/monk");
        move_object(monster, this_object());
        }
        if(arg) return;


  add_exit("north","/guilds/channel/r06");
  add_exit("south","/guilds/channel/r04");



  short_desc = "Long corridor of the church";
  long_desc = "A long and dusty corridor leading into the heart of the church. The holy\n"+
              "candles light the room slightly but the darkness in the room does not scare\n"+
              "you. Massive white marble pillars hold the ceiling firmly. The thick white\n"+
              "marble walls echo the silent prayers.\n"; 
              
  set_not_out(1);
  set_light(2);

  items = allocate(4);
  items[0] = "candles";
  items[1] = "Small white candles burning brightly";
  items[2] = "pillars";
  items[3] = "Massive white pillars made out of fine marble";


}


