inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("down","/wizards/ozmala/areatele");
  short_desc = "shotdesc";
  long_desc = 
"Ozmala�s workroom, full of funny looking tuning tools.\n" +
"there is a sign on the ground maybe you should check it out.\n";
  items = allocate(2);                
  items[0] = "sign";
  items[1] = "if you aren't Ozmala go to -<HELL>-";
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
