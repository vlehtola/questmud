inherit "room/room";

reset(arg) {
if(arg) return;
 
  add_exit("north", "tunnele.c");
  add_exit("south", "citye.c");
 
  short_desc = "A tunnel";
  long_desc = "A tunnel leading downwards. There are many torhces hanging\n"+
              "on the walls giving light. There is a gorgeous looking\n"+
              "statue standing on the left side of the tunnel.\n";

items = allocate(4);
  items[0] = "statue";
  items[1] = "Very beautiful statue made of rock.\n"+
            "There is a sign on the pedestal.\n";
  items[2] = "sign";
  items[3] = "Our beloved king Thordim Goodsteel.\n";

}
