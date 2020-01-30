string str;
status lighted;
int fuel, maxfuel,l;
long() {
        str = short();
        str += "\nMaybe you could 'light' it if you need light, or 'extinguish' it if\n"+
               "you want to save the fuel. Lanterns last longer then torches.\n"+
               "You can also refill it with an oil bag.\n";
write(str+"");
}
query_long() { return str;      }

short() {
        string x;
        x = "An iron lantern ";
        if(lighted) { x += "(lighted)"; }
        else if(!lighted) { x += "(not lighted)"; }
        else if(!fuel) { x += "(empty)"; }
        return x;
        }

reset(arg) {
    if (arg)
        return;
    maxfuel = 4000; lighted = 0; fuel = maxfuel, l = 3;
}

query_weight() { return 150; }
query_lighted() { return lighted; }

set_fuel(f) {
        fuel = f;
        lighted = 0;
        }

init() {
    add_action("light", "light");
    add_action("extinguish", "extinguish");
}

light(str) {
    if (!str) { return 0; }
    if (this_object() != present(str)) { return 0; }
    if (lighted) {
        write("It is already lighted.\n");
        return 1;
    }
    if(!fuel) { write("It has run out of fuel, maybe you could refill it.\n"); return 1; }
    lighted = 1;
    call_out("out_of_fuel", maxfuel);
    call_out("burning", random(60)+120);
    write("You light the lantern.\n");
    say(this_player()->query_name()+" lights a lantern.\n");
    set_light(set_light(0) + 3);
    return 1;
}
burning() {
        tell_room(environment(this_player()), "The flame in lantern flickers.\n");
        call_out("burning", random(60)+120);
        return 1;
}

out_of_fuel() {
        int i;
        i = remove_call_out("burning");
        fuel = 0;
        write("The flame in lantern flickers and dies.\n");
        set_light(-l);
        return 1;
}

id(str) {
    return str == "lantern";
}

query_value() {
    return 5;
}

get() { return 1; }

extinguish(str) {
    int i,x;

    if (str && !id(str))
        return 0;
    if (!lighted)
        return 0;
    i = remove_call_out("out_of_fuel");
    x = remove_call_out("burning");

    fuel = i;
    lighted = 0;
    write("You extinguish the lantern.\n");
    say(this_player()->query_name()+" extinguish an lantern.\n");
    set_light(-l);
    return 1;
}
