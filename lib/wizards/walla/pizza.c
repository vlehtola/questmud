inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("pizza");
set_short("A warm slice of pizza");
set_long("A perfect slice, a crunchy thin crust.\n"+
         "The toppings are still steaming and the smell\n"+
 "is to die for.\n");
set_weight(1);
set_value(0);
set_strength(5000);
}


set_id(arg) {
    return name == arg;
}

init() {
        ::init();
        add_action("eatt","eat");
}

eatt(str) {
        if(present(str) != this_object()) return;
        write("Mmm, pizza!\n");
        this_player()->set_ep(this_player()->query_max_ep());
        return;
}

