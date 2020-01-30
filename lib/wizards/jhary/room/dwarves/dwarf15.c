inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("south","/wizards/jhary/room/dwarves/dwarf14");
  short_desc = "In a mountain crack";
  long_desc = "The only way to enter or leave the main part of Thalahamisar\n"+
              "is this small crack. There are huge massive doors that could\n"+
              "be closed to lock out all enemies. To the south you enter\n"+
              "Thalahamisar, and northward you are outside of this safe\n"+
              "town.\n";
}
                                        
