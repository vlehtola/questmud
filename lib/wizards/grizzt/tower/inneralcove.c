inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("south","/wizards/grizzt/tower/entrance");
  add_exit("up","/wizards/grizzt/tower/2ndfloor1");

  set_not_out(1);
  
  short_desc = "Beginning of a stairway";
  long_desc = "This narrow room seems to be the bottom of a long stairway which is \n"+
  	      "leading upwards into this tower. Each stair seems to be made of \n"+
  	      "natural stone without any sign of cutting. Here too, the dust has \n"+
  	      "settled to cover all horizontal surfaces. There are a few torches on \n"+
  	      "on the wall. The torches look like they have given all their light \n"+
  	      "away years ago. The stairway rises steeply and there is no railing \n"+
  	      "for support.\n";


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
 add_action("wipe_floor", "wipe");
}

wipe_floor(str) 
{
 if(str == "floor") 
   {
    write ("You see a letter 'F' and the dust settles.\n");
    return 1;
   }
 write("Wipe what?\n");
 return 1;
}