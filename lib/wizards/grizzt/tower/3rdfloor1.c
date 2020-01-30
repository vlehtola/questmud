inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("down","/wizards/grizzt/tower/2ndfloor1");
  add_exit("up","/wizards/grizzt/tower/4thfloor1");


  set_not_out(1);
  
  short_desc = "Narrow staircase";
  long_desc = "The staircase continues to rise up into the tower. There is a \n"+
              "slight narrowing here, but still it does not disturb the climbing. \n"+
              "The eastern part of the round walls seems to be made of bricks,  \n"+
              "as if to block something. A few torches are hanging from the rings \n"+
              "attached to the walls, except the eastern wall. \n";


  items = allocate(4);
  items[0] = "wall";
  items[1] = "The bricks on eastern wall make the stairwell narrower and seem to be blocking something.";
  items[2] = "bricks";
  items[3] = "The bricks seem to be eroded by time, perhaps you could somehow dig a hole and peek inside.";

  
   

}
init() 
{
 ::init();
 add_action("light_torch", "light");
 add_action("dig_hole", "dig");
 add_action("wipe_floor", "wipe");
 }

light_torch(str) 
{
 if(str == "torch") 
   {
    write ("The torch crackles but does not burn.\n");
    return 1;
   }
 write("Light what?\n");
 return 1;
}

dig_hole(str) 
{
 if(str == "hole") 
   {
    write ("HIRVEEN ISO MOSA TULEE JA ANTAA TURPAAN!.\n");
    return 1;
   }
 write("Dig what?\n");
 return 1;
}

wipe_floor(str)
{
if(str == "floor")
  {
  write ("You see a letter 'E' and the dust settles.\n");
  return 1;
  }
 write("Wipe what?\n");
 return 1;
}