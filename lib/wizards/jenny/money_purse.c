#define STACK_D "/daemons/string_stack_d"

id(str) { return str == "purse" || str == "money purse"; }

add_weight(w) {	return 1; }

query_weight() { return 100; }

query_no_save() { return 1; }

query_value() { return 50; }

can_put_and_get(object ob) { return 1; }

get() { return 1; }

drop() { return 0; }

short() { return "A silk money purse"; }
query_long() { return "A money purse made from silk. It can be used to carry unlimited amount of money.\n"; }

query_purse() { return 1; }

long() {
  object ob;
  int i;
  string lista, *list;
  write(short()+"\n");
  write("It contains:\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
  list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
  return 1;
}