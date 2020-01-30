inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("southwest","/wizards/jhary/room/dwarves/dwarf7");
  add_exit("north","/wizards/jhary/room/dwarves/dwarf9");
  add_exit("east","/wizards/jhary/room/dwarves/dwarf10");
  add_exit("south","/wizards/jhary/room/dwarves/smithy");
  short_desc = "At a south lane";
  long_desc = "One building to the south attracts you eye. It has a \n"+
              "huge sign with an anvil fixed above the door. This must \n"+
              "be the smithy of Thalahamisar. The surrounding buildings \n"+
              "are housings of the inhabitants. West of where you are \n"+
              "standing you can look onto the church. This high edifice \n"+
              "is the centre of the main circle. The curch is overgrown \n"+
              "with moss and softly illuminated. The main circle goes to \n"+
              "the north in the centre of Thalahamisar and southwest round \n"+
              "the church. Other possibilities are to walk south into the \n"+
              "smithy or east to other shops.\n";
}
                                        
