inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("ja-tora","/wizards/phoebus/areas/ja-tora/rooms/ja1");
 short_desc = "A big old dusty room, oned by Phoebus Apollo\n";
  long_desc = "long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
}



