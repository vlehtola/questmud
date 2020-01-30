inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf8");
  short_desc = "In a smithy";
  long_desc = "Through the massive oakwood door, you enter the house \n"+
              "of Gnift the weapon-smith. The shelves on the wall are \n"+
              "crowded with different kinds of armoury and weapons. In \n"+
              "the corner you see a heavy anvil. At the southern wall \n"+
              "there is a big fireplace with burning charcoals to heat \n"+
              "the iron. Some kinds of tools to forge the iron are leaned \n"+
              "on the walls. After a few seconds you are overwhelmed by the \n"+
              "mixedsmell of oil, burning fire and weapons-grease. You won't \n"+
              "stay here very long, so you concentrate on the counter. \n"+
              "Besides the small counter you recognize a sign which is \n"+
              "fixed to the wall.\n";
}
                                        
