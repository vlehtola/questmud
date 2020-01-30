#define DEMONLIST "/daemons/demonxplist"

init() {
  add_action("pala","look");
  add_action("pala","l");
  add_action("update","update");
}

update() {
DEMONLIST->update_plaque(this_player());
write("Plaque updated.\n");
return 1;
}

pala(str) {
  string nimi;
  int i;
  if(!str) { return; }
  if(lower_case(str) == "at siki on plaque") {
    write("You should worship and praise siki for doing this board and coding warlocks!\n");
    return 1;
  }
  if (str == "at list") {
	long(0,1);
	return 1;
  }
  if(sscanf(str, "at %s on plaque", nimi) == 1) {
    while(i < DEMONLIST->query_size()) {
      if(DEMONLIST->query_list(i) && capitalize(DEMONLIST->query_list(i)) == capitalize(nimi)) {
        long(i);
        return 1;
      }
      i += 1;
    }
    write(capitalize(nimi) + " is not on the plaque.\n");
    return 1;
  }
}

long(num, list) {
  int i, ii;
  string tmp_exp, str, exp_str, st;
  object pager;
  ii = 11;
  if (intp(num) && num > 5) { i = num - 5; ii = num + 5; }
  if (list) { i = 0; ii = DEMONLIST->query_plaque_size(); }
  st= sprintf("+-----+----------------------+------------+-----------------+\n");
  st+=sprintf("| #   | Name                 | Level      | Demon-Xp percent|\n");
  st+=sprintf("+-----+----------------------+------------+-----------------+\n");
  while(i<DEMONLIST->query_plaque_size() && i < ii && DEMONLIST->query_list(i) !="-") {
    if(DEMONLIST->query_list(i)) {
  st+= sprintf("| %-3d | %-20s | %-10d | %-15d |\n", i, DEMONLIST->query_list(i), DEMONLIST->query_levels(i), DEMONLIST->query_demonxp(i));
    }
    i += 1;
  }
  st+=sprintf("+-----+----------------------+------------+-----------------+\n");
  if (num == "plaque" && !list) {
   st+=sprintf("You could also 'look at {someone} on plaque' and 'look at list'.\n");
   st+=sprintf("You can also 'update'.\n");
  }
  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(st);
}
query_name() { return "plaque"; }
id(str) { return str=="plaque"; }

short() { return "A bloody plaque"; }

