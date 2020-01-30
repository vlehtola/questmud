// #define QUESTLIST "/daemons/questlist" *//
#define QUESTLIST "/wizards/kaappi/questlist"

init() {
  add_action("pala","look");
  add_action("pala","l");
}

pala(str) {
  string nimi;
  int i;
  if(!str) { return; }
  if(lower_case(str) == "at kaappi on plaque") {
    write("All praise kaappi for doing this plaque!\n");
    return 1;
}
 
if(str == "at list") {
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
    str = "|"+i+".| ";
    if(i<100) { str = "| "+i+".| "; }
    if(i<10) { str = "|  "+i+".| "; }
     if(strlen(QUESTLIST->query_list(i)) < 9) {
      str += capitalize(QUESTLIST->query_list(i))+"\t\t"; }
    else {
      str += capitalize(QUESTLIST->query_list(i))+"\t"; }
        if(QUESTLIST->query_levels(i) < 10) {
          str += "|   -"+QUESTLIST->query_levels(i)+"- | ";
        } else if(QUESTLIST->query_levels(i) < 100) {
          str += "|  -"+QUESTLIST->query_levels(i)+"- | ";
        } else {
          str += "| -"+QUESTLIST->query_levels(i)+"- | ";
        }
        
  st+="`----------------------------------------------------'\n";

  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(st);

  if(num == "plaque" && !list) {
     write("You could also 'look at {someone} on plaque' and 'look at list'.\n");
  }
 }
}
}

query_name() { return "plaque"; }

id(str) { return str=="plaque"; }

short() { return "A golden plaque"; }
