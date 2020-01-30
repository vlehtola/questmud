inherit "room/room";
object monster;

reset(arg) 
{
  if(!monster) 
  {
   monster = clone_object("/wizards/jhary/npc/kilhean");
   move_object(monster, this_object());
  }
            
  if(arg) return;
  add_exit("southwest","/wizards/jhary/room/dwarves/dwarf12");
  short_desc = "At a sewers home";
  long_desc = "The seamstress took care that the room is well \n"+
              "illuminated. You haven't a problem to see clearly what \n"+
              "she exhibits on several dummies. The walls are hidden \n"+
              "behind thin length of material with artificial embroidery \n"+
              "pattern, to make this cave inside the mountains more \n"+
              "comfortable. If you want to go back to the caves, walk \n"+
              "southwest.\n";
}
                                        
