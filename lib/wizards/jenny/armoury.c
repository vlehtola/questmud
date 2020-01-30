inherit "room/room";

reset(arg) {
  if(arg) return;
  
  add_exit("west", "/wizards/proge/lab");

  short_desc =
"Armoury";

  long_desc = 

"Very experimental armoury\n"+
"Look at plaque for more info";

}

init() {
  add_action("order", "order");
  add_action("look", "look");
  ::init();
}

look(str) {
   if (str == "plaque") {
     write("Currently available:\n"+
"--------------------------------------------\n"+
"|                                          |\n"+
"|    1.        Custom made broad sword     |\n"+
"|    2.        Custom made chainmail       |\n"+
"|                                          |\n"+
"--------------------------------------------\n"+
"'order <nmbr> <class> [str,con,dex,int.wis] [1-9] ...'\n");
   return 1;
   }
   return;
}

order(str) {
  string *attribs;
  int HINTA;
  int cost;
  int i;
  object item;
  attribs = explode(str, " ");
  for(i = 4; i < sizeof(attribs); i += 2) {
    if(to_int(attribs[i]) < 0) {
        attribs[i] = "0";
    }
    if(to_int(attribs[i]) > 9) {
        attribs[i] = "9";
    }
  }
  if (attribs[0] == "1") {
    item = clone_object("wizards/proge/test/custom_sword");
    move_object(item, this_object());
  }
  if (attribs[0] == "2") {
    item = clone_object("wizards/proge/test/custom_armour");
    move_object(item, this_object());
  }
  HINTA = 0;
  item->set_class(to_int(attribs[1]));
  HINTA = to_int(attribs[1])*2;
  for(i = 3; i < sizeof(attribs); i =+ 2) {
    HINTA += to_int(attribs[i]) + 1;
    if(sizeof(attribs) > 2) {
      item->set_stats(attribs[i], to_int(attribs[i+1]));
    }
  }
  if(item) {
    cost = HINTA * 1000;
    if(this_player()->query_money(3) < cost) {
    write("You don't have enough money. (Cost is "+cost+")\n");
    return 1;
  }
  this_player()->reduce_money(cost, 3);
  write(""+item->query_name()+" cost you "+cost+" bronze coins.\n");
  move_object(item, this_player());
  return 1;
}

