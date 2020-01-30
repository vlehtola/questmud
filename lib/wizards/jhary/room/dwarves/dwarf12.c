inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("west","/wizards/jhary/room/dwarves/dwarf1");
  add_exit("southwest","/wizards/jhary/room/dwarves/dwarf9");
  add_exit("southeast","/wizards/jhary/room/dwarves/dwarf13");
  add_exit("east","/wizards/jhary/room/dwarves/guards");
  add_exit("northeast","/wizards/jhary/room/dwarves/seamstress");
  add_exit("northwest","/wizards/jhary/room/dwarves/dwarf14");
  short_desc = "At the eastern market place";
  long_desc = "This is the eastern part of Thalahamisar's market place.\n"+
              "It wide into the centre of Thalahamisar to the west.\n"+
              "The whole place is surrounded with buildings, except to \n"+
              "the southeast. Several shops try to make you spend your \n"+
              "cash. Also two other important buildings attract your eye:\n"+
              "The guard-office, located to the east. To step onto the \n"+
              "main place simply head west.\n";
}
                                        
