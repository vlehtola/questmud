inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("east","/wizards/jhary/room/dwarves/dwarf4");
  add_exit("south","/wizards/jhary/room/dwarves/mayor");
  add_exit("north","/wizards/jhary/room/dwarves/carpenter");
  short_desc = "At a western edge of Thalahamisar";
  long_desc = "As you follow the small lane you arrive at the western\n"+
              "wall of the cave. The road is clearly illuminated of \n"+
              "torches and you can see every obstacle on it. Only less \n"+
              "housings are build this close to the cave wall. The ones \n"+
              "you recognize look comfortable, but aren't new. The rough \n"+
              "stone blocks the way west and the only possibility is to \n"+
              "turn and head in another direction. The last buildings next \n"+
              "to the wall are the carpenter in the north and the \n"+
              "mayors-office to the south. Eastward you look onto the main \n"+
              "circle of Thalahamisar.\n";
  
}
                                        
