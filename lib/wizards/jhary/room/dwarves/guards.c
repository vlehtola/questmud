inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("west","/wizards/jhary/room/dwarves/dwarf12");
  short_desc = "In the office of the town-guard";
  long_desc = "Through a massive door you enter the sparsely furnished \n"+
              "guard room. At the left side you can see a huge desk \n"+
              "with several papers. In the right corner there is a huge \n"+
              "barrel with different weapons in it. Although it is not \n"+
              "forbidden to wear weapons in the town, the most inhabitants \n"+
              "don't need to carry any and gave them to the guards, to \n"+
              "deposit and keep them till they are needed. If you have a \n"+
              "matter of concern you can ask the Chief and he'll help \n"+
              "you if he is able to. A steel door with a big lock, let \n"+
              "directly inside the mountain serves as a small prison. \n"+
              "To leave this place try to go westward.\n";
}
                                        
