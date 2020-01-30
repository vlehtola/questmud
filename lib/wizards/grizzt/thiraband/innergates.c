inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("north","/wizards/grizzt/thiraband/innergates");
  add_exit("south","/wizards/grizzt/thiraband/gates");

  
  short_desc = "Under a huge gate";
  long_desc = "This is the spot right under the huge gate of Thiraband.\n"+
  	      "There are many stories of this gate protecting the city \n"+
  	      "against the attacks of the barbaric nomads. There are several \n"+
  	      "holes on the road making a straight line from wall to wall \n";


  items = allocate(4);
  items[0] = "gate";
  items[1] = "The gate looks like even a giant couldn't open this gate from outside";
  items[2] = "holes";
  items[3] = "The holes mark the spot, where the gate's spikes go when the gate is lowered";
  
        
  

}