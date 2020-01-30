inherit "room/room"; 

object monster;

reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/ozmala/areat/area-testi/mosut/mosa2");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","/wizards/ozmala/areat/area-testi/roomit/roomi1");
  add_exit("east","/wizards/ozmala/areat/area-testi/roomit/roomi3");
  short_desc = "testing testing";
  long_desc = 
"hieno iso huone jne...\n" +
"toosi iiso.\n";

  items = allocate(4);                
  items[0] = "sign";
  items[1] = "old rotting sign pointing to west";
  items[2] = "pilar"; 
  items[3] = "Two huge pilars on both sides of the room";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
    
}
