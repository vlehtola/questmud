inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("west","/wizards/veron/areat.c");
  short_desc = "Veron's palace";
  long_desc = "Pieni sotkuinen koppi.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  
}







