inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("south","/wizards/jhary/room/dwarves/dwarf8");
  add_exit("north","/wizards/jhary/room/dwarves/dwarf1");
  add_exit("northwest","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("northeast","/wizards/jhary/room/dwarves/dwarf12");
  short_desc = "At the southern market place";
  long_desc = "One building to the south attracts you eye. It has a huge \n"+
              "sign with an anvil fixed above the door. This must be the \n"+
              "smithy of Thalahamisar. The surrounding buildings are \n"+
              "housings of the inhabitants. West of where you are standing \n"+
              "you can look onto the church. This high edifice is the \n"+
              "centre of the main circle. The curch is overgrown with moss \n"+
              "and softly illuminated. The main circle goes to the north \n"+
              "in the centre of Thalahamisar and southwest round the church.\n"+
              "Other possibilities are to walk south into the smithy or \n"+
              "east to other shops.\n";
}
                                        
