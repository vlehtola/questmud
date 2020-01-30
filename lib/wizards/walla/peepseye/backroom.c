inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/cottoneyejoe");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","/wizards/walla/peepseye/tree/1");
  short_desc = "Behind the bar";
  long_desc =
 "Here sits the manager of the bar, Cotton-Eye Joe. He is the nowadays the greatest pirate alive,\n" +
 "now that Pepe lost the duel, because he couldn't see. Cotton-Eye Joe is the kind of pirate that is only\n" +
 "interrested in money.\n" ;

  items = allocate(4);  
  items[0] = "sign";
  items[1] = "The sign says: Wrong glasseye, schmuck.";
 
}
init() {
  ::init();
  add_action("dig", "dig");
}
 
dig(str) {
if(!present("shovel",this_player())) {write("You need a shovel to dig.\n");return 0; }
write("You dig a hole in the ground and fall down to another place.\n");
say("Someone digs a hole in the ground, but it covers itself as soon as he disappears.\n");
  move_object(this_player(), "/wizards/walla/peepseye/vorticons/entrance");
return 1;                  
}
