int money,type;

reset(arg) {
  call_out("merge",3);
  if(arg) {
    if(!money) destruct(this_object());
    return;
  }
  money = 1;
  type = 1;
}

merge() {
  object ob;
  int i;
  if(!environment(this_object())) { destruct(this_object()); return; }
  ob = all_inventory(environment(this_object()));
  while(i<sizeof(ob)) {
    if(ob[i]->id("money") && ob[i] != this_object() &&
	ob[i]->query_type() == query_type()) {
	add_value(ob[i]->query_real_value(query_type()));
	destruct(ob[i]);
    }
    i += 1;
  }
}
id(str) { return str == "money" || str == "coins" || str == "coin" ||
		str == query_type_string(query_type()); }

short() {
  string tmp;
  tmp = amount() + " " + query_type_string() + " coins";
  return capitalize(tmp);
}

long() {
  write(short()+"\n");
  write("You quickly count the coins: "+query_value()+"\n");
  write("This is about "+ query_real_value(3) +" bronze coins.\n");
}

/* i = type */
/* t = (optional) toinen type */
/* sum = (optional) rahamaara */
query_real_value(int i,int t,int sum) {
  int tmp,ii;
  if (!i) return;
  tmp = money;
  if(sum) tmp = sum;
  ii = type - i;
  if(t) ii = t - i;
  if(ii > 0) {
    while(ii>0) {
      tmp = tmp * 10;
      ii-=1;
    }
  } else {
    while(ii<0) {
      tmp = tmp / 10;
      ii+=1;
    }
  }
  return tmp;
}

amount() {
  int i;
  i = money;
  if(i==1) return "one";
  if(i<5) return "few";
  if(i<20) return "several";
  if(i<60) return "many";
  if(i<200) return "a small pile of";
  if(i<600) return "a large pile of";
  if(i<1500) return "a small hill of";
  if(i<3000) return "a large hill of";
  if(i>=3000) return "a mountain of";
  destruct(this_object());
}

type_nums(str) {
  if(str == "tin") return 1;
  if(str == "copper") return 2;
  if(str == "bronze") return 3;
  if(str == "silver") return 4;
  if(str == "gold") return 5;
  if(str == "mithril") return 6;
}
  
get() {
  call_out("merge",1);
  return 1;
}

drop() {
  call_out("merge",1);
  return 0;
}

query_value() {
  return money;
}

query_type() {
  return type;
}

query_weight() {
  return money/1000;
}

set_value(i) {
  money = i;
  if(money < 1) destruct(this_object());
}

add_value(i) {
  money += i;
  if(money < 1) destruct(this_object());
}

reduce_value(i) {
  money -= i;
  if(money < 1) destruct(this_object());
}

set_type(i) {
  if(i<1||i>6) return;
  type = i;
}

query_type_string(int str) {
  if(!str) str = type;
  if(str == 1) return "tin";
  if(str == 2) return "copper";
  if(str == 3) return "bronze";
  if(str == 4) return "silver";
  if(str == 5) return "gold";
  if(str == 6) return "mithril";
  return "Illegal money type";
}

query_money() {
  return 1;
}
