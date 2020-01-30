string str;
init() {
    add_action("fill", "fill");
}

id(str) { if (str == "bag" || str == "oil bag") { return 1; } }

short() { return "A leather oil bag"; }

long() {
   str = short();
   str += "\nThe oil bag contains oil for a lantern.\n";
   str += "Maybe you could 'fill' a lantern with it.\n";
   write(str+"");
}
query_long() { return str; }

get() { return 1; }

fill(str) {
    object ob;
    if (str != "lantern") {
        write("Fill what?\n");
        return 1;
    }
    ob = present("lantern", this_player());
    if (!ob) {
        write("You have no lantern.\n");
        return 1;
    }
    if(ob->query_lighted() == 1) { write("Maybe you should extinguish it before refilling.\n"); return 1; }
    ob->set_fuel(4000);
    destruct(this_object());
    write("You fill the lantern with the oil bag.\n");
    say(this_player()->query_name()+" fills the lantern with an oil bag.\n");
    return 1;
}

query_value() { return 1; }
query_weight() { return 100; }
