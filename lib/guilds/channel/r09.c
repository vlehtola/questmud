inherit "room/room";

object monster;
 
reset(arg) {
    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/monk2");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("east","/guilds/channel/r10");
  add_exit("south","/guilds/channel/r08");

  short_desc = "Small corridor of the church";
  long_desc = "A corner room in the corridors of the church. The corridor goes to the\n"+
              "east and to the south from here.\n";
              
  set_not_out(1);
  
}
