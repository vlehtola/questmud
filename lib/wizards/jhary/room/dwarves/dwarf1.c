inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf14");
  add_exit("west","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("south","/wizards/jhary/room/dwarves/dwarf9");
  add_exit("east","/wizards/jhary/room/dwarves/dwarf12");
  short_desc = "At the centre of Thala.";
  long_desc = "This is the center of the town Thalahamisar. High above your \n"+
              "head, the naked, cold stone builds the ceiling. But you can \n"+
              "imagine the height, because the several sources of light \n"+
              "don't illuminate it. The only piece of the ceiling you can \n"+
              "see is a huge stalactite hanging down right over this place. \n"+
              "Somebody has mounted a huge clock to this stalactite. All \n"+
              "around this place you can see different houses of the \n"+
              "inhabitants of the town. The four roads leaving this place \n"+
              "are all illuminated with torches, to avoid that anybody will \n"+
              "spread something. Although the shadows try to eat up the light, \n"+
              "you like this place and feel safe. In the four corners of \n"+
              "this cave you recognise several important buildings, but you are \n"+
              "only sure, that one of this is the chapel. \n"+
              "You may use the four roads to step in front of them and enter. \n"+
              "There is also huge sign right in the middle of this big place \n"+
              "attracting your eye.\n";
}
                                        
