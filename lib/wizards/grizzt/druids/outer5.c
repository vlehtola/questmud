inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("north","/wizards/grizzt/druids/outer4");
  add_exit("southeast","/wizards/grizzt/druids/outer6");
  
  short_desc = "Outside of an ancient stone ring";
  long_desc = "Lis�� desci \n";


  items = allocate(4);
  items[0] = "gate";
  items[1] = "The gate looks like even a giant couldn't open this gate from outside";
  items[2] = "holes";
  items[3] = "The holes mark the spot, where the gate's spikes go when the gate is lowered";
  
        
  

}