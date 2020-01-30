inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("south","/wizards/jhary/room/dwarves/church2");
  short_desc = "In a main chapel";
  long_desc = "Reverently you enter the holy chapel. Although it isn't\n"+
              "very huge, the painted ceiling spans high above your head.\n"+
              "It is hold of huge columns. Between them there are several\n"+
              "stylites. All in hear looks simple worked, but shows signs\n"+
              "of great artists. Some rows of chairs are lined up for \n"+
              "people who want to pray to heaven. This columned hall \n"+
              "continues to the south and ends near the huge altar.\n";
}
                                        
