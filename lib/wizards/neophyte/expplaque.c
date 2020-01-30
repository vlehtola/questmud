#define EXPLIST "/daemons/explist"

init() {
  add_action("pala","look");
  add_action("pala","l");
  add_action("toggle_conceal", "conceal");
}

toggle_conceal() {
  if(EXPLIST->toggle_concealed(lower_case(this_player()->query_name()) ))
    write("You conceal your worth and prevent all from seeing it.\n");
  else
    write("You reveal your worth for all to see.\n");

  return 1;
}

pala(str) {
  string nimi;
  int i;
  if(!str) { return; }
  if(lower_case(str) == "at garath on plaque") { 
    write("The king would make your moral go down, so he has decieded not to be part of this.\n");
    return 1;
  }
  if (str == "at list") {
	long(0,1);
	return 1;
  }
  if(sscanf(str, "at %s on plaque", nimi) == 1) {
    while(i < EXPLIST->query_size()) {
      if(EXPLIST->query_list(i) && capitalize(EXPLIST->query_list(i)) == capitalize(nimi)) {
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
  if (list) { i = 0; ii = EXPLIST->query_plaque_size(); }
  st=",----------------------------------------------------.\n";
  st+="|  # | Name             | Level |     Total worth    |\n";
  st+="+----+------------------+-------+--------------------+\n";
  while(i<EXPLIST->query_plaque_size() && i < ii && EXPLIST->query_list(i) != "-") {
    if(EXPLIST->query_list(i)) {
	str = "|"+i+".| ";
	if(i<100) { str = "| "+i+".| "; }
	if(i<10) { str = "|  "+i+".| "; }
        if(strlen(EXPLIST->query_list(i)) < 9) {
	  str += capitalize(EXPLIST->query_list(i))+"\t\t"; }
	else {
          str += capitalize(EXPLIST->query_list(i))+"\t"; }
	if(EXPLIST->query_levels(i) < 10) {
	  str += "|   -"+EXPLIST->query_levels(i)+"- | ";
	} else if(EXPLIST->query_levels(i) < 100) {
          str += "|  -"+EXPLIST->query_levels(i)+"- | ";
	} else {
          str += "| -"+EXPLIST->query_levels(i)+"- | ";
	}
	tmp_exp = EXPLIST->query_exps(i);
	exp_str = "";
      if(tmp_exp && stringp(tmp_exp)) {
        if(strlen(tmp_exp) > 9) {
          exp_str += extract(tmp_exp,0,strlen(tmp_exp)-10)+"G ";
          tmp_exp = extract(tmp_exp,strlen(tmp_exp)-9,strlen(tmp_exp));
        }
        if(strlen(tmp_exp) > 6) {
          exp_str += extract(tmp_exp,0,strlen(tmp_exp)-7)+"M ";
          tmp_exp = extract(tmp_exp,strlen(tmp_exp)-6,strlen(tmp_exp));
        }
        if(strlen(tmp_exp) > 3) {
          exp_str += extract(tmp_exp,0,strlen(tmp_exp)-4)+"k ";
          tmp_exp = extract(tmp_exp,strlen(tmp_exp)-3,strlen(tmp_exp));
        }
      }
      if(strlen(tmp_exp) < 3) {
        exp_str += extract("0000", 1, 3-strlen(tmp_exp)) + tmp_exp;
      } else {
	exp_str += tmp_exp;
      }
      if(exp_str == "") {
	  exp_str = "0k";
      }

  // player can optionally conceal his worth
      if(EXPLIST->query_list(i) != this_player()->query_real_name() && EXPLIST->query_concealed(EXPLIST->query_list(i)) )
	exp_str = "<concealed>";


	str += extract("                            ",0,17-strlen(exp_str))+exp_str+" |";
	st += str+"\n";
    }
    i += 1;
  }
  st+="`----------------------------------------------------'\n";

  pager = clone_object("/daemons/pager");
  pager->move(this_player());
  pager->page(st);

  if (num == "plaque" && !list) {
     write("You could also 'look at {someone} on plaque' and 'look at list'.\n");
     write("It is possible for you to 'conceal' your worth.\n");
  }
}

query_name() { return "plaque"; }

id(str) { return str=="plaque"; }

short() { return "A golden plaque"; }

