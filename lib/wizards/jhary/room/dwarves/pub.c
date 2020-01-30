inherit "room/room";
object monster;

reset(arg) 
{
  if(!monster) 
  {
   monster = clone_object("/wizards/jhary/npc/beery");
   move_object(monster, this_object());
  }
              
  if(arg) return;
  add_exit("south","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("up","/wizards/jhary/room/dwarves/inn");
  short_desc = "At Beery's";
  long_desc = "Yes, you remember the headache, of the last time you were \n"+
              "here! But this can't keep you away. You are in 'Beery's' \n"+
              "a little, but nevertheless good bar with a lot of different \n"+
              "drinks. All drinks can be ordered at the bartender. He serves \n"+
              "the drinks on the big bar, he is standing at. The light is \n"+
              "dimmed and you feel comfortable in here. It's difficult to \n"+
              "describe, but you like the tables, smelling of spilled beer \n"+
              "and the dirty straw at the floor. As you look through the room, \n"+
              "you remember, why you entered here. Probably it's a good idea \n"+
              "to wet your whistle with a drink. Above the bar you can get a \n"+
              "meal in the restaurant. Leave this place to the south.\n";              
}
                                        
