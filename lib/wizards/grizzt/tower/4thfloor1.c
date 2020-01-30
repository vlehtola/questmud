inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("down","/wizards/grizzt/tower/3rdfloor1");
  add_exit("west","/wizards/grizzt/tower/4thfloor2");
  
  set_not_out(1);
  
  short_desc = "A bit bigger landing";
  long_desc = "\n";


  items = allocate(6);
  items[0] = "walls";
  items[1] = "The walls are made of huge boulders without any plaster.";
  items[2] = "stair";
  items[3] = "The stairs seem to be made without any use of tools.";
  items[4] = "torches";
  items[5] = "The torches do not give any more light for you.";
        
  

}
init() 
{
 ::init();
 add_action("light_torch", "light");
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

wipe_floor(str) 
{
 if(str == "floor") 
   {
    write ("You see a letter 'R' and the dust settles.\n");
    return 1;
   }
 write("Wipe what?\n");
 return 1;
}