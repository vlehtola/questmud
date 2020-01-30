inherit "room/room";

object monster;

reset(arg) {
    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/monk2");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("east","/guilds/channel/r07");
  add_exit("south","/guilds/channel/r12");


  short_desc = "Small corridor of the church";
  long_desc = "A corner room in the corridors of the church. The corridor goes to the\n"+
              "east and to the south from here and a light from the east lights the room.\n";
              
  set_not_out(1);
  set_light(2);

  }
