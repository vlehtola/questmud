short() { return "A sign hanging from the inn door"; } 
 
long(str) {
    write("'Ye ole Alemouth's place'\n");
    return;
}
 
id(str) { return str == "sign"; }
 
get(str) {
    if (str == "sign") {
        write("It's securely chained to the inn.\n");
        return 0;
    }
    return 0;
}
