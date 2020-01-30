inherit "room/room";
#define SAVE_FILE "/data/auctioneer"
#define MAX_PRIZE 500000

string *list;
string *item_short;
string *price;
string *bidder;
string *last_bid;
string *who_bid;
string *auction_time;
string *item_status;
string *file_ob;
string *how_long;

// auctions -> itemnumber, itemshort, timeleft, itemprice, bidder, whoauct, filenameob
reset(arg) {
  short_desc = "Auctioneer";
  long_desc = "\n"+
              "list (Shows list of the items currently available)\n"+
              "auction <item> for <price> (Puts a item for auction with the price).\n"+
              "bid <price> for <item number> (Bids price for the item)\n"+
              "reclaim <item> (Reclaims back the item that has not been sold)\n"+
              "buy <item> (Buy's the item from the auctioneer if it has bee sold to you>\n"+
              "info <item> (Shows information of the item)\n";
  set_property("no_summon","no_fight");
  add_exit("north", "/world/city/ice4");
  list = ({ });
  item_short = ({ });
  price = ({ });
  bidder = ({ });
  last_bid = ({ });
  auction_time = ({ });
  item_status = ({ });
  who_bid = ({ });
  file_ob = ({ });
  how_long = ({ });
 if(!restore_object(SAVE_FILE)) {
         save_object(SAVE_FILE);
 }
save_object(SAVE_FILE);
}

init() {
::init();
add_action("list", "list");
add_action("auction", "auction");
add_action("bid", "bid");
add_action("buy", "buy");
add_action("reclaim", "reclaim");
add_action("info", "info");
}
info(str) {
        int mika;
        int i;
        if(!str) { write("info <item numbe>\n"); return 1; }
        if(sscanf(str, "%d", mika) != 1) { write("info <item number>\n"); return 1; }
        i = sizeof(list);
        if(mika >= i) { write("No such item.\n"); return 1; }
        write("Displaying information of "+item_short[mika]+"...\n");
        write("It was placed on auction by "+capitalize(list[mika])+".\n");
        write("Starting price was set at "+price[mika]+" bronze.\n");
        if(who_bid[mika] == "nobody") {
        write("Nobody has bidded that item.\n");
} else if(who_bid[mika] != "nobody") {
        write("Last bid by "+who_bid[mika]+" of "+last_bid[mika]+" bronze.\n");

}
return 1;
}

reclaim(str) {
int mika;
int i;
object ob;
if(!str) { write("Reclaim <item number>\n"); return 1; }
if(sscanf(str, "%d", mika) != 1) { write("Reclaim <item number>\n"); return 1; }
i = sizeof(list);
if(mika >= i) { write("No such item.\n"); return 1; }
if(item_status[mika] != "not-sold") { write("You cant reclaim that yeat.\n"); return 1; }
if(list[mika] != this_player()->query_real_name()) { write("You diden't auction that item.\n"); return 1; }
write("You reclaim your "+item_short[mika]+" back.\n");
ob = clone_object(file_ob[mika]);
move_object(ob, this_player());
this_player()->fix_weight();
 log_file("AUCTIONEER", ctime(time())+" "+this_player()->query_name()+" reclaimed "+file_ob+".\n");
    list[mika] = 0;
    item_short[mika] = 0;
    price[mika] = 0;
    bidder[mika] = 0;
    last_bid[mika] = 0;
    auction_time[mika] = 0;
    item_status[mika] = 0;
    who_bid[mika] = 0;
    file_ob[mika] = 0;
    how_long[mika] = 0;
save_object(SAVE_FILE);
return 1;
}
query_time_left(i) { return auction_time[i] - time(); }
query_files() { return file_ob; }
query_how_long(i) { return how_long[i] - time(); }

buy(str) {
        int mika;
        int i;
        object ob;
        if(!str) { write("Buy <item number>\n"); return 1; }
        if(sscanf(str, "%d", mika) != 1) { write("Buy <item number>.\n"); return 1; }
        i = sizeof(list);
        if(mika >= i) { write("No such item.\n"); return 1; }
        if(item_status[mika] != "sold") { write(item_short[mika]+" is not sold yeat.\n"); return 1; }
        if(this_player()->query_money(3) < last_bid[mika]) { write("You don't have enough money to buy that.\n"); return 1; }
        ob = clone_object(file_ob[mika]);
        move_object(ob, this_player());
        write("You give "+last_bid[mika]+" bronze coins to auctioneer and receive "+item_short[mika]+"\n");
        if(find_player(list[mika])) { tell_object(find_player(list[mika]), "Auctioneer tells you 'I transferred "+last_bid[mika]+" to your account.\n"); }
        this_player()->reduce_money(last_bid[mika], 3);
        "/room/bank"->add_bank_money(last_bid[mika], 3, list[mika]);
        log_file("AUCTIONEER", ctime(time())+" "+this_player()->query_name()+" bought "+file_ob+" with money of "+last_bid[mika]+".\n");
    list[mika] = 0;
    item_short[mika] = 0;
    price[mika] = 0;
    bidder[mika] = 0;
    last_bid[mika] = 0;
    auction_time[mika] = 0;
    item_status[mika] = 0;
    who_bid[mika] = 0;
    file_ob[mika] = 0;
    how_long[mika] = 0;
    return 1;
}


