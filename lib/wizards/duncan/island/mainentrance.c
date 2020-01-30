inherit "room/room";
object boat;
reset(arg) {

  if(arg) return;
  if(!boat) {
	  boat = clone_object("/wizards/duncan/island/boat");
	  move_object(boat, "/wizards/duncan/island/entrance");
	  boat->move_back();
  }
  add_exit("pier", "pier");
  add_exit("north", "outmap: 84 48");
  add_exit("northwest", "outmap: 84 48");
  add_exit("northeast", "outmap: 84 48");
  add_exit("west", "outmap: 84 48");

  short_desc = "A small pier on the beach";
  long_desc = "Where the beach ends begins a small wooden pier. The pier offers shelter for\n"+
              "small boats from the storm. This must be very safe place, because the wind\n"+
              "does not blow in here. The pier is five meters long and three meters wide.\n"+
              "A huge island covered with thick mist is couple miles towards south. The\n"+
              "pier is under heavy traffic, traffic between the mainland and the island.\n"+
              "There are no waves splashing on the beach, because of the island which offers\n"+
              "shelter from the wind.\n";

}
