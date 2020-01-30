short() { return "Strong-looking wooden ladders"; }

long(str) {
    write("These ladders have survived the test\n"+
        "of time. Somehow the termites and mould\n"+
        "have avoided these ladders. The ladders\n"+
        "seem long enough to even climb to the\n"+
        "bell tower.\n");
    return;
}

id(str) { return str == "ladders"; }

get() {
    return 1;
}

query_weight() {
  return 1500;
}
