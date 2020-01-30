inherit "room/room";
object monster;

reset(arg) 
{
  if(!monster) 
  {
   monster = clone_object("/wizards/jhary/npc/cinthara");
   move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/church1"); 
  short_desc = "At the altar";
  long_desc = "You step right in front of the huge altar. The wall behind\n"+
              "it is a half circle and has seven tiny windows. In each of\n"+
              "these windows there is a big lighted candle, that\n"+
              "illuminates the altar from behind, all day and night time.\n"+
              "The combination of paintings and carvings at the altar \n"+
              "looks divine and it's difficult not to kneel down and pray,\n"+
              "as you stand here.\n";
}
                                        
