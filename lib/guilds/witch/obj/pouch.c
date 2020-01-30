#define STACK_D "/daemons/string_stack_d"

short() {
  return "Witch pouch";
}

long() {
  object ob,tp;
  int i;
  string lista, *list;
  tp = this_player();
  if(!tp->check_condis()) { return 1; }

  write(short()+".\n");
  write("It is a container.\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
          list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
  return 1;
}

id(str) { return str == "pouch"; }

herb_container() { return 1; }

reset(arg) {
  if(arg) return;
}

get() {
        return 1;
}
query_value() { return 500; }

add_weight(int i) {
	return 1;
}

can_put_and_get(object ob) {
        return 1;
}