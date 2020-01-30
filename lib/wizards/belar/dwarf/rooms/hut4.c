inherit "room/room";

reset(arg) {
add_exit("out","/wizards/belar/dwarf/rooms/nort2.c");
short_desc = "The shop of Velour";
long_desc = "This is Valour's item shop. You can buy and sell your items in here.\n"+
            "You are standing at doorway. This large hall is filled with shelfs.\n"+
	    "Every shelf is filled with items. You can sell scrolls, potions, \n"+
	    "even some amulets and misc items is lost in here.\n"+
	    "There is a sign over the entrance.\n"+
            "Use commands : list, sell <item>, buy <item>.\n";
  property = allocate(1);
  property[0] = "no_summon";
  items = allocate(2);
  items[0] = "sign";
  items[1] = "sign reads : \n."+
	     "Explanation how to sell or buy items\n"+
	     " LIST - gives you list of avaible items \n"+
	     " SELLing armour ? here is how : type <sell mail> - \n"+
	     " this sells your iron chainmail to the store. \n"+
	     " BUYing amulet ? here is how : type <buy 1> there is an amulet\n"+
	     " at stores list in place 1 - then you get your amulet if you have\n"+
	     " enough money to buy it.";
}	
