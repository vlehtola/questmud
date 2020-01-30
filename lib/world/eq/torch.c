#define THIS this_object()
#define TP this_player()
int maxfuel, fuel,weight,x;
status lighted;
string msg,rc;
int setfuelmax(int v) { return maxfuel = v; }
int setfuel(int v) { return fuel = v; }
int query_fuelmax() { return maxfuel; }
int query_fuel() { return fuel; }
int query_light_source() { return 1; }
int query_lighted() { return lighted; }
set_weight(v) { return weight = v; }
reset(arg) {
        if (arg)
        return;
        maxfuel = 1000; lighted = 0; fuel = maxfuel;
}

short() {
        if(lighted) return "A torch, burning with a flame";
        if(!fuel) return "The remains of a torch";
        return "A torch";
}
long() {
        rc = short();
        rc += ".\n";
        rc += "You can light it and extinguish it.\n";
        rc += "It is a light source.\n";
        tell_object(TP, rc+"");
        return 1;
}
query_weight() { return 100; }
query_value() { return 1; }
id(str) {
    return str == "torch";
}
get() { return 1; }

query_long() { return "A torch\nYou can light it and extinguish it.\nIt is a light source.\n"; }
set_extinguish() {
	int i;
    lighted = 0;
    i = remove_call_out("out_fuel");
    setfuel(i);
    set_light(-3);
    return 1;
}

set_lighted() {
        lighted = 1;
        call_out("out_fuel", maxfuel);
        set_light(3);
        return 1;
}

out_fuel() {
        tell_room(environment(TP), "The torch flickers and dies.\n");
        setfuel(0);
        lighted = 0;
        set_light(-3);
        destruct(this_object());
        return 1;
}