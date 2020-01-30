inherit "room/room";

reset(arg) {

      if(arg) return;
   
  add_exit("west","/wizards/siki/island/floorc1");
  add_exit("south","/wizards/siki/island/floorc6");


  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into west and south. The\n"+
              "marks on the cold stone walls are quite new. The walls \n"+
              "are secured with large wooden bars.\n";

         



  set_not_out(1);
 

  items = allocate(6);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "bar";
  items[3] = "Large wooden bar used to secure the walls of the tunnel";
  items[4] = "bars";
  items[5] = "Large wooden bars used to secure the walls of the tunnel";


}
