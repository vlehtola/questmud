short() { return "A stone well"; }

long(str) {
    write("The well is made of stone. It has a wooden shed\n"+
        "to keep rain water out from the well. There is a\n"+
        "winch placed under the shed. You could use it to\n"+
        "lower something to the well to get water.\n");
    return;
}

id(str) { return str == "well"; }

get() {
    return 0;
}

query_weight() {
  return 10000;
}
