#define STACK_D "/daemons/string_stack_d"
#define MAX_WEIGHT 100
int local_weight;

short() {
  return "An enourmous silk quiver";
}
query_quiver() { return 1; }

long() {
  object ob,tp;
  int i;
  string lista, *list;
  tp = this_player();
  if(!tp->check_condis()) { return 1; }
  write(short()+".\n");
  write("You can put arrows or bolts inside this quiver.\n");
  write("It looks like it can handle around 100 different arrows or bolts.\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
          list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
  return 1;
}

id(str) { return str == "quiver"; }


reset(arg) {
  if(arg) return;
}

get() {
        return 1;
}
query_value() { return 10000; }

add_weight(w) {
    if (w + local_weight > MAX_WEIGHT) return 0;
    local_weight += w;
    return 1;
}

can_put_and_get(object ob) {  return 1;  }
quiver_container() { return 1; }

query_weight() { return local_weight; }