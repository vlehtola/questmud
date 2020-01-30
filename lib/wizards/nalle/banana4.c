inherit "obj/weapon";

init() {
    ::init();
add_action("peel", "peel");
       }

reset(arg) {
    ::reset(arg);
    set_name("banana");
    set_short("A ripe banana");
    set_long("A banana that has not been peeled.\n");
    set_value(5);

    set_wc(21);
    set_weight(8);
    set_type(1);
    set_hit_func(1);
}

peel() {
write("You peel the banana");
move_object("wizards/nalle/peeled.c", this_player());
destruct(this_object());
return 1;
}
