inherit "room/room";

reset(arg) {

  add_exit("southwest","/wizards/irmeli/bwp/lost1.c");
  add_exit("south","/wizards/irmeli/bwp/lost1.c"); 
  add_exit("north","/wizards/irmeli/bwp/lost1.c"); 
  add_exit("west","/wizards/irmeli/bwp/lost1.c"); 
  add_exit("east","/wizards/irmeli/bwp/lost1.c"); 

  short_desc = "Strange clearing in the dense forest";
  long_desc = "A strange clearing in the middle of the dense forest. In the past here was a\n"+
                "swamp, but nowadays it has drained. The ground is still soft and a bit wet,\n"+
                "almost boggy. It seems like here was some kind of battle formely. Combat\n"+
                "between good and evil.\n";    
  property = allocate(1);
  property[0] = "no_summon";
}
  

