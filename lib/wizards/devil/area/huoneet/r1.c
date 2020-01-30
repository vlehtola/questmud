inherit "room/room";

  reset(arg) {
  if(arg) return;
  add_exit("east","out: 156 57");
  add_exit("south","out: 156 57");
  add_exit("west","out: 156 57");
  add_exit("north","out: 156 57");
  add_exit("northwest","out: 156 57");
  add_exit("southwest","out: 156 57");
  add_exit("northeast","out: 156 57");
  add_exit("southeast","out: 156 57");
  add_exit("graveyard","r2");
 
  short_desc = "At the entrance to a graveyard";
  long_desc =
"You have arrived at a huge graveyard which is in the middle of nowhere. You\n"+
"can smell the rotten corpses which are lying in the graves. The air is getting\n"+
"thick with mist. You start to feel a little scared by walking in here.\n";
  
 
  
}
