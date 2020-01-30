object ob;
string str;

short() {
return("Buluts debugging object"); 
}


init() { 
add_action("check","check");
}


long() {
write("check(ob name) = show query_shadowed\n");
}

check(str) {
ob = find_player(str);
write("returned: " + ob->query_shadowed()+"\n");
return 1;
}

id(str) {
return str == "object";
}

