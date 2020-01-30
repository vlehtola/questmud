inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/map");
   return 1;
}
object monster,acka,karry;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/init");
    move_object(monster, this_object());
  }
    
  if(!acka) {
    acka = clone_object("/wizards/walla/jericho/mobs/inamra");
    move_object(acka, this_object());
  }

  if(!karry) {
     karry = clone_object("/wizards/walla/jericho/stuph/cart2");
     move_object(karry, this_object());
  }
   
 
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/bazaar/keskioikea");
  add_exit("west","wizards/walla/jericho/rooms/bazaar/keskivasen");
  short_desc = "In the bazaar";
  long_desc =
"You are standing in the middle of the bazaar. This is the place to\n" +
"come if you need to buy clothes, since the cart of Init Sitab is\n" +
"well known to contain the best woven fabrics in the nearby realms.\n" +
"The people that come here, know to demand only the best of fabrics, \n" +
"and that is what Init sells.\n";
 
   
  
}


