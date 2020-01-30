inherit "room/room";

reset(arg) {

        if(arg) return;


  add_exit("up","/guilds/channel/r07");
  add_exit("south","/guilds/channel/r05");



  short_desc = "End of the corridor";
  long_desc = "End of the long and dusty corridor. Massive white pillars\n"+
              "hold the ceiling firmly. Soft and calm voices echoes down\n"+
              "from stairs slowly fading into the south. A dim light from\n"+
              "the stairs lights the room.\n"; 
              
  set_not_out(1);
  set_light(1);

  items = allocate(4);
  items[0] = "stairs";
  items[1] = "Stairs, made out of fine rock, leading upwards";
  items[2] = "pillars";
  items[3] = "Massive white pillars made out of fine marble";


}


