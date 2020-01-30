object ob;
string str;

short() {
return("Buluts another debugging object"); 
}


init() { 
add_action("helb","helb");
}


long() {
write("helb = find object named sign and dest it :P\n");
}

helb() {
ob = find_object("/wizards/bulut/event/sign");
ob->self_destruct();
return 1;
}

id(str) {
return str == "object";
}

