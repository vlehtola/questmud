#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET set_not_out(1);

init() {
    ::init();
    add_action("sell", "sell");
    add_action("value", "value");
    add_action("buy", "buy");
    add_action("west", "west");
    add_action("list", "list");
}

ONE_EXIT("world/city/mainstr2", "north",
	 "The magic shop",
"You are in a shop. You can buy or sell magic items here.\n" +
"Commands are: 'buy item', 'sell item', 'sell all', 'list' and 'value item'.\n" +
"There is an opening to the west, and some shimmering\n" +
"blue light in the doorway.\n", 3)


sell(item) {
    object ob;

    if (!item)
	return 0;
    if (item == "all") {
	object next;
	ob = first_inventory(this_player());
	while(ob) {
	    next = next_inventory(ob);
	    if (!ob->drop() && !ob->keep() && ob->query_value() && ob->query_wc()) {
		write(ob->short() + ":\t");
		do_sell(ob);
	    }
	    ob = next;
	}
	write("Ok.\n");
	return 1;
    }
    ob = present(item, this_player());
    if (!ob)
	ob = present(item, this_object());
    if (!ob) {
	write("No such item ("); write(item); write(") here.\n");
	return 1;
    }
    do_sell(ob);
    return 1;
}

do_sell(ob) {
    int value, do_destroy;
    value = ob->query_value() / 5;
    if (!value) {
	write(ob->short() + " has no value.\n");
	return 1;
    }
    if (ob->short() != "An old and yellowed scroll") {
	write(ob->short() + " is not a scroll.\n");
	return 1;
    }
    if (environment(ob) == this_player()) {
        int weight;
	if (call_other(ob, "drop", 0) || ob->keep()) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(ob, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
    if (value > 2000)
	do_destroy = 1;
    if (value > 1000) {
	write("The shop is low on money...\n");
	value = 1000;
    }
    write("You get "); write(value); write(" bronze coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value,3);
    if (do_destroy) {
	write("The valuable item is hidden away.\n");
	destruct(ob);
	return 1;
    }
    call_other("world/city/magic_store", "store", ob);
    return 1;
}

value(item) {
    int value;
    string name_of_item;

    if (!item)
	return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
	if (call_other("world/city/magic_store", "value", item))
	    return 1;
	write("No such item ("); write(item); write(") here\n");
	write("or in the store.\n");
	return 1;
    }
    value = call_other(name_of_item, "query_value", 0) / 10;
    if (!value) {
	write(item); write(" has no value.\n");
	return 1;
    }
    write("You would get "); write(value); write(" bronze coins.\n");
    return 1;
}

buy(item) {
    if (!item)
	return 0;
    call_other("world/city/magic_store", "buy", item);
    return 1;
}

west() {
    if (!call_other(this_player(), "query_wiz", 0)) {
	write("A strong magic force stops you.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(),"move_player","west#world/city/magic_store");
    return 1;
}

list(obj) {
    call_other("world/city/magic_store", "inventory", obj);
    return 1;
}

find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}

query_drop_castle() {
    return 1;
}
