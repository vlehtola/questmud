inherit "room/room";
status burning;
string desc, who;
reset(arg) {
if(arg) return;
burning = 0;
set_not_out(1);
set_light(2);
	long_desc = "A large dining table full of dishes is center of the kitchen and\n"+
	             "chairs made from oak are placed around the table. A small kitchen\n"+
	             "table is backside of the room and small sink is dripping little water\n"+
	             "drips, which make funny noise when they drop in the sink. A cabinet is\n"+
	             "next to the kitchen table, which is full of cauldrons and dining equipment.\n"+
	             "The floor is full of food leftovers and misc rubbish. A large candle lamp\n"+
	             "is hanging from the ceiling and a tiny fire is burning in one of the candles.\n";

short_desc = "A kitchen";
  add_exit("east", "house2");
}
init() {
	::init();
	add_action("extinguish", "extinguish");
}
extinguish(str) {
	if(!str || str != "candle") { write("Extinguish what?\n"); return 1; }
	if(burning) { write("The candles are all extinguished.\n"); return 1; }
	write("You extinguish the candle which was still burning.\n");
	say(this_player()->query_name()+" extinguish one of the candles.\n");
	long_desc = "A large dining table full of dishes is center of the kitchen and\n"+
             "chairs made from oak are placed around the table. A small kitchen\n"+
             "table is backside of the room and a small sink is dripping little water\n"+
             "drips, which make funny noise when they drop in the sink. A cabinet is\n"+
             "next to the kitchen table, which is full of cauldrons and dining equipment.\n"+
             "The floor is full of food leftovers and misc rubbish. A large candle lamp\n"+
             "is hanging from the ceiling and the candles are all extinguished.\n";
    burning = 1;
    who = this_player()->query_name();
    return 1;
}

query_burning() { return burning; }
query_who() { return who; }
