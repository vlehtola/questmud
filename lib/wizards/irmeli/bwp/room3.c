inherit "room/room";  

reset(arg) {
  add_exit("northeast","/wizards/irmeli/bwp/room4.c");
  add_exit("northwest","/wizards/irmeli/bwp/room5.c");
  add_exit("south","/wizards/irmeli/bwp/room2.c"); 

  short_desc = "At the crossing of two paths in the forest";
  long_desc = "The forest is denser and it's almost impassable from some places. A small\n"+
                "curving path divides up into two parts. Other path leads to northeast up to\n"+
                "the riverside, while another path leads to northwest deeper in the dense\n"+
                "forest. There is a big, neat pile of woods, piled up between two big\n"+
                "trees.\n";

  property = allocate(1);
  property[0] = "no_summon";

  items = allocate(2);
  items[0] = "pile";
  items[1] = "A big, neat pile of woods, has been piled up between two big trees. The pile of woods is waiting for carriage. These would be good firewoods"; 
}
