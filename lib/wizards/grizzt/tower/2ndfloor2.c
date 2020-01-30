inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("west","/wizards/grizzt/tower/2ndfloor1");

  set_not_out(1);
  
  short_desc = "An empty guestroom";
  long_desc = "This small and simple room must be for the occasional guests \n"+
              "of this tower. There are no expensive decorations or beautiful \n"+
              "carpets in this small room. Only a table, a bed and a chair act \n"+
              "as furniture. For some reason there are no windows in this room, \n"+
              "just a burnt candle, which has given its light many years ago. \n";


  items = allocate(8);
  items[0] = "table";
  items[1] = "There is a burnt candle on the table, otherwise it's covered with dust.";
  items[2] = "bed";
  items[3] = "The doesn't seem to be suitable for sleeping.";
  items[4] = "chair";
  items[5] = "The does not seem to be able to carry your weight.";
  items[6] = "candle";
  items[7] = "The candle has burnt into a small stub, it will not give any more light.";
  
   

}