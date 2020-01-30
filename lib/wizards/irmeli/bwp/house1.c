inherit "room/room";  

reset(arg) {
  add_exit("out","/wizards/irmeli/bwp/room19.c"); 
  set_not_out(1);  

  short_desc = "In a small red hunting lodge";
  long_desc = "Everything, what a hunter needs for living, is in this simple room. Two regular\n"+
                "beds, one small table, fireplace and couple chairs. This hunting lodge consist\n"+
                "of this room only. The hunting lodge is good shelter for rainy days, after\n"+
                "dark and tired-out hunter. There is a filled head of moose on the wall.\n";


  property = allocate(1);
  property[0] = "no_summon";

  items = allocate(2);
  items[0] = "head";
  items[1] = "A filled head of moose. It must have been a big moose to have a head like that"; 
}
