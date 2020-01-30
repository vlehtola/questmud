short() { return "The decapitated head of Mondasa"; }

long(str) {
        write("The decapitated head of Mondasa the half-god.\n"+
        "The head smells awful, maybe you should get rid\n"+
        "of it as soon as possible.\n");
        return;
}

id(str) { return str == "head"; }

get() {
    return 1;
}

query_weight() {
  return 10;
}
