inherit "obj/food";
string desc;
int x;

start(str,i) {
desc = str;
x = i;
set_name("can");
set_short("Can made from "+desc);
set_long("Can made from "+desc+"\n");
set_weight(5);
set_value(0);
set_strength(x*500);
}


set_id(arg) {
    return name == arg;
}

query_long() { return "Can made from "+desc+".\n"; }
