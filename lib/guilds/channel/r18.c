inherit "room/room";

object monster;

reset(arg) {
 
        if(!monster) {
        monster = clone_object("guilds/channel/monsters/priest3");
        move_object(monster, this_object());
        }
        if(arg) return;


  add_exit("east","/guilds/channel/r19");
  add_exit("south","/guilds/channel/r20");
  add_exit("west","/guilds/channel/r17");
 


  short_desc = "Secret room";
  long_desc = "A dusty room built many years after the rest of the church. A strong smell\n"+
              "of booze fills the whole room. A small torch hanging on the wall light the\n"+
              "room giving it a mystical feeling.\n";

              
  set_not_out(1);
  set_light(3);

  items = allocate(2);
  items[0] = "torch";
  items[1] = "A lit torch hanging on the wall";




}


