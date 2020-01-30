inherit "room/room";


reset(arg) {
        if(arg) return;

  add_exit("north","/guilds/channel/r11");
  add_exit("west","/guilds/channel/adept_cleric");


  short_desc = "Small corridor of the church";
  long_desc = "A corner room in the corridors of the church. The corridor goes to the\n"+
              "north and to the west from here and a light from the west lights the room.\n";
              
  set_not_out(1);
  set_light(2);

  }
