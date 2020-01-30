inherit "room/room";
 
reset(arg) {
  add_exit("post","/world/city/post");
  add_exit("city","/world/city/cs");
 
  short_desc = "A Morgoth's workroom.";
  long_desc = "Taa on tyohuone!\n"+
                "Eiko oo hieno?\n";
 
  items = allocate(4);
  items[0] = "morgoth";
  items[1] = "morgoth looks you angrily!";
 
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}
 
 
init() {
  ::init(); 
  add_action("saatana", "saatana");
}
 
 
saatana(str) {
  if(str == "perkele") {
    write("ELA MOYKKAA PERKELE!\n"); 
    return 1; 
  }
  write("RIVO SIKA!\n");
  return 1;
}
