inherit "room/room";



reset(arg) {



  add_exit("south","/wizards/irmeli/bwp/room6.c"); 



  short_desc = "At the bank of a broad river";

  long_desc = "You are standing on the bank of a broad river. An old and decayed tree from\n"+

                "the another side of the river has falled across the river. The top of the\n"+

                "tree reaches all way to this side of the river. It would be possible to\n"+

                "get to the other side of the river, using the tree as a bridge. The\n"+

                "meandering river bends to the west.\n";



  property = allocate(1);

  property[0] = "no_summon";



  items = allocate(2);

  items[0] = "tree";

  items[1] = "An old and decayed tree has falled over across the river. The top of the tree reaches on this side of the river from the other side. Crossing the river would be easy using this tree"; 



}

  

init() {

  ::init(); 

  add_action("cross", "cross");

}



cross(str) {

  if(str == "river") {

    write("You step on the tree and use it as a bridge to the another side.\n"); 

    this_player()->set_quest("Cross the river in the forest");

    move_object(this_player(),"/wizards/irmeli/bwp/room10.c");
   
    this_player()->look();
    
    return 1; 

}

    write("Something wrong?\n");

    return 1;

}



