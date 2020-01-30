#define EXPLIST "/daemons/explist"

object ob;

init() {
  add_action("pala","look");
  add_action("pala","l");
}

pala(str) {
  string nimi;
  int i;
  if(!str) { return; }
  ob = find_object(EXPLIST);
  if (str == "at list") {
	long(0,1);
	return 1;
  }
  if(sscanf(str, "at %s on plaque", nimi) == 1) {
    while(i<ob->query_size()) {
      if(ob->query_list(i) && capitalize(ob->query_list(i)) == capitalize(nimi)) {
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
  ob = find_object(EXPLIST);
  ii = 11;
  if (intp(num) && num > 5) { i = num - 5; ii = num + 5; }
  if (list) { i = 0; ii = ob->query_plaque_size(); }
  st=",----------------------------------------------------.\n";
  st+="|  # | Name             | Level |     Total worth    |\n";
  st+="+----+------------------+-------+--------------------+\n";
  while(i<ob->query_plaque_size() && i < ii && ob->query_list(i) != "-") {
    if(ob->query_list(i)) {
	str = "|"+i+".| ";
	if(i<100) { str = "| "+i+".| "; }
	if(i<10) { str = "|  "+i+".| "; }
        if(strlen(ob->query_list(i)) < 9) {
	  str += capitalize(ob->query_list(i))+"\t\t"; }
	else {
          str += capitalize(ob->query_list(i))+"\t"; }
	if(ob->query_levels(i) < 10) {
	  str += "|   -"+ob->query_levels(i)+"- | ";
	} else if(ob->query_levels(i) < 100) {
          str += "|  -"+ob->query_levels(i)+"- | ";
	} else {
          str += "| -"+ob->query_levels(i)+"- | ";
	}
	tmp_exp = ob->query_exps(i);
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
  }
}

query_name() { return "plaque"; }

id(str) { return str=="plaque"; }

short() { return "A golden plaque"; }

