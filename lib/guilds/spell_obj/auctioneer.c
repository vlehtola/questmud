inherit "room/room";
#define SAVE_FILE "/data/auctioneer"
#define AUCTION_PRIZE 1

string *list;

// auctions -> itemnumber, itemshort, timeleft, itemprice, bidder, whoauct, filenameob
reset(arg) {
  short_desc = "You shouldn't be here.";
  long_desc = "Auctioneer.\n"+
              "list | shows all items that are for sale.\n"+
              "auction <item> for <price>.\n"+
              "bid <price> for <item number>\n"+
              "claim <item>.\n"+
              "collect\n"+
              "identify <item number>\n";
  set_property("no_summon","no_fight");
 if(!restore_object(SAVE_FILE)) {
	 save_object(SAVE_FILE);
 }
list = ({ });
save_object(SAVE_FILE);
}

init() {
::init();
add_action("list", "list");
add_action("auction", "auction");
add_action("bid", "bid");
add_action("claim", "claim");
add_action("collect", "collect");
}
#define
list() {
string str;
string lappa;
int i;
str =sprintf("+------------------------------------------------------------------------+\n");
str+=sprintf("| Nr | Time-left   |Item                                 | bid           |\n");
str+=sprintf("+----+-------------+-------------------------------------+---------------+\n");
for(i=0;i<sizeof(list);i++) {
str+=sprintf("| %2d | %2d | %-15s | %-10d |\n", i, list[i], list[i], list[i]);
}
str+=sprintf("+------------------------------------------------------------------------+\n");
write(str);
return 1;
}

auction(str) {
 object ob;
 string item;
 string money;
 int i;
 if(!list)list =({ });
 if(!str) { write("Usage: auction <item> for <price>\n"); return 1; }
 if(sscanf(str, "%s for %d", item, money) != 2) { write("Usage: auction <item> for <price>\n"); return 1; }
 ob = present(item, this_player());
 if(!ob) { write("You don't have such thing to auction.\n"); return 1; }
 if(!ob->query_value()) { write("You can't auction that.\n"); return 1; }
 if(this_player()->query_money(3) < AUCTION_PRIZE) { write("You need to pay 1 bronze coins for auction.\n"); return 1; }
 if(money > 500000) { write("Max price is set currently at the 500000 bronze.\n"); return 1; }
 if(sizeof(list)>MAX_ITEMS) { write("No more auctions accepted.\n"); return 1; }
 write("You pay the 500 bronze and put the "+ob->short()+" in auction.\n");
 this_player()->add_money(-AUCTION_PRIZE);
 list += ({ this_player()->query_name(), time(), ob->short(), money, money, "no-one", file_name(ob), });
 save_object(SAVE_FILE);
 return 1;
}
