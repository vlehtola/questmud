
string amount_of_fuel;
string name;
status is_lighted;
int weight;

long() {
    write(short() + "\n");
}

reset(arg) {
    if (arg)
        return;
    amount_of_fuel = 8000; name = "lantern"; is_lighted = 0; weight = 3;
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

short() {
    string str;
    str = "An iron oil lantern";
    if (amount_of_fuel == 8000)
        str = str + " (full)";
    if (is_lighted)
        str = str + " (lighted)";
    return str;
}

set_name(n) { name = n; }
set_fuel(f) { amount_of_fuel = f; }

init() {
    add_action("light", "light");
    add_action("extinguish", "extinguish");
}

light(str) {
    if (!str)
        return 0;
    if (this_object() != present(str)) { return 0; }
    if (is_lighted) {
        write("It is already lighted.\n");
        return 1;
    }
    is_lighted = 1;
    call_out("out_of_fuel", amount_of_fuel * 2);
    if (set_light(2) == 2) {
        write("You can see again.\n");
        say(call_other(this_player(), "query_name") +
            " lights a " + name + "\n");
    } else
        write("Ok.\n");
    amount_of_fuel = 0;
    return 1;
}

out_of_fuel() {
    if (set_light(-2) == 0)
        say("There is darkness as a " + name + " goes dark.\n");
    else
        say("The " + name + " goes dark.\n");
}

id(str) {
    return str == name;
}

query_value() {
    return amount_of_fuel/100;
}

get() { return 1; }


extinguish(str) {
    int i;

    if (str && !id(str))
        return 0;
    if (!is_lighted)
        return 0;
    i = remove_call_out("out_of_fuel");
    if (i == -1) {
        write("Error.\n");
        return 1;
    }
    amount_of_fuel = i/2;
    is_lighted = 0;
    if (set_light(-2) == 0) {
        write("It turns dark.\n");
        say(call_other(this_player(), "query_name") +
            " extinguishes the only light source.\n");
    } else {
        write("Ok.\n");
    }
    return 1;
}