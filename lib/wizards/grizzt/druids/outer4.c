inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("northeast","/wizards/grizzt/druids/outer3");
  add_exit("south","/wizards/grizzt/druids/outer5");
  
  short_desc = "Outside of an ancient stone ring";
  long_desc = "Lis�� desci \n";


  items = allocate(4);
  items[0] = "gate";
  items[1] = "The gate looks like even a giant couldn't open this gate from outside";
  items[2] = "holes";
  items[3] = "The holes mark the spot, where the gate's spikes go when the gate is lowered";
  
        
  

}