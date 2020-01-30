#define STACK_D "/daemons/string_stack_d"
int max_weight, local_weight;

void set_max_weight(int i) {
	max_weight=i;
	call_out("end_pocket", i);
}

end_pocket() {
	object ob;
	int i;
ob = all_inventory(this_object());
for(i=0;i<sizeof(ob);i++) {
	move_object(ob[i], environment(this_player()));
}
write("The void pocket disappears and everything drops to the ground.\n");
destruct(this_object());
return 1;
}

id(str) { return str == "pocket" || str == "void pocket"; }
automatic_weight() { return 1; }

add_weight(w) {
    if (w + local_weight > max_weight)
	return 0;
	calc_weight();
	return 1;
}
calc_weight() {
 int i;
 object *obs;
 local_weight = 0;
 obs = all_inventory(this_object());
 for(i=0;i<sizeof(obs);i++) {
 if(local_weight < max_weight) {
	 local_weight += obs[i]->query_weight();
} else if(local_weight > max_weight) {
  move_object(obs[i], this_player());
}
 }
}
query_weight() { return local_weight/5; }
query_no_save() { return 1; }

can_put_and_get(object ob) { return 1; }

get() { return 0; }

drop() { return 1; }

short() {
string str;
int i;
if(local_weight) {
i = (local_weight * 100) / max_weight;
}

if(i>100)i=100;
str = "Void pocket ("+i+"%)";
return str;
}

long() {
  object ob;
  int i;
  string lista, *list;
  write(short()+"\n");
  if(local_weight) write("It contains:\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
  list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
  return 1;
}