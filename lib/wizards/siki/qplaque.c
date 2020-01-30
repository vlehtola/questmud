#define QUESTLIST "/daemons/questlist"
init() {
  add_action("pala","look");
  add_action("pala","l");
}


pala(str) {
  string nimi;
  int i;
  if(!str) { return; }
  if(lower_case(str) == "at siki on plaque") {
    write("All praise siki for doing this plaque!\n");
    return 1;
  }
  if (str == "at list") {
	long(0,1);
	return 1;
  }
  if(sscanf(str, "at %s on plaque", nimi) == 1) {
    while(i < QUESTLIST->query_size()) {
      if(QUESTLIST->query_list(i) && capitalize(QUESTLIST->query_list(i)) == capitalize(nimi)) {
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
  if (list) { i = 0; ii = QUESTLIST->query_plaque_size(); }
  st=sprintf("+-----------------------------------------------------------+\n");
  st+=sprintf("| #   | Name                 | Level      | Quest points    |\n");
  st+=sprintf("+-----+----------------------+------------+-----------------+\n");
  while(i<QUESTLIST->query_plaque_size() && i < ii && QUESTLIST->query_list(i) !="-") {
    if(QUESTLIST->query_list(i)) {
  st+= sprintf("| %-3d | %-20s | %-10d | %-15d |\n", i, capitalize(QUESTLIST->query_list(i)), QUESTLIST->query_levels(i), QUESTLIST->query_quests(i));
    }
    i += 1;
  }
  st+=sprintf("+-----------------------------------------------------------+\n");
  if (num == "plaque" && !list) {
   st+=sprintf("You could also 'look at {someone} on plaque' and 'look at list'.\n");
  }
  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(st);
}
query_name() { return "plaque"; }
id(str) { return str=="plaque"; }

short() { return "A platinum plaque"; }

