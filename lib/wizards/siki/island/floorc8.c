inherit "room/room";

reset(arg) {

      if(arg) return;
   
  add_exit("north","/wizards/siki/island/floorc6");
  add_exit("west","/wizards/siki/island/floorc9");


  short_desc = "An abandoned mining tunnel";
  long_desc = "A dark mining tunnel leading into west and north. The walls\n"+
              "are extremely hard at this point, it is impossible to mine\n"+
              "here. The walls are secured with large wooden bars.\n";

         



  set_not_out(1);
 

  items = allocate(4);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";


}
