#define STACK_D "/daemons/string_stack_d"

status can_put_item(object ob, object container_o) {
  if(ob->drop())
	return 0;
  if(this_player()->query_keep(ob))
	return 0;
  if(!container_o->add_weight(ob->query_weight() ))
	return 0;
  if(ob->can_put_and_get())
	return 0;
  if(ob->query_money() != container_o->query_purse())
  return 0;
  if(ob->query_arrow() != container_o->quiver_container())
  return 0;
  if(ob->herbs() != container_o->herb_container())
  return 0;
  return 1;
}

cmd_put(string str) {
    int i;
    int weight;
    string item, container, *kamat, lista;
    object *item_o, container_o;
    weight = 0;
    if (!this_player()->check_condis()) { return 1; }
    if (!str || sscanf(str, "%s in %s", item, container) != 2) {
        write("Put what in where?\n");
        return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
        container_o = present(container, environment(this_player()));
    if (!container_o) {
        write("There are no " + container + "s here!\n");
        return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0)) {
        write("You can't do that.\n");
        return 1;
    }
    item_o =  call_other("/daemons/filter", "EQ_FILTER", item, this_player());

    if(item_o) item_o = filter_array(item_o, "can_put_item", this_object(), container_o);

    if (!item_o) {
        write("Nothing put.\n");
        return 1;
    }

    kamat = allocate(sizeof(item_o));
    for(i=0; i < sizeof(item_o); i++) {
	kamat[i] = item_o[i]->short();
    move_object(item_o[i], container_o);
    weight += item_o[i]->query_weight();
    }
    lista = STACK_D->stack_item_list(kamat);

    if (!lista) {
        write("Nothing put.\n");
        return 1;
    }
    write("You put "+lista+" in "+container+".\n");
    tell_room(environment(this_player()), this_player()->query_name()+ " puts "+lista+" in "+container+".\n", ({ this_player(), }) );
    this_player()->fix_weight();
    if(container_o->automatic_weight()) {
	container_o->calc_weight();
}
    return 1;
}
