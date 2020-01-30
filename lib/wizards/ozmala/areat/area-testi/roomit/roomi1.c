inherit "room/room"; 

reset(arg) {
 
  add_exit("tele","/wizards/ozmala/areatele");
  add_exit("east","/wizards/ozmala/areat/area-testi/roomit/roomi2");
  short_desc = "testing testing";
  long_desc = 
"joo t�h�n tulee long desci mut t��ki v�h� testaa\n" +
"et mite systeemit toimii.\n";

  items = allocate(4);                
  items[0] = "sign";
  items[1] = "old rotting sign pointing to east";
  items[2] = "pilar"; 
  items[3] = "Two huge pilars on both sides of the room";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
    
}
