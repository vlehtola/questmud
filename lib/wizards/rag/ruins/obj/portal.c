short() { return "A blood-red portal to unknown planes of existence"; }

long(str) {
    write("This portal is about 12 feet high and some 8 feet wide.\n"+
    	"It is pulsating slightly and you think you can hear the\n"+
    	"wailing of lost souls coming from the portal. There are\n"+
    	"some skulls and bones lying next to the portal. Only the\n"+
    	"bravest or the foolest heroes dare to enter the portal.\n");
    return;
}

id(str) { return str == "portal" || str == "portal123"; }

get() {
    return 0;
}

query_weight() {
  return 10000;
}