#define MONEY "/obj/new_money"

short() {
  return "The currency value displayer";
}

long() {
  int type,value;
  type = 1;
  write("The current values are:\n");
  while(type < 7) {
    value = call_other(MONEY, "query_real_value",type,3,1000);
    write("1000 bronze coins is equal to "+value+" "+call_other(MONEY, "query_type_string", type)+
	" coins.\n");
    type += 1;
  }
}

id(str) { return str == "displayer"; }

