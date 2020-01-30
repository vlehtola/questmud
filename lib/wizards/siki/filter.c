EQ_FILTER(string item,object from) {
  object ob, OBJ, *items, *inv, *already;
  object container_o;
  int a, b, e;
  string *comma, eq;
  string container;
  if (!item) { return; }

  inv = all_inventory(from);
  comma = explode(item, ",");
  if(sizeof(comma) <= 1) {
    comma = ({"nothing",comma[0]});
  }
  items = ({ });
  already = ({ });
  inv = all_inventory(from);
  for(a = 1; a < sizeof(comma) && comma[a]; a++) {

    if(comma[a] == "all") {
      return all_inventory(from);
    }
    if(comma[a] == "eq") {
      for(e = 0; e < sizeof(inv); e++) {
        if(inv[e] -> id(eq) && (!(member_array(inv[e], already) != -1))) {
          if(inv[e]->query_worn() || inv[e]->query_wielded()) {
            if(!living(inv[e])) {
              items += ({ inv[e] });
              already += ({ inv[e] });
            }
          }
        }
      }
    }
    if(comma[a] == "noeq") {
      for(e = 0; e < sizeof(inv); e++) {
        if(inv[e] -> id(eq) && (!(member_array(inv[e], already) != -1))) {
          if(!inv[e]->query_worn() && !inv[e]->query_wielded()) {
            if(!living(inv[e])) {
              items += ({ inv[e] });
              already += ({ inv[e] });
            }
          }
        }
      }
    }
    if(sscanf(comma[a], "all from %s", container) == 1) {
	container_o = present(container, this_player());
	if(!container_o)container_o=present(container, environment(this_player()));
	if(container_o && container_o->can_put_and_get()) {
	inv = all_inventory(container_o);
	for(e = 0; e < sizeof(inv); e++) {
	if(inv[e] -> id(eq) && (!(member_array(inv[e], already) != -1))) {
	if(!living(inv[e])) {
	items += ({ inv[e] });
	already += ({ inv[e] });
}
}
}
}
}
    if(sscanf(comma[a], "all %s", eq) == 1) {
      for(e = 0; e < sizeof(inv); e++) {
        if(inv[e] -> id(eq) && (!(member_array(inv[e], already) != -1))) {
          if(!living(inv[e])) {
            items += ({ inv[e] });
            already += ({ inv[e] });
          }
        }
      }
    }

    if(OBJ = present(comma[a], from)) {
      if(!(member_array(OBJ, already) != -1) && !living(OBJ)) {
        items += ({ OBJ });
        already += ({ OBJ });
      }
    }
  }
  if(!sizeof(items)) { return 0; }
  return items;
}
