inherit "room/room";

object monster;
reset(arg) {

    if(!monster) {
        monster = clone_object("/guilds/channel/monsters/hang_monk");
        move_object(monster, this_object());
        }
        if(arg) return;

  add_exit("north","/guilds/channel/r09");
  add_exit("south","/guilds/channel/r07");

  short_desc = "Small corridor of the church";
  long_desc = "A quiet corridor. A strong light from the south lights the room.\n";
             
              
  set_not_out(1);
  set_light(2);
  
}