list() {
string str;
string lappa;
int i;
str =sprintf("+---------------------------------------------------------------------------+\n");
str+=sprintf("| Nr  | Time-left        |Item                                 | bid        |\n");
str+=sprintf("+-----+------------------+-------------------------------------+------------+\n");
for(i=0;i<sizeof(list);i++) {
if(query_time_left(i) > 0 && list[i] == this_player()->query_real_name()) {
str+=sprintf("| *%-3d| %-16s | %-35s | %-10d |\n", i, time_left(auction_time[i] - time()), item_short[i], last_bid[i]);
} else if(query_time_left(i) > 0 && who_bid[i] == this_player()->query_real_name()) {
str+=sprintf("| %-3d | %-16s | %-35s | *%-10d|\n", i, time_left(auction_time[i] - time()), item_short[i], last_bid[i]);
} else if(query_time_left(i) > 0) {
str+=sprintf("| %-3d | %-16s | %-35s | %-10d |\n", i, time_left(auction_time[i] - time()), item_short[i], last_bid[i]);
} else if(query_time_left(i) < 0 && who_bid[i] != "nobody") {
str+=sprintf("| %-3d | %-16s | %-35s | %-10d |\n", i, "sold", item_short[i], last_bid[i]);
item_status[i] = "sold";
} else if(query_time_left(i) < 0 && who_bid[i]) {
str+=sprintf("| %-3d | %-16s | %-35s | %-10d |\n", i, "not-sold", item_short[i], last_bid[i]);
item_status[i] = "not-sold";
} else if(query_how_long(i) < 0) {
            list[i] = 0;
            item_short[i] = 0;
            price[i] = 0;
            bidder[i] = 0;
            last_bid[i] = 0;
            auction_time[i] = 0;
            item_status[i] = 0;
            who_bid[i] = 0;
            file_ob[i] = 0;
        how_long[i] = 0;
}
}
str+=sprintf("+---------------------------------------------------------------------------+\n");
write(str);
save_object(SAVE_FILE);
return 1;
}

bid(str) {
int i;
int need_bid;
int a;
string num, price;
i = sizeof(list);
if(!str) { write("Usage: bid <price> for <num>\n"); return 1; }
if(sscanf(str, "%d for %d", price, num) != 2) { write("Usage: bid <price> for <num>\n"); return 1; }
if(num >= i) { write("You can't bid that.\n"); return 1; }
if(item_status[num] != "bid") { write("You can't no longer bid that item.\n"); return 1; }
need_bid = last_bid[num]/10*2;
a = last_bid[num]+need_bid;
if(list[num] == this_player()->query_real_name()) { write("You can't bid equipment auctioned by yourself.\n"); return 1; }
if(price < a) { write("You need bid atleast "+a+".\n"); return 1; }
if(price > MAX_PRIZE) { write("Max price is set currently at the "+MAX_PRIZE+" bronze.\n"); return 1; }
if(this_player()->query_money(3) < price) { write("You don't have enough bronze coins.\n"); return 1; }
write("You bid "+price+" for the "+num+".\n");
last_bid[num] = price;
who_bid[num] = this_player()->query_real_name();
save_object(SAVE_FILE);
return 1;
}
query_list() { return list; }
reset_all() { if(this_player()->query_wiz() < 3) return 0;
  list = ({ });
  item_short = ({ });
  price = ({ });
  bidder = ({ });
  last_bid = ({ });
  auction_time = ({ });
  item_status = ({ });
  who_bid = ({ });
  file_ob = ({ });
  how_long = ({ });
  save_object(SAVE_FILE);
  write("Reseted.\n");
}
string time_left(int p) {
  int i;
  string piu;

  piu = "";
  i = p;
  if(i/86400) {
    piu += (i/86400) +"d ";
    i = i - (i/86400)*86400;
  }
  if(i/3600) {
    piu += (i/3600) +"h ";
    i = i  - (i/3600)*3600;
  }
  if(i/60) {
    piu += (i/60) +"m ";
    i = i - (i/60)*60;
  }
  piu += i +"s";
  return piu;
}

auction(str) {
 object ob;
 string item;
 string money;
 string filen;
 string shortti;
 string tmp;
 int i;
 int lap;
 if(!str) { write("Usage: auction <item> for <price>\n"); return 1; }
 if(sscanf(str, "%s for %d", item, money) != 2) { write("Usage: auction <item> for <price>\n"); return 1; }
 ob = present(item, this_player());
 if(!ob) { write("You don't have such thing to auction.\n"); return 1; }
 if(!ob->query_value()) { write("You can't auction that.\n"); return 1; }
 if(!ob->query_weapon() && !ob->query_armour()) { write("You can't auction that.\n"); return 1; }
 if(ob->query_no_save()) { write("You can't auction that.\n"); return 1; }
 if(this_player()->query_money(3) < 500) { write("You need to pay 500 bronze coins for auction.\n"); return 1; }
 if(money > MAX_PRIZE) { write("Max price is set currently at the "+MAX_PRIZE+" bronze.\n"); return 1; }
 if(sizeof(list)>100) { write("No more auctions accepted.\n"); return 1; }
 write("You pay the 500 bronze and put the "+ob->short()+" in auction.\n");
 shortti = ob->short();
 if(sscanf(shortti, "%s<%s", shortti, tmp))
 if(strlen(shortti)>32)shortti=shortti[0..32];

 if(sscanf(file_name(ob), "%s#%d", filen, lap))
 this_player()->reduce_money(500, 3);
 list += ({ this_player()->query_real_name(), });
 item_short += ({ shortti, });
 price += ({ money, });
 bidder += ({ "no-one", });
 last_bid += ({ money, });
 auction_time += ({ 216000 + time(), });
 how_long += ({ 432000 + time(), });
 item_status += ({ "bid", });
 who_bid += ({ "nobody", });
 file_ob += ({ filen, });
 "/daemons/channel_d"->send_to_channel("sales", "Auctioneer: "+ob->short()+" for "+money+" bronze coins. (Automated)\n");
 log_file("AUCTIONEER", ctime(time())+" "+this_player()->query_name()+" place "+ob->short()+" on auction with price of "+money+".\n");
 destruct(ob);
 save_object(SAVE_FILE);
 return 1;
}
