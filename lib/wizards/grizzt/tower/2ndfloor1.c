inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("down","/wizards/grizzt/tower/inneralcove");
  add_exit("east","/wizards/grizzt/tower/2ndfloor2");
  add_exit("up","/wizards/grizzt/tower/3rdfloor1");

  set_not_out(1);
  
  short_desc = "A small landing";
  long_desc = "The stairway rises to s small landing. The landing seems to be \n"+
  	      "in a nice place for rest after a short climbing. The whole landing \n"+
  	      "seems to be made of a single stone. The walls are covered with \n"+
  	      "some fabric, which has mostly decayed over time. There is a rotten \n"+
  	      "broom leaning against the west wall. A few torches are hanging from \n"+
  	      "the rings attached to the wall. There is an archway towards the east, \n"+
  	      "covered by a door. \n";


  items = allocate(6);
  items[0] = "fabric";
  items[1] = "You can not picture anything from the canvas and it crumbles to dust as you touch it.";
  items[2] = "broom";
  items[3] = "You can see from the dust that the broom hasn't been used for quite some time and it is now decayed.";
  items[4] = "torches";
  items[5] = "The torches do not give any more light for you.";
        
  // lis�� t�h�n actioni "light torch" -> "the torch crackles but does not burn"
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