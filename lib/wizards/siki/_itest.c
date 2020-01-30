#define STACK_D "/daemons/string_stack_d"

status not_in_use(object ob) {
  if(ob->query_wielded() || ob->query_worn())
	return 0;
  return 1;
}

cmd_itest(str) {
    int i, wei;
    object *ob, tp;
    string lista, *list;
    string lista2, *list2;

    tp = this_player();
    if (!tp->check_condis()) { return 1; }
    if (str && find_player(str) && tp->query_wiz()) {
        tp = find_player(str);
    }

    wei = tp->query_local_weight() * 100;
    write("You are using " + (wei/tp->query_max_weight()) + " % of your carrying capacity.\n");

    ob = filter_array(all_inventory(tp), "not_in_use");
    list = allocate(sizeof(ob));
    list2 = allocate(sizeof(ob));
    for(i=0; i<sizeof(ob); i++) {
	if(!this_player()->query_keep(ob[i])) {
    list[i] = ob[i]->short();
    } else if(this_player()->query_keep(ob[i])) {
	list2[i] = ob[i]->short();
}
}
    lista2 = STACK_D->stack_item_list(list2);
    lista = STACK_D->stack_item_list(list);
    if(lista)
    write(lista+"\n");
    if(lista2)
	write("\nIn keep: "+lista2+"\n");
    return 1;
}
