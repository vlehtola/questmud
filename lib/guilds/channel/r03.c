inherit "room/room";

object monster;

reset(arg) {
 
        if(!monster) {
        monster = clone_object("guilds/channel/monsters/priest");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("north","/guilds/channel/appr_cleric");
  add_exit("east","/guilds/channel/r02");



  short_desc = "A small room";
  long_desc = "Small empty room with huge window on the western wall. The white marble walls\n"+
              "are shining as the light from the candles hit them. Silent prayers echo in the\n"+
              "room creating a calm atmosphere.\n";

              
  set_not_out(1);
  set_light(3);

  items = allocate(4);
  items[0] = "window";
  items[1] = "A huge window giving a perfect view to the Emerald street";
  items[2] = "candles";
  items[3] = "Holy candles burning brightly";


}


