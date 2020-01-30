inherit "room/room";

reset(arg) {

   add_exit("northeast","/wizards/siki/ent/la09");
   add_exit("northwest","/wizards/siki/ent/la04");
   add_exit("south","/wizards/siki/ent/la06");
   short_desc = "A crossing.";
   long_desc = "A small round hall. The ceiling is extremely old, it looks like\n"+
               "it could collapse any time. The tunnels divide into three different\n"+
               "directions. Each passage has a different kind of symbol above them.\n";

items = allocate(6);
items[0] = "symbol";
items[1] = "A strange red symbol above the southern passage '--<%>'";
items[2] = "symbol 2";
items[3] = "A strange purple symbol above the northeastern passage ']\/['";
items[4] = "symbol 3";
items[5] = "A strange blue symbol above the northwestern passage '%--%'";


   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}


